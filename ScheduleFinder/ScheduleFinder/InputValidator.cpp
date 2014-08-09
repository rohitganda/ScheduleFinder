#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "InputValidator.h"
#include "Utilities.h"

using std::vector; 
using std::string;

InputValidator::InputValidator(const vector<string>& scheduleEntries) : 
inputScheduleEntries(scheduleEntries)
{  }

void InputValidator::FindValidAndInvalidEntries(vector<string>& invalid, vector<string>& valid)
{
  for (size_t i = 0; i < inputScheduleEntries.size(); ++i) {
    if (PerformAllTests(inputScheduleEntries[i]))
      valid.push_back(inputScheduleEntries[i]);
    else
      invalid.push_back(inputScheduleEntries[i]); 
  }
}

bool InputValidator::PerformAllTests(const string& s)
{  
  /*you can add tests here for one schedule entry as read from input file */
  if (!PerformMinuteTest(s) && !PerformLightningTest(s)) return false;
  if (!PerformDigitInNameTest(s)) return false;
  if (!PerformIsAlphaAndSpaceTest(s)) return false;
  return true; 
}

bool InputValidator::PerformMinuteTest(const string& s)
{
  //Rule: Case insensitive comparison of last occurence of "min" 
  string searchForLast("min");
  return PerformStringTest(s, searchForLast);
}

bool InputValidator::PerformLightningTest(const string& s)
{
  //Rule: Case insensitive comparison of last occurence of "lightning" 
  string searchForLast("lightning");
  return PerformStringTest(s, searchForLast);
}

bool InputValidator::PerformDigitInNameTest(const string& searchIn)
{  
  auto pos = findLastOccurence(searchIn, " ");
  const char* cStr = searchIn.c_str();
  
  for (size_t i = 0; i < pos; ++i) {
    if (std::isdigit(cStr[i])) return false; 
  }
  
  return true; 
}

bool InputValidator::PerformStringTest(const string& searchIn, const string& searchForLast)
{
  auto pos = findLastOccurence(searchIn, searchForLast);
  if ((searchIn.size() - pos) > searchForLast.size()) return false;
  return true;
}

bool InputValidator::PerformIsAlphaAndSpaceTest(const std::string& s)
{  
  const char* cStr = s.c_str();
  for (size_t i = 0; i < s.size(); ++i) {
    if (!((cStr[i] >= 0) && (cStr[i] < 128))) return false;
  }
  return true;
}
