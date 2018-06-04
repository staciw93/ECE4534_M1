#include "app.h"
#include "debug.h"

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Set up GPIO ports */
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, 0x00FF);
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_D, 0x00FF);
    
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    dbgOutputEvent(APP_TASK_START);
    unsigned int count = 0;
    
    while(1){
        
        PLIB_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_E, count);
        PLIB_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_D, count);
        if(count < 127)
            count = count + 1;
        else
            count = 0;
        
    }
    
}

 

/*******************************************************************************
 End of File
 */
