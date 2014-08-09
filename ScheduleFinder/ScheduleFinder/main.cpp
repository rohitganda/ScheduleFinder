#include <iostream>
#include <string>
#include "CommandLineHandler.h"
#include "Constants.h"
#include "ScheduleAppIntegratorEngine.h"

using namespace std; 

static void KeepWindowOpen()
{
  std::cin.clear();
  std::cin.sync();
  char ch = getchar();
}

int main(int argc, char* argv[])
{
  CommandLineHandler cmdHandler(argc, argv); 
  if (!cmdHandler.ParseAndStoreCommandParameters()) {
    cmdHandler.PrintUsage();
    return 1; 
  }

  /*FILE_STREAM can */
  ScheduleAppIntegratorEngine appEngine(cmdHandler.GetInputFileName(), FILE_STREAM); 
  if (!appEngine.Run()) return 1;   

  KeepWindowOpen(); 
  return 0;
}