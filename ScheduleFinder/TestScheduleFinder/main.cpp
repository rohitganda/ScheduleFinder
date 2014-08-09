#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std; 

const int MAX_WORDS = 20; 
const int MAX_TIME = 240; 
const char NEWLINE = '\r\n'; 
const int MAX_TITLES = 100; 

void KeepWindowOpen()
{
  cin.clear(); 
  cin.sync(); 
  char ch = getchar(); 
}

string AddSingleSpace()
{
  if (rand() % 2) return " ";
  return "";

}
string AddSpaces()
{
  
  if (rand() % 2) return "           ";
  return ""; 
}

string HowManyMinutes()
{
  return to_string(rand() % MAX_TIME); 
}

string AddMinLightningNothing()
{
  int choice = rand() % 3; 
  switch (choice){
  case 0: 
    return "min"; 
  case 1:
    return "lightning"; 
  case 2:
    return ""; 
  }
  return "min"; 
}

string GenerateTitle()
{
  string spaces = "       "; 
  vector<string> words = { "Writing", "Fast", "Tests", "Against", "Enterprise",
    "Rails", "Overdoing", "it", "in", "Pyt5hon", "Lua", "for", "the", "Masses",
    "30min", "Ruby", "Errors", "from", "Mismatched", "Gem", "Versions",    
    "Rails for Python", "Developers lightning", 
    "Communicating Over", "Distance", 
    "Accounting - Driven ", "Development 45min", 
    "Woah", "Sit Down a;; nd Write", 
    "Pair Programming vs Noise", "Rails Magic",     
    "Ruby on Rails : ", "Why We Should Move On",
    "Clojure Ate Scala(on my project)", 
    "Common Errors",
    "Programming", "Algorithms", "in the Boondocks of Seattle",
    "Ruby vs.Clojure", "for Back - End Development",
    "Ruby on Rails", "C++", "=========", " Legacy App", 
    "Maintenance","A World Without HackerNews", 
    "Cool ", "9999999999999999", ""
  }; 

  
  int howManyWords = rand()%MAX_WORDS; 

  string title = "";
  for (int i = 0; i < howManyWords; i++) {
    title = title + words[rand() % words.size()]; 
  }

  title = title + AddSingleSpace() + HowManyMinutes() + AddMinLightningNothing() + AddSpaces(); 
  return title; 

}

int main()
{
  cout << "======================================================================"<<endl;
  cout << "          Generating the test File for ScheduleFinder.exe             " << endl;
  cout << "======================================================================" << endl;
  
  string fileName = "TestScheduleFinder.txt"; 
  vector<string> titles; 
  
  srand(time(NULL)); //Old technique 

  int totalTitles = rand() % MAX_TITLES;
  for (int i = 0; i < totalTitles; i++) {
    titles.push_back(GenerateTitle()); 
  }

  ofstream op; 
  op.open(fileName.c_str(), ios::out); 
  if (!op.good()) return 1; 
  
  cout << "Writing titles to file ... " << endl; 
  for (size_t i = 0; i < titles.size(); i++) {
    cout << titles[i] << endl;
    op << titles[i] << endl;
  }

  op.close(); 

  KeepWindowOpen(); 
  return 0; 
}