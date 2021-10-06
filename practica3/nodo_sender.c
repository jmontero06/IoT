#include "contiki.h"
#include "net/netstack.h"
#include "net/nullnet/nullnet.h"
#include <string.h>
#include "sys/log.h"
#define LOG_MODULE "Broadcast Sending App"
#define LOG_LEVEL LOG_LEVEL_INFO
#define SEND_INTERVAL (8 * CLOCK_SECOND)

PROCESS(nodo_sender,"broadcas sender example");
AUTOSTART_PROCESSES(&nodo_sender);

PROCESS_THREAD(node_sender,ev,data){

    static struct etimer periodoc_timer;
    static unsigned counter=0;

    PROCESS_BEGIN();
    nullnet_buf=(uint8_t*)&counter;
    nullnet_len=sizeof(counter);

    etimer_set(&periodoc_timer,SEND_INTERVAL);
    while(1){
        
        LOG_INFO("sending %u\n",counter);
        memcpy(nullnet_buf,&counter,sizeof(counter));
        nullnet_len=sizeof(counter);

        NETSTACK_NETWORK.ouput(NULL);
        counter++;

        etimer_reset(&periodoc_timer)
    }
}