#ifndef __SCHEDULE_APP_INTEGRATOR__
#define __SCHEDULE_APP_INTEGRATOR__

#include <string>
#include <vector>
#include <list>


class InputHandler; 
class SchedulingEngine; 
class InputFormatter; 
struct ScheduleEntry;
class Schedule;


class ScheduleAppIntegratorEngine {
public:
  ScheduleAppIntegratorEngine(std::string streamName, int streamType);  
  int Run(); 
  InputHandler* CreateInputHandler(std::string streamName, int streamType);
  ~ScheduleAppIntegratorEngine(); 

private:
  
  void GiveFinalScheduleToOutputHandler();
  bool InitAndOpenInputHandler();
  bool InitScheduleAppEngine();      
  bool InitSchedulingEngine(); 
  bool RunSchedulingEngine();
  bool InitOutputFormatter();
  void PopulateInputScheduleLines(); 
  void CloseInputHandler();
  void ValidateAndCreateScheduleItems(); 
  void CreateScheduleEntryList();

private:
  InputHandler* inputHandler; 
  SchedulingEngine* scheduleEngine;
  Schedule* finalSchedule; 
  int streamType; 
  std::string streamName; 
  std::vector<std::string> inputScheduleItems; 
  std::vector<ScheduleEntry> scheduleEntries;
  std::vector<std::string> invalidEntries; 
  std::vector<std::string> validEntries; 
  
};

#endif 