#include <iostream>
#include <ostream>
#include <vector>
#include <ctime>

#include "ConferenceDay.h"
#include "Schedule.h"

using std::vector; 
using std::cout; 
using std::endl;

void Schedule::AddConferenceDay(const ConferenceDay& day)
{
  wholeSchedule.push_back(day); 
}

//void Schedule::PrintScheduleWithTime()
//{
//
//  std::tm* sTime = nullptr;
//  long long some_time = 0;
//
//  time(&some_time); 
//  sTime = localtime(&some_time); 
//  cout << endl;
//  
//  cout << "sTime -> min = " << sTime->tm_min << endl;
//  cout << "sTime-> hour = " << sTime->tm_hour << endl;
//  
//  cout << endl;
//
//  cout << "================ Final schedule =====================> " << endl;
//  for (size_t i = 0; i < wholeSchedule.size(); i++) { //Number of Days
//    sTime->tm_hour = 9;
//    sTime->tm_min = 0;
//    sTime->tm_sec = 0; 
//    cout << endl;
//    cout << "============== Day - " << i + 1 << " Schedule =========" << endl << endl;
//    cout << "-------------- First Half starting at 9:00 AM ---------" << endl;
//    const vector<ScheduleEntry>& firstHalf = wholeSchedule[i].GetFirstHalf(); 
//    for (size_t j = 0; j < firstHalf.size(); j++) {
//      //mktime not normalizing, and thus removed this line, needs some research  
//      cout << sTime->tm_hour << ":" << sTime->tm_min << "AM "; 
//      cout << firstHalf[j].title << " " << firstHalf[j].duration << " min" << endl;
//      sTime->tm_min = sTime->tm_min + firstHalf[j].duration; 
//      std::mktime(sTime); 
//    }
//
//    cout << "12:00 PM Lunch" << endl;
//    sTime->tm_hour = 1;
//    sTime->tm_min = 0; 
//    std::mktime(sTime); 
//
//    cout << endl;
//    cout << "-------------- Second Half starting at 9:00 AM ---------" << endl;
//    const vector<ScheduleEntry>& secondHalf = wholeSchedule[i].GetSecondHalf(); 
//    for (size_t j = 0; j < secondHalf.size(); j++) {
//      //mktime not normalizing, and thus commented this line, needs some research
//      cout << sTime->tm_hour << ":" << sTime->tm_min << "PM ";
//      cout << secondHalf[j].title << " " << secondHalf[j].duration << " min" << endl;
//      sTime->tm_min = sTime->tm_min + secondHalf[j].duration;
//      std::mktime(sTime); 
//    }
//    cout << "5:00 PM Networking Event" << endl;
//  }  
//}

string Schedule::ToString()
{
  return ""; 
}

const std::vector<ConferenceDay>& Schedule::GetSchedule() const
{
  return wholeSchedule; 
}
