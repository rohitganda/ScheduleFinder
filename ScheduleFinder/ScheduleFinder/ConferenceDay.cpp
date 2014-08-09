#include <iostream>
#include <vector>

#include "ConferenceDay.h"
#include "ScheduleEntry.h"

using std::vector; 

void ConferenceDay::AddScheduleEntryToFirstHalf(const ScheduleEntry& sch)
{
  firstHalf.push_back(sch); 
}
void ConferenceDay::AddScheduleEntryToSecondHalf(const ScheduleEntry& sch)
{
  secondtHalf.push_back(sch); 
}

const vector<ScheduleEntry>& ConferenceDay::GetFirstHalf() const 
{
  return this->firstHalf;
}
const vector<ScheduleEntry>& ConferenceDay::GetSecondHalf() const
{
  return this->secondtHalf; 
}
