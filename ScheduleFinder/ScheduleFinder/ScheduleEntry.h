#ifndef __SCHEDULE_ENTRY__
#define __SCHEDULE_ENTRY__

#include <string>

#include "Constants.h"

using std::string; 

struct ScheduleEntry{
  string title; 
  size_t duration; 
  bool isVisited;
  bool isIncluded; 

  ScheduleEntry(string name, size_t dur) :title(name), duration(dur)
  {isVisited = false;  isIncluded = false;}

  ScheduleEntry(){
    title = ""; duration = INVALID_DURATION; 
    isVisited = false; isIncluded = false;
  }
};

#endif