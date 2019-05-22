#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "alarm.h"


int main (void) {
   time_t eTime;			// time from Epoch
   struct tm *locTime;		// structure holding readable time info
   struct alarm alarm_1;
   struct alarm *myAlarm = &alarm_1;
   char option; 
   
   setAlarm(myAlarm, 7, 0, OFF);
   
   printf("Date:\t\tCurrent time:\t\tAlarm time:\tAtarm state:\n");
   while(1) {
   		/* get time from epoch and recalculate it to local time */
   		eTime = time( NULL );
   		locTime = localtime( &eTime );
   		
   		/* printing the time */
   		printf(	
		   		"\r%4d-%02d-%02d\t%02d:%02d:%02d\t\t%02d:%02d\t\t%s", 
				(*locTime).tm_year+1900, (*locTime).tm_mon+1, (*locTime).tm_mday,
		   		(*locTime).tm_hour, (*locTime).tm_min, (*locTime).tm_sec,
		   		(*myAlarm).tm_hour, (*myAlarm).tm_min,
		   		getAlarmStatus(myAlarm)
		);
   		fflush(stdout);
   		
   		if(kbhit()) {
   			option = getch();
   			switch(option){
   				case 'm':
   					incrAlarm(myAlarm, 0, 5);
   					break;
   				case 'h':
   					incrAlarm(myAlarm, 1, 0);
   					break;
   				case 's':	
   					toggleAlarm(myAlarm);
   					break;
   				case 'q':
   					return(0);
    	    }
		}
		
   		alarm(locTime, myAlarm);
   }
}

/*
TODO ideas:
- display 'hello message'
- save/read hello message to/from file
*/
