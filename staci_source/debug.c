#include "debug.h"

void dbgOutputVal(unsigned int outVal){
    if(outVal <= 127 && outVal >= 0){
        PLIB_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_D, outVal);
    }
    else{
        dbgOutputEvent(ERR_VAL_OUT_OF_RANGE);
        stopBadError();
    }
}

void dbgUARTVal(unsigned int outVal){
    dbgOutputEvent(START_USART_WRITE);
    if(DRV_USART0_TransmitBufferIsFull() & DRV_USART0_TransferStatus()){
        dbgOutputEvent(ERR_UART_BUFFER_FULL);
        stopBadError();
    }
    else{
        DRV_USART0_WriteByte(outVal);
        DRV_USART0_WriteByte('c');
        DRV_USART0_WriteByte('m');
    }
    dbgOutputEvent(STOP_USART_WRITE);
}

void dbgOutputEvent(unsigned int outVal){
    if(outVal <= 127){
        PLIB_PORTS_Write (PORTS_ID_0, PORT_CHANNEL_E, outVal);
    }
}

void stopBadError(){
    dbgOutputEvent(ERR_HANDLER_CALLED);
    
    PLIB_INT_Disable(INT_ID_0);
        
    vTaskSuspendAll();
    
    while(1);
}