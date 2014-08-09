#ifndef __SCHEDULE_STRUCT_CREATOR__
#define __SCHEDULE_STRUCT_CREATOR__

#include <string>

#include "ScheduleEntry.h"

class ScheduleExtractor {
public:  
  std::string ExtractScheduleTitle(const std::string& scheduleEntry);
  int ExtractScheduleDuration(const std::string& scheduleEntry);
};

#endif