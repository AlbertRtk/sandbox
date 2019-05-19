#include <time.h>
#include "alarm.h"


struct tm alarmTime;
char alarmStatus = OFF;


char eqHM(struct tm *time1, struct tm *time2) {
	return ((*time1).tm_hour==(*time2).tm_hour && (*time1).tm_min==(*time2).tm_min) ? 1 : 0;
}


void setAlarm(char hour, char minute) {
	alarmStatus = SET;
	alarmTime.tm_hour = (int) hour;
	alarmTime.tm_min = (int) minute;
}

void disableAlarm() {
	alarmStatus = OFF;
}

const char *getAlarmStatus() {
	switch(alarmStatus) {
		case OFF:
			return "OFF";
		case SET:
			return "SET";
		case ON:
			return "ON ";
	}
}

void alarm(struct tm *timeNow) {
	if(alarmStatus) {
   		if(eqHM(&alarmTime, timeNow) && alarmStatus!=ON) alarmStatus = ON;
		if(alarmStatus==ON) {
			Beep(750, 250); 
			Sleep(250);	
		}
	}
}
