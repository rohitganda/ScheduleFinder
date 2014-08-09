#include <iostream>
#include <string>
#include "Constants.h"
#include "ScheduleExtractor.h"
#include "Utilities.h"

using std::string;

string ScheduleExtractor::ExtractScheduleTitle(const string& scheduleEntry)
{  
  auto pos = findLastOccurence(scheduleEntry, " ");
  if (pos == string::npos) return ""; //Invalid entry without space between time and title
  string str(scheduleEntry); 
  str.erase(pos, str.size()-pos);   
  return str; 
}


int ScheduleExtractor::ExtractScheduleDuration(const string& scheduleEntry)
{  
  size_t pos = 0; 
  pos = findLastOccurence(scheduleEntry, "lightning");
  if (!(pos == string::npos)) return MIN_DURATION; 
  
  pos = findLastOccurence(scheduleEntry, " ");  
  string str(scheduleEntry); 
  str = str.erase(0, pos); 
  pos = 0; 
  pos = findLastOccurence(str, "min");
  if (pos == string::npos) return INVALID_DURATION; 
  str.erase(pos, str.size() - pos);   
  return (std::stoi(str)); 
  
}