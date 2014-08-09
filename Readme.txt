About ScheduleFinder:

ScheduleFinder is a command line tool for generating a schedule for conferences in the format listed in problem below. This code was created for ThoughtWorks in response to the problem listed below but using the same code for my application for HackerSchool: 

========================================================================================
You are planning a big programming conference and have received many proposals which have passed the initial screen process but you're having trouble fitting them into the time constraints of the day -- there are so many possibilities! So you write a program to do it for you.

• The conference has multiple tracks each of which has a morning and afternoon session.
• Each session contains multiple talks.
• Morning sessions begin at 9am and must finish by 12 noon, for lunch.
• Afternoon sessions begin at 1pm and must finish in time for the networking event.
• The networking event can start no earlier than 4:00 and no later than 5:00.
• No talk title has numbers in it.
• All talk lengths are either in minutes (not hours) or lightning (5 minutes).
• Presenters will be very punctual; there needs to be no gap between sessions.

Note that depending on how you choose to complete this problem, your solution may give a different ordering or combination of talks into tracks. This is acceptable; you don’t need to exactly duplicate the sample output given here.
 
Test input:
 
Writing Fast Tests Against Enterprise Rails 60min
Overdoing it in Python 45min
Lua for the Masses 30min
Ruby Errors from Mismatched Gem Versions 45min
Common Ruby Errors 45min
Rails for Python Developers lightning
Communicating Over Distance 60min
Accounting-Driven Development 45min
Woah 30min
Sit Down and Write 30min
Pair Programming vs Noise 45min
Rails Magic 60min
Ruby on Rails: Why We Should Move On 60min
Clojure Ate Scala (on my project) 45min
Programming in the Boondocks of Seattle 30min
Ruby vs. Clojure for Back-End Development 30min
Ruby on Rails Legacy App Maintenance 60min
A World Without HackerNews 30min
User Interface CSS in Rails Apps 30min
 
Test output:
 
Track 1:
09:00AM Writing Fast Tests Against Enterprise Rails 60min
10:00AM Overdoing it in Python 45min
10:45AM Lua for the Masses 30min
11:15AM Ruby Errors from Mismatched Gem Versions 45min
12:00PM Lunch
01:00PM Ruby on Rails: Why We Should Move On 60min
02:00PM Common Ruby Errors 45min
02:45PM Pair Programming vs Noise 45min
03:30PM Programming in the Boondocks of Seattle 30min
04:00PM Ruby vs. Clojure for Back-End Development 30min
04:30PM User Interface CSS in Rails Apps 30min
05:00PM Networking Event
 
Track 2:
09:00AM Communicating Over Distance 60min
10:00AM Rails Magic 60min
11:00AM Woah 30min
11:30AM Sit Down and Write 30min
12:00PM Lunch
01:00PM Accounting-Driven Development 45min
01:45PM Clojure Ate Scala (on my project) 45min
02:30PM A World Without HackerNews 30min
03:00PM Ruby on Rails Legacy App Maintenance 60min
04:00PM Rails for Python Developers lightning
05:00PM Networking Event
========================================== 
========================================================================================

Algorithms Used: 
- This problem was deceptively simple and actually falls in the NP-complete category. The algorithms chosen here might not present themselves as the optimum solution here. Following are the algorithms chosen to solve this problem: 
a. SubsetSum - This one produces exact solution. 
b. Best Fit Heuristic - which find some solution. 

ScheduleFinder Bugs: 
- BEWARE: This program can in no way be considered as a release version, it still needs a lot of work to be done. 
- For now it is error prone and requires a lot of testing, debugging, refactoring and cleaning. 
- The mktime() function was not normalizing the result and due to shortage of time I chose to just print the divided schedules. So the output might not be in the requested format. The output is displayed in the format: 
====>
Communicating Over Distance 60min
Rails Magic 60min
Woah 30min
Sit Down and Write 30min
Lunch
Accounting-Driven Development 45min
Clojure Ate Scala (on my project) 45min
=====>

Build And Test Instructions: 
- This project was created in Visual Studio 2013 (MSDN licensed version :-)), so please load the solution in VS2013 and build. The testfile used to test this program has been included, and a half cooked :-( version of test program is also included, some output from the testprogram has been included in the input file for testing purpose. 

- One build problem (ScheduleFinder debug mode) was noticed which might be due to the build order. To workaround, rebuild the FileHandler.cpp and then build the project. This problem was not noticed in Release mode builds. 

Other Notes:
- This program is by no means a release candidate, please consider it as a prototype.  
- This program can be extended by improved by adding new algorithms. 


IMPORTANT: Please write to me at ROHIT_GANDA@YAHOO.COM in case you need any help in building, or face any other problems. 