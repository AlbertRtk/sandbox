#ifndef ALARM_H
#define ALARM_H

/* possible alarm states */
#define OFF 0
#define SET 1
#define ON 2

/* alarm time and state */
struct alarm {
	int tm_hour;
	int tm_min;
	char status;
};

/* increments alarm time by given number of hours and minutes*/
void incrAlarm(struct alarm *, int, int);

/* takes care that 1st number (int *) is in the range 
from 0 (including) to 2nd number (char) (excluding) */
void normTime(int *, int);

/*function setting given alarm time, and status to SET */
void setAlarm(struct alarm *, int, int, char);

/* function toggles alarm state */
void toggleAlarm(struct alarm *);

/* function retrns string indicating alarm state: OFF, SET, ON */
const char *getAlarmStatus(struct alarm *);

/* functions comaparing given times and alarm time with minute precision:
returns 1 if HH:MM==HH:MM, if not - 0 */
char timeForAlarm(struct tm *, struct alarm *);

/* rings an alarm when set time is reached and status is 1 or 2;
if status is 1, sets it to 2 when the alarm time is reached */
int alarm(struct tm *, struct alarm *);

#endif
