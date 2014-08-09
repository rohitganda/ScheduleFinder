#include <iostream>
#include <list>
#include <string>
#include <vector>


#include "Constants.h"
#include "InputHandler.h"
#include "FileInputHandler.h"
#include "InputValidator.h"
#include "Schedule.h"
#include "SchedulingEngine.h"
#include "ScheduleExtractor.h"
#include "ScheduleAppIntegratorEngine.h"
#include "ScheduleOutputStreamer.h"


using std::string; 
using std::vector;
using std::list; 

ScheduleAppIntegratorEngine::ScheduleAppIntegratorEngine(string streamName, 
                                                         int streamType)
{
  this->streamType = streamType; 
  this->streamName = streamName; 
  this->scheduleEngine = nullptr;

}
bool ScheduleAppIntegratorEngine::InitScheduleAppEngine()
{
  if (!InitAndOpenInputHandler()) {
    std::cout << "Failure in initializing input handler " << std::endl;
    return false; 
  }

  return true; 
}
int ScheduleAppIntegratorEngine::Run()
{
  if (!InitScheduleAppEngine()) {
    std::cout << "Could not initiliaze schedule app engine " << std::endl;
    return false; //Define error code or build exception handling later
  }
  PopulateInputScheduleLines();

#ifdef _DEBUG
  std::cout << "Following is the input I received " << std::endl;  
  for (size_t i = 0; i < inputScheduleItems.size(); i++) {
    std::cout << "Line[" << i << "] = " << inputScheduleItems[i] << std::endl;
  }
  std::cout << "====================================================" << std::endl;
  std::cout << std::endl;

#endif  
  
  ValidateAndCreateScheduleItems(); 

  CreateScheduleEntryList(); 

#ifdef _DEBUG
  std::cout << "Following is the final distilled Schedule entries " << std::endl;
  vector<ScheduleEntry>::iterator it = scheduleEntries.begin(); 
  for (; it != scheduleEntries.end(); it++) {
    std::cout << "Title = " << (*it).title << " ";
    std::cout << "Duration = " << (*it).duration << std::endl;
  }
  std::cout << "Schedule Entry Count = " << scheduleEntries.size() << std::endl;
  std::cout << "====================================================" << std::endl;
  std::cout << std::endl;
#endif  

  // At this point we are good with the Schedule Entries which can 
  // Be passed to the Schedule Engine 
  
  //Init The Schedule Engine
  if (!InitSchedulingEngine()) {
    std::cout << "Failure in initializing scheduling engine " << std::endl;
    return false; 
  }

  finalSchedule = scheduleEngine->RunAndCreateSchedule(); 

  if (finalSchedule == nullptr) {
    std::cout << "Schedule Engine did not return schedule " << std::endl;
    return false; 
  }
   
  //finalSchedule->PrintScheduleWithTime(); 

  ScheduleOutputStreamer schHandler(finalSchedule);

  schHandler.PrintSchedule();


  return true; 
}
ScheduleAppIntegratorEngine::~ScheduleAppIntegratorEngine()
{
  if (finalSchedule != nullptr) delete finalSchedule; 
  if (scheduleEngine != nullptr) delete scheduleEngine; 
  if (inputHandler != nullptr) delete inputHandler; 
  //free everything 
}


InputHandler* ScheduleAppIntegratorEngine::CreateInputHandler(string streamName, int streamType)
{
  switch (streamType) {
  case FILE_STREAM:
    return new FileInputHandler(streamName);
  default:
    return nullptr; 
  }
}

void ScheduleAppIntegratorEngine::GiveFinalScheduleToOutputHandler()
{
  return; 
}

bool ScheduleAppIntegratorEngine::InitAndOpenInputHandler()
{
  inputHandler = CreateInputHandler(streamName, streamType);
  if (inputHandler == nullptr) {
    std::cout << "Coud not create inputHandler " << std::endl;
    return false;
  }
  //Initialize the other parts accordingly 
  if (!inputHandler->CreateInputStreamReader()) {
    std::cout << "Could not create Input Stream Reader" << std::endl;
    return false;
  }

  if (!inputHandler->OpenStream()) {
    std::cout << "Could not open Input Stream Reader" << std::endl;
    return false;
  }
  return true; 
}

bool ScheduleAppIntegratorEngine::InitSchedulingEngine()
{
  scheduleEngine = new SchedulingEngine(this->scheduleEntries);
  /*Come back to this to improve after working*/
  scheduleEngine->CreateAlgorithm(COMPOSITE_ALGO);
  scheduleEngine->SetAlgorithmData();
  return true; 
}

bool ScheduleAppIntegratorEngine::RunSchedulingEngine()
{  
  return true;
}
bool ScheduleAppIntegratorEngine::InitOutputFormatter()
{
  return true;
}

void ScheduleAppIntegratorEngine::PopulateInputScheduleLines()
{
  string str = inputHandler->GetNextInputScheduleEntry();
  while (str != "") {
    inputScheduleItems.push_back(str);
    str = inputHandler->GetNextInputScheduleEntry(); 
  }
}

void ScheduleAppIntegratorEngine::CloseInputHandler()
{
  inputHandler->CloseInputStreamReader(); 
}

void ScheduleAppIntegratorEngine::ValidateAndCreateScheduleItems()
{
  InputValidator ip(inputScheduleItems); 
  ip.FindValidAndInvalidEntries(invalidEntries, validEntries); 

#ifdef _DEBUG
  std::cout << "Following are the valid entries " << std::endl;
  for (size_t i = 0; i < validEntries.size(); i++) {
    std::cout << "Line[" << i << "] = " << validEntries[i] << std::endl;
  }

  std::cout << "Following are the invalid entries " << std::endl;
  for (size_t i = 0; i < invalidEntries.size(); i++) {
    std::cout << "Line[" << i << "] = " << invalidEntries[i] <<std::endl;
  }
#endif  
}

void ScheduleAppIntegratorEngine::CreateScheduleEntryList()
{
  ScheduleExtractor structAuthor; 
  for (size_t i = 0; i < validEntries.size(); ++i) {
    string title = structAuthor.ExtractScheduleTitle(validEntries[i]); 
    if (title == "") continue; //Discard 
    int duration = structAuthor.ExtractScheduleDuration(validEntries[i]);
    if (duration == INVALID_DURATION || duration > MAX_SESSION_LENGTH) continue; //Discard
    scheduleEntries.push_back(ScheduleEntry(title, duration)); 
  }

  return;
}