#ifndef __SCHEDULE_ENGINE__
#define __SCHEDULE_ENGINE__

#include <vector>
#include <list>

class Schedule; 
class SchedulingAlgo; 
struct ScheduleEntry; 
class ConferenceDay; 

class SchedulingEngine {
public:
  SchedulingEngine(std::vector<ScheduleEntry>& incoming) : entryList(incoming)
  {myAlgo = nullptr;}
  virtual void CreateAlgorithm(int algoType);
  void SetAlgorithm(SchedulingAlgo* myAlgo); 
  virtual void SetAlgorithmData(); 
  bool RunAndPopulate(std::vector<ConferenceDay>& confDays);
  Schedule* RunAndCreateSchedule();
  virtual ~SchedulingEngine();

private:
  int CalculateRequiredDays(); 

private:
  std::vector<ScheduleEntry> entryList; 
  SchedulingAlgo* myAlgo;
  

};

#endif