#include "contiki.h"

#include "sys/etimer.h"
#include "sys/ctimer.h"

#include <stdio.h>

PROCESS(timers_demo,"timers demo");
AUTOSTART_PROCESSES(&timers_demo);

static struct etimer event_timer;
static struct ctimer callback_timer;

void callback_function(){
    printf("this is the callback function\n");
    ctimer_reset(&callback_timer);
}

PROCESS_THREAD(timers_demo,ev,data){
    PROCESS_BEGIN();

    ctimer_set(&callback_timer, 4*CLOCK_SECOND,callback_function,NULL);
    etimer_set(&event_timer,2 * CLOCK_SECOND);
    while (2){
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&event_timer));
        printf("envent timer expider \n");
        etimer_reset(&event_timer);
    }
    
    printf("processes ending ...\n");
    PROCESS_END();
}