#include "app.h"
#include "debug.h"
#include "sensor_state.h"
#include "sensor_queue.h"

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    dbgOutputEvent(APP_TASK_INIT);
    
    /* Set up GPIO ports */
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, 0x00FF);
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_D, 0x00FF);
    
    /* Set up ADC */
    DRV_ADC_Close();
    DRV_ADC_Initialize();
    DRV_ADC_Open();
    DRV_ADC_Start();
            
    /* Set up Timer */
    DRV_TMR0_Start();
    
    /* Create Message Queue*/
    createQueue();
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
    unsigned int state = 0;
    unsigned int curSum = 0;
    unsigned int nxtSum = 0;
    unsigned int count = 0;
    
    while(1){
        MSGTYPE msg;
        readFromQueue(&msg);
        
        nxtSum = avgStateMachine(curSum, msg, state);
        
        if(state >= 3)
            state = 0; 
        else
            state = state + 1;
        
        curSum = nxtSum;
        count = count + 1;
        if(count == 33)
            state = 4;
        
    }
    
}

 

/*******************************************************************************
 End of File
 */
