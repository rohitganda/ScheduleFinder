#ifndef __INPUT_PARSER__
#define __INPUT_PARSER__

#include <vector>
#include <string>

class InputValidator {
public:
  InputValidator(const std::vector<std::string>& inputScheduleEntries);
  bool PerformAllTests(const std::string& scheduleEntry);
  void FindValidAndInvalidEntries(std::vector<std::string>& invalid,
                                            std::vector<std::string>& valid);
  ~InputValidator(){}


private:
  bool PerformStringTest(const std::string& searchIn, const std::string& searchForLast);
  bool PerformIsAlphaAndSpaceTest(const std::string& str);
  bool PerformMinuteTest(const std::string& s);
  bool PerformLightningTest(const std::string& s);
  bool PerformDigitInNameTest(const std::string& s);

private:
  const std::vector < std::string >& inputScheduleEntries; 
};

#endif