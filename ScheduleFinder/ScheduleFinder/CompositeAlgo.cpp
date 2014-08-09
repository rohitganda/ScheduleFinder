#include <iostream>
#include <list>
#include <vector>
#include "SchedulingAlgo.h"
#include "CompositeAlgo.h"

using std::list;
using std::vector; 

void CompositeAlgo::SelectAndMoveNodesWithSum(vector<ScheduleEntry>& input,
  vector<ScheduleEntry>& subsetSum,
  int sum)
{
  if (sum == 0) return;   

  vector<ScheduleEntry> outVector;
  vector<ScheduleEntry> resultVector; 

  SubsetSum(input, outVector, resultVector, 0, sum);

  if (!resultVector.size()) {
    std::cout << "Could not find exact match, proceeding to best fit heuristic" << std::endl;
    this->PerformBestFitHeuristic(input, resultVector, sum); 
  }
  //Sure of having something in the resultVector by now. 
  //Remove everything
  subsetSum = resultVector; 
}


void CompositeAlgo::SubsetSum(vector<ScheduleEntry>& mainSet,
  vector<ScheduleEntry>& outVector,
  vector<ScheduleEntry>& resultVector,
  int index, 
  const int sum)
{
  
  for (size_t i = index; i < mainSet.size(); i++)
  {
    int count = 0;
    for (auto item : outVector)
      count += item.duration;

    if ((mainSet[i].duration + count) == sum)
    {
      for (auto item : outVector) {
        std::cout << item.duration << " ";
        resultVector.push_back(item);        
      }
      resultVector.push_back(mainSet[i]);
      outVector.push_back(mainSet[i]);
      std::cout << mainSet[i].duration;
      std::cout << std::endl;
    }
    else if ((mainSet[i].duration + count) > sum)
    return;

    outVector.push_back(mainSet[i]);
    SubsetSum(mainSet, outVector, resultVector, i + 1, sum);
    //remove the last considered item from outVector
    outVector.pop_back();
    /*    for (auto it = outVector.begin(); it != outVector.begin(); it++) {
      if ((*it).title == mainSet[i].title)
        outVector.erase(it); 
    }
    */
  }
}


void CompositeAlgo::PerformBestFitHeuristic(std::vector<ScheduleEntry>& mainSet,
  std::vector<ScheduleEntry>& outVector,
  int sum)
{
  if (sum == 0) return;   
  int subsetSum = 0; 
  int remainingLimit = sum;
  for (size_t i = 0; i < mainSet.size(); i++) {
    if (remainingLimit > mainSet[i].duration) {
      remainingLimit -= mainSet[i].duration;
      outVector.push_back(mainSet[i]); 
    }
    else if (remainingLimit <= 0) 
      break;
  }  
}
