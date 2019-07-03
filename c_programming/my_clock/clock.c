#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "alarm.h"


char *getstr();
char *readfile(FILE*);

int main (void) {
   time_t eTime;			// time from Epoch
   struct tm *locTime;		// structure holding readable time info
   struct alarm alarm_1;
   struct alarm *myAlarm = &alarm_1;
   char option; 
   char *helloMsg = NULL;
   int showMsg = 0;
   FILE *fp;
   
   setAlarm(myAlarm, 7, 0, OFF);
   
   fp = fopen("msg.txt", "r");
   if(fp!=NULL) {
   		helloMsg = readfile(fp);
   		fclose(fp);
		}
   
   //printf("Date:\t\tCurrent time:\t\tAlarm time:\tAtarm state:\n");
   while(1) {
   		/* get time from epoch and recalculate it to local time */
   		eTime = time( NULL );
   		locTime = localtime( &eTime );
   		
   		/* printing the time */
   		if( showMsg && (*helloMsg) ) {
   			printf("\r%s It is %02d:%02d:%02d                               ", helloMsg, (*locTime).tm_hour, (*locTime).tm_min, (*locTime).tm_sec);
		}
		else {
			printf(	
		   		"\r%4d-%02d-%02d\t%02d:%02d:%02d\tAlarm: %02d:%02d\t%s", 
				(*locTime).tm_year+1900, (*locTime).tm_mon+1, (*locTime).tm_mday,
		   		(*locTime).tm_hour, (*locTime).tm_min, (*locTime).tm_sec,
		   		(*myAlarm).tm_hour, (*myAlarm).tm_min,
		   		getAlarmStatus(myAlarm)
			);
		}
   		
   		fflush(stdout);
   		
   		if(kbhit()) {
   			option = getch();
   			switch(option){
   				case 'm':	// alarm minut + 5
   					incrAlarm(myAlarm, 0, 1);
   					break;
   				case 'h':	// alarm hour +1
   					incrAlarm(myAlarm, 1, 0);
   					break;
   				case 's':	
   					toggleAlarm(myAlarm);
   					break;
   				case 't':
   					system("cls");
   					printf("Enter your hello message:\n");
   					helloMsg = getstr();
   					fp = fopen("msg.txt", "w");
   					if(fp!=NULL) {
   						fprintf(fp, "%s", helloMsg);
   						fclose(fp);
					   }
   					system("cls");
   					break;
   				case 'q':	// quit the program
   					return(0);
   				default:
   					;	// random key pressed - do nothing
    	    }
		}
		
   		showMsg = alarm(locTime, myAlarm);
   }
}


char *getstr() {
	char *str, ch;
	int i = 1;
	str = (char*)malloc(sizeof(char));
	
	ch = getc(stdin);
	while(ch!='\n') {
		str = (char*)realloc(str, (i+1)*sizeof(char));	// (i+1) - length of string, one place extra for '\0'
		str[i-1] = ch;
		i++;
		ch = getc(stdin);
	}
	str[i-1] = '\0';	// end of string
	
	return str;
}


char *readfile(FILE *fp){
	char *str, ch;
	int i = 1;
	str = (char*)malloc(sizeof(char));
	
	ch = fgetc(fp);  // reading the first character
	while(ch!=EOF) {
		str = (char*)realloc(str, (i+1)*sizeof(char));	// changing length of string
		str[i-1] = ch;
		i++;
		ch = fgetc(fp);
	}
	str[i-1] = '\0';	// changing new line '\n' to end of string '\0'
	
	return str;
}

