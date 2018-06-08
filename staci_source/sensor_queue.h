#ifndef _SENSOR_QUEUE_H    /* Guard against multiple inclusion */
#define _SENSOR_QUEUE_H

#include "FreeRTOS.h"
#include "queue.h"
#include "debug.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


#define MSGQUEUE_LENGTH                   10
#define MSGTYPE                           unsigned int

QueueHandle_t appQueue;
    
    void createQueue();
    void readFromQueue(void* msg);
    void writeToQueue(void* msg);



    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
