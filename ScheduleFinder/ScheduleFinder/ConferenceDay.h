#ifndef __CONFERENCE_DAY_H__
#define __CONFERENCE_DAY_H__

#include <vector>
#include "ScheduleEntry.h"

class ConferenceDay{
public:
  ConferenceDay() :firstHalf(0), secondtHalf(0){}
  void AddScheduleEntryToFirstHalf(const ScheduleEntry& sch); 
  void AddScheduleEntryToSecondHalf(const ScheduleEntry& sch);
  const std::vector<ScheduleEntry>& GetFirstHalf() const; 
  const std::vector<ScheduleEntry>& GetSecondHalf() const; 

  
private:
  std::vector<ScheduleEntry> firstHalf;
  std::vector<ScheduleEntry> secondtHalf;
};

#endif 