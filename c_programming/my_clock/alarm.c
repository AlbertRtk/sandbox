#include <time.h>
#include "alarm.h"


void incrAlarm(struct alarm *thisAlarm, char dh, char dm) {
	if(dh) {
		(*thisAlarm).tm_hour += (int) dh;
	}
	if(dm) {
		(*thisAlarm).tm_min += (int) dm;
	}
	normTime(&(*thisAlarm).tm_hour, 24);
	normTime(&(*thisAlarm).tm_min, 60);
}


void normTime(int *toNorm, char norm) {
	if(*toNorm>=norm) {
		*toNorm -= norm;	// e.g., 24 --> 0, for norm=24
	}
	else if(*toNorm<0) {
		*toNorm += norm;	// e.g., -1 --> 59, for norm=60
	}
}


void setAlarm(struct alarm *thisAlarm, char hour, char minute, char status) {
	(*thisAlarm).status = status;
	(*thisAlarm).tm_hour = (int) hour;
	(*thisAlarm).tm_min = (int) minute;
}


void toggleAlarm(struct alarm *thisAlarm) {
	(*thisAlarm).status = (*thisAlarm).status!=OFF ? OFF : SET;
}


const char *getAlarmStatus(struct alarm *thisAlarm) {
	switch( (*thisAlarm).status ) {
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

