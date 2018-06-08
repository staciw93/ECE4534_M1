#include "sensor_queue.h"


void createQueue(){
        
    appQueue = xQueueCreate(MSGQUEUE_LENGTH, sizeof(MSGTYPE));
    
    if(appQueue == NULL){
        dbgOutputEvent(ERR_QUEUE_NOT_CREATED);
        stopBadError();
    }
}
void readFromQueue(void* msg){
    xQueueReceive(appQueue, msg, portMAX_DELAY);
}
void writeToQueue(void* msg){
    portBASE_TYPE pxHigherPriorityTaskWoken = pdFALSE;
    if(xQueueSendToBackFromISR(appQueue, msg, &pxHigherPriorityTaskWoken) == pdPASS)
        dbgOutputEvent(MESSAGE_WRITE_SUCCESS);
    else{
        dbgOutputEvent(ERR_MESSAGE_WRITE_FAIL);
        stopBadError();
    }

}


/* *****************************************************************************
 End of File
 */
