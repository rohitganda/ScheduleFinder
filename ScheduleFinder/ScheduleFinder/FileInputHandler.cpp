#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#include "Utilities.h"
#include "InputHandler.h"
#include "FileInputHandler.h"


using std::string; 


bool FileInputHandler::CreateInputStreamReader()
{

  streamReader = new std::ifstream; 
  if (streamReader == nullptr) return false; 
  return true; 


}

bool FileInputHandler::OpenStream()
{
  streamReader->open(fileName.c_str(), std::ios::in); 
  return streamReader->good(); 
}

string FileInputHandler::GetNextInputScheduleEntry()
{
  string str; 
  if (!streamReader->good()) return ""; 
  if (!streamReader->eof())std::getline(*streamReader, str);

  //An intended side effect to trim leading and trailing spaces 
  return (str = ltrim(str)); 
}

bool FileInputHandler::IsScheduleEntryValid(string s)
{
  return true; 
}

ScheduleEntry* FileInputHandler::CreateScheduleEntryFrom(string s)
{
  return nullptr; 
}

void FileInputHandler::CloseInputStreamReader()
{
  if (streamReader->is_open()) {
    streamReader->close(); 
    delete streamReader; 
    streamReader = nullptr; 
  }
}

FileInputHandler::~FileInputHandler()
{
  CloseInputStreamReader(); 
}

FileInputHandler::FileInputHandler(string fileName)
{
  this->fileName = fileName;
  this->streamReader = nullptr;

}



