#ifndef __SCHEDULING_ALGO_H__
#define __SCHEDULING_ALGO_H__

#include <list>
#include "ScheduleEntry.h"
class SchedulingAlgo
{
public:
  virtual void SelectAndMoveNodesWithSum(
    std::vector<ScheduleEntry>& input,
    std::vector<ScheduleEntry>& entryForSum,
    int sum) = 0; 

};

#endif 