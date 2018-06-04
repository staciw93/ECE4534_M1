#include "debug.h"

void dbgOutputVal(unsigned int outVal){
    if(outVal <= 127){
        PLIB_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_D, outVal);
    }
}

void dbgUARTVal(unsigned int outVal){
    
}

void dbgOutputEvent(unsigned int outVal){
    if(outVal <= 127){
        PLIB_PORTS_Write (PORTS_ID_0, PORT_CHANNEL_E, outVal);
    }
}

void stopBadError(){
    
}