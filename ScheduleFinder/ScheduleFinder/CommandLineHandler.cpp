#include <iostream>
#include "CommandLineHandler.h"


using std::cout;
using std::endl;
using std::string;

CommandLineHandler::CommandLineHandler(int argc, char* argv[])
{
  this->argc = argc; 
  this->argv = argv; 
  this->drPissinger = false; 
}

bool CommandLineHandler::ParseAndStoreCommandParameters()
{
  programName.assign(argv[0]);  
  if ((argc != 2)) return false;
  inputFile = string(argv[1]);   
  return true; 
}

void CommandLineHandler::PrintUsage()
{
  cout <<  programName << " inputFile " << endl;
  cout << "inputFile = Path to input file" << endl;
  cout << "Refer to readme.txt for details of input file format " << endl;
}

CommandLineHandler::~CommandLineHandler(){}
