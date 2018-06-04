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

    
#define APP_TASK_START      0x23

    
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
