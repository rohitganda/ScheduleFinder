#ifndef __COMMAND_LINE_HANDLER__
#define __COMMAND_LINE_HANDLER__

#include <vector>
#include <string>

using std::string; 

class CommandLineHandler {
public: 
  CommandLineHandler(int argc, char* argv[]); 
  bool ParseAndStoreCommandParameters(); 
  void PrintUsage(); 
  inline string GetInputFileName() { return inputFile; }
  ~CommandLineHandler(); 

private:
  void StoreCommandParamaeters(); 

private: 
  int argc;
  char** argv; 
  std::string inputFile;
  std::string programName; 
  bool drPissinger; 
};

#endif