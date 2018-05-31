#include "sensor_queue.h"

void createQueue(){
    appQueue = xQueueCreate(MSGQUEUE_LENGTH, sizeof(MSGTYPE));
}

void readFromQueue(void* msg){
   xQueueReceive(appQueue, msg, portMAX_DELAY);
}
    
void writeToQueue(void* msg){
   xQueueSendToBack(appQueue, msg, (TickType_t) 0);
}