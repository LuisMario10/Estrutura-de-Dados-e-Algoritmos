#include <stdio.h>

typedef struct _time {
    int dayInit;
    int dayFinal;
    int hoursInit ;
    int hoursFinal;
    int minutesInit;
    int minutesFinal;
    int secoundsInit;
    int secoundsFinal;
    
} Time;

void timer(Time time) {
    int days;
    int hours;
    int minutes;
    int secounds;
    
    int totalHours = (time.dayFinal - time.dayInit) * 24;
    hours = (totalHours - time.hoursInit) + time.hoursFinal;
    
    while(hours >= 24) {
        hours = hours - 24;
        days++;
    }
    
    if(time.minutesInit > time.minutesFinal && time.hoursInit > time.hoursFinal) {
        hours--;
        minutes = ((time.hoursInit - time.hoursFinal) * 60) - (time.minutesInit - time.minutesFinal);
    } else {
        minutes = time.minutesFinal - time.minutesInit;
    }
    
    if(time.secoundsInit > time.secoundsFinal) {
        minutes--;
        secounds = ((time.minutesInit - time.minutesFinal) * 60) - (time.secoundsInit- time.secoundsFinal);
    }
    
    printf("%i Dia(s)\n%i Hora(s)\n%i Minuto(s)\n%i Segundo(s)", days, hours, minutes, secounds);
}

int main(void) {
    Time myEvent;
    myEvent.dayInit = 5;
    myEvent.dayFinal = 9;
    myEvent.hoursInit = 8;
    myEvent.hoursFinal = 6;
    myEvent.minutesInit = 12;
    myEvent.minutesFinal = 13;
    myEvent.secoundsInit = 23;
    myEvent.secoundsFinal = 23;
    timer(myEvent);
    return 0;
}