#include <time.h>
#include "alarm.h"


void setAlarm(struct alarm *thisAlarm, char hour, char minute, char status) {
	(*thisAlarm).status = status;
	(*thisAlarm).tm_hour = (int) hour;
	(*thisAlarm).tm_min = (int) minute;
}

void toggleAlarm(struct alarm *thisAlarm) {
	(*thisAlarm).status = (*thisAlarm).status!=OFF ? OFF : SET;
}

const char *getAlarmStatus(struct alarm *thisAlarm) {
	switch((*thisAlarm).status) {
		case OFF:
			return "OFF";
		case SET:
			return "SET";
		case ON:
			return "ON ";
	}
}

char timeForAlarm(struct tm *time, struct alarm *thisAlarm) {
	return ((*time).tm_hour==(*thisAlarm).tm_hour && (*time).tm_min==(*thisAlarm).tm_min) ? 1 : 0;
}

void alarm(struct tm *timeNow, struct alarm *thisAlarm) {
	if( (*thisAlarm).status ) {
   		if(timeForAlarm(timeNow, thisAlarm) && (*thisAlarm).status==SET) {
   			(*thisAlarm).status = ON;	
		}
		if( (*thisAlarm).status==ON ) {
			Beep(750, 250); 
			Sleep(250);	
		}
	}
}
