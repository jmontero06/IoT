#include "contiki.h"
#include "sys/etimer.h"
#include <stdio.h>
#include "virtual_sensorp1.h"

PROCESS(sensor_node,"sensor reading node");
AUTOSTART_PROCESSES(&sensor_node);

static struct etimer timer;

PROCESS_THREAD(sensor_node,ev,data){
    PROCESS_BEGIN();

    etimer_set(&timer,3*CLOCK_SECOND);
    while (1){
       PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));

       float temp=read_temperature();
       printf("temperature reading: %.2fºC\n",temp);

       etimer_reset(&timer);
    }
    
    PROCESS_END();
}