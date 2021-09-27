#include "contiki.h"
#include "sys/etimer.h"
#include <stdio.h>
#include "virtual_sensor_p1.h"

PROCESS(practica_1,"sensor reading node");
AUTOSTART_PROCESSES(&practica_1);

static struct etimer timer;

PROCESS_THREAD(practica_1,ev,data){
    PROCESS_BEGIN();

    etimer_set(&timer,3*CLOCK_SECOND);
    while (1){
       PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
       printf("read temp");

        adjust_temperature(21,27);
        
       etimer_reset(&timer);
    }
    
    PROCESS_END();
}