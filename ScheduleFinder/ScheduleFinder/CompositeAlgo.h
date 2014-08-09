#ifndef __COMPOSITE_ALGO_H__
#define __COMPOSITE_ALGO_H__


#include "SchedulingAlgo.h"

class CompositeAlgo : public SchedulingAlgo
{
public:
  virtual void SelectAndMoveNodesWithSum(
    std::vector<ScheduleEntry>& input,
    std::vector<ScheduleEntry>& subsetSum,
    int sum); 

  static std::vector<ScheduleEntry> results; 

private:
  //Helper Functions 
  void CompositeAlgo::SubsetSum(std::vector<ScheduleEntry>& mainSet,
    std::vector<ScheduleEntry>& outVector,
    std::vector<ScheduleEntry>& resultVector,
    int index,
    const int sum);
  void PerformBestFitHeuristic(std::vector<ScheduleEntry>& mainSet,
    std::vector<ScheduleEntry>& outVector,
    int sum);

};

#endif