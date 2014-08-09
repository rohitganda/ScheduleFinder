#include <iostream>
#include <vector>
#include <list>

#include "Schedule.h"
#include "SchedulingEngine.h"
#include "ScheduleEntry.h"
#include "CompositeAlgo.h"

using std::vector;

void SchedulingEngine::CreateAlgorithm(int algoType)
{
  /*Add more algos if you like */
  switch (algoType)
  {
    /*Cases can be added if you expand for algorithms*/
  case COMPOSITE_ALGO:
    myAlgo = new CompositeAlgo();
  default:
    myAlgo = new CompositeAlgo(); 
  }
}
void SchedulingEngine::SetAlgorithm(SchedulingAlgo* algo)
{
  if (algo == nullptr) return; 
  if (myAlgo != nullptr) delete myAlgo; 
  this->myAlgo = algo; 
}
void SchedulingEngine::SetAlgorithmData()
{

}

Schedule* SchedulingEngine::RunAndCreateSchedule()
{ 

  Schedule* sch = new Schedule; 
  int days = CalculateRequiredDays();
  
  sch->SetDays(days);   
  std::vector<ScheduleEntry> half; 
  

  for (int i = 0; i < days; i++) {
    half.clear(); 
    myAlgo->SelectAndMoveNodesWithSum(entryList, half, MAX_FIRST_HALF_DURATION);

    ConferenceDay myDay;
    int sumCheck = 0; 
    for (size_t i = 0; i < half.size() && sumCheck < MAX_FIRST_HALF_DURATION; i++) {
      std::cout << "Title = " << half[i].title << "Duration = " << half[i].duration << std::endl;      
      sumCheck += half[i].duration;
      myDay.AddScheduleEntryToFirstHalf(half[i]);
      //also erase this entry from entryList
      // a side effect to handle for refactoring 
      vector<ScheduleEntry>::iterator it = entryList.begin();
      while (it != entryList.end()) {
        if (((*it).title == half[i].title) && ((*it).duration == half[i].duration)) break;
        it++; 
      }
      if (it == entryList.end()) {
        //TO DO: Again Refactor this part of code note good to have this 
        std::cout << "Some error condition, returning nullptr " << std::endl;
        delete sch;
        return nullptr;
      }
      entryList.erase(it);      
    }        
    
    //First Half is done lets do the second half 
    half.clear();     
    myAlgo->SelectAndMoveNodesWithSum(entryList, half, MAX_SECOND_HALF_DURATION);
    sumCheck = 0; 
    for (size_t i = 0; i < half.size() && sumCheck < MAX_SECOND_HALF_DURATION; i++) {
      sumCheck += half[i].duration; 
      std::cout << "Title = " << half[i].title << "Duration = " << half[i].duration << std::endl;
      myDay.AddScheduleEntryToSecondHalf(half[i]);
      //also erase this entry from entryList
      // a side effect to handle for refactoring 
      vector<ScheduleEntry>::iterator it = entryList.begin();
      while (it != entryList.end()) {
        if (((*it).title == half[i].title) && ((*it).duration == half[i].duration)) break;
        it++; 
      }
      if (it == entryList.end()) {
        //TO DO: Again Refactor this part of code note good to have this 
        std::cout << "Some error condition, returning nullptr " << std::endl;
        delete sch; 
        return nullptr;
      }
      entryList.erase(it);
    }

    sch->AddConferenceDay(myDay); 
  }

  return sch; 
}

SchedulingEngine::~SchedulingEngine()
{
  if (myAlgo != nullptr) delete myAlgo; 
}


int SchedulingEngine::CalculateRequiredDays()
{
  int sum = 0;
  auto it = this->entryList.begin(); 
  for (; it != entryList.end(); it++) {
    sum += (*it).duration; 
  }

  int daysRequired = 0; 
  if (sum % ALLOWED_MINUTES_IN_DAY == 0)
    daysRequired = sum / ALLOWED_MINUTES_IN_DAY;
  else
    daysRequired = (sum / ALLOWED_MINUTES_IN_DAY) + 1; 


  std::cout << "Total Duration requested = " << sum << std::endl;
  std::cout << "Total days required = " << daysRequired << std::endl;
  
  return daysRequired; 
}

