#include "contiki.h"
#include "net/netstack.h"
#include "net/nullnet/nullnet.h"
#include <string.h>
#include "sys/log.h"

#define LOG_MODULE "broadcast reciver app"
#define LOG_LEVEL LOG_LEVEL_INFO
#define WAIT_INTERVAL (5 * CLOCK_SECOND)

PROCESS(nodo_reciver,"broadcas reciver");
AUTOSTART_PROCESSES(&nodo_reciver);
void input_callback(const void*data,uint16_t len,const linkaddr_t*source,const linkaddr_t*destination){
    if(len==sizeof(unsigned)){
        unsigned counter;
        memcpy(&counter,data,sizeof(counter));
        LOG_INFO("recived %u from",counter);
        LOG_INFO_LLADDR(source);
        LOG_INFO_("\n");

    }
}

PROCESS_THREAD(nodo_reciver,ev,data){
    
    static struct timer peridic_timer;
    static unsigned counter;

    PROCESS_BEGIN();
    nullnet_buf=(uint8_t*)&counter;
    nullnet_len=sizeof(counter);
    nullnet_set_input_callback(input_callback);

    etimer_set(&peridic_timer, WAIT_INTERVAL);

    while(1){
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&peridic_timer));
        LOG_INFO("waiting for data...\n");
        etimer_reset(&peridic_timer);
    }
    PROCESS_END();
}