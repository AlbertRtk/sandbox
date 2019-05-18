#include <stdio.h>
#include <time.h>
#include <windows.h>


/* possible alarm states */
#define OFF 0
#define SET 1
#define ON 2


/* functions comaparing two given times with minute precision - HH:MM==HH:MM */
char eqHM(struct tm *time1, struct tm *time2) {
	return ((*time1).tm_hour==(*time2).tm_hour && (*time1).tm_min==(*time2).tm_min) ? 1 : 0;
}


/* rings an alarm */
void alarm(char *status, struct tm *timeAlarm, struct tm *timeNow) {
	if(status) {
   		if(eqHM(timeAlarm, timeNow) && *status!=ON) *status = ON;
		if(*status==ON) {
			Beep(750, 250); 
			Sleep(250);	
		}
	}
}


int main () {
   time_t eTime;			// time from Epoch
   struct tm *locTime;		// structure holding readable time info
   struct tm alarmTime;		// time of alarm
   char alarmStatus = SET;	// status of alarm
   
   /* setting time of alarm */
   alarmTime.tm_hour = 10;
   alarmTime.tm_min = 16;
   
   printf("Current time: \n");
   while(1) {
   		/* get time from epoch and recalculate it to local time */
   		eTime = time( NULL );
   		locTime = localtime( &eTime );
   		
   		/* printing the time */
   		printf("\r%02d:%02d:%02d", (*locTime).tm_hour, (*locTime).tm_min, (*locTime).tm_sec);
   		fflush(stdout);
   		
   		alarm(&alarmStatus, &alarmTime, locTime);
   }
   
   return(0);
}

/*
TODO ideas:
- set alarm time
- display 'hello message'
*/
