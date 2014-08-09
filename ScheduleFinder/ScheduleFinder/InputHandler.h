#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include <string>
#include "ScheduleEntry.h"

class InputHandler {  
  public:
    virtual void CloseInputStreamReader() = 0; 
    virtual bool CreateInputStreamReader() = 0;
    virtual ScheduleEntry* CreateScheduleEntryFrom(std::string s) = 0;
    virtual std::string GetNextInputScheduleEntry() = 0;
    virtual bool IsScheduleEntryValid(std::string s) = 0;
    virtual bool OpenStream() = 0;     
    virtual ~InputHandler(){};
};

#endif