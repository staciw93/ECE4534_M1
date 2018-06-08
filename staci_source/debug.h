#ifndef _DEBUG_H    /* Guard against multiple inclusion */
#define _DEBUG_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

    
#define APP_TASK_INIT           0x22
#define APP_TASK_START          0x23

#define ENTER_STATE_0           0x30
#define ENTER_STATE_1           0x31
#define ENTER_STATE_2           0x32
#define ENTER_STATE_3           0x33
    
#define START_USART_WRITE       0x50
#define STOP_USART_WRITE        0x51
    
#define ENTER_ISR               0x60
#define EXIT_ISR                0x61
    
#define MESSAGE_WRITE_SUCCESS   0x70
    
#define START_ADC_READ          0x10
#define STOP_ADC_READ           0x11

#define ERR_IN_DEFAULT_STATE    0x40
#define ERR_QUEUE_NOT_CREATED   0x41
#define ERR_MESSAGE_WRITE_FAIL  0x42
#define ERR_UART_BUFFER_FULL    0x43
#define ERR_VAL_OUT_OF_RANGE    0x44
#define ERR_HANDLER_CALLED      0x45

    
void dbgOutputVal(unsigned int outVal);
void dbgUARTVal(unsigned int outVal);
void dbgOutputEvent(unsigned int outVal);
void stopBadError();

    

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
