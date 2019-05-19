#ifndef ALARM_H
#define ALARM_H

/* possible alarm states */
#define OFF 0
#define SET 1
#define ON 2

/* aet alarm time and state */
extern struct tm alarmTime;
extern char alarmStatus;

/* functions comaparing two given times with minute precision:
returns 1 if HH:MM==HH:MM, if not - 0 */
char eqHM(struct tm *, struct tm *);

/*function setting given alarm time, and status to SET */
void setAlarm(char, char);

/* function disables alarm */
void disableAlarm();

/* function retrns string indicating alarm state: OFF, SET, ON */
const char *getAlarmStatus();

/* rings an alarm when set time is reached and status is 1 or 2;
if status is 1, sets it to 2 when the alarm time is reached */
void alarm(struct tm *);

#endif
