#ifndef __FILE_INPUT_HANDLER__
#define __FILE_INPUT_HANDLER__

#include <string>
#include <fstream>

#include "InputHandler.h"

class FileInputHandler : public InputHandler
{
public:
  FileInputHandler(std::string fileName);  
  virtual void CloseInputStreamReader();
  virtual bool CreateInputStreamReader();
  virtual bool OpenStream();
  virtual std::string GetNextInputScheduleEntry();
  virtual bool IsScheduleEntryValid(std::string s);
  virtual ScheduleEntry* CreateScheduleEntryFrom(std::string s);
  ~FileInputHandler(); 
private:
  std::string fileName; 
  std::ifstream* streamReader; 

};

#endif