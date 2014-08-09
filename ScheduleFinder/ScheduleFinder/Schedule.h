#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__

#include <iostream>
#include <vector>
#include <string>

#include "ConferenceDay.h"

class Schedule {
public:
  Schedule() :wholeSchedule(0){}
  Schedule(int days) : wholeSchedule(days){}
  void AddConferenceDay(const ConferenceDay& day); 
  int GetActualDays() { return wholeSchedule.size(); }
  //void PrintScheduleWithTime();  
  string ToString(); 
  void SetDays(int days) { numberOfDays = days; }
  const std::vector<ConferenceDay>& GetSchedule() const; 
  
private:
  std::vector<ConferenceDay> wholeSchedule;
  int numberOfDays; 
};

#endif
