#ifndef __SCHEDULE_OUTPUT_HANDLER_H__
#define __SCHEDULE_OUTPUT_HANDLER_H__

class Schedule; 

class ScheduleOutputStreamer
{
public: 
  ScheduleOutputStreamer(Schedule* sch){ this->mySchedule = sch;}
  void PrintSchedule(); 
private:
  Schedule* mySchedule; 
};

#endif