#include "sensor_state.h"
#include "debug.h"

unsigned int convertToCM(unsigned int reading){
    unsigned int cmVal = 0;
    
    if(reading >= 450)
        cmVal = 10;
    else if(reading >= 325 && reading <= 499)
        cmVal = 15;
    else if(reading >= 225 && reading <= 324)
        cmVal = 20;
    else if(reading >= 175 && reading <= 224)
        cmVal = 30;
    else if(reading >= 140 && reading <= 174)
        cmVal = 40;
    else if(reading >= 125 && reading <= 139)
        cmVal = 50;
    else if(reading >= 110 && reading <= 124)
        cmVal = 60;
    else if(reading >= 80 && reading <= 109)
        cmVal = 70;
    else if(reading >= 75 && reading <= 89)
        cmVal = 40;
    else
        cmVal = 0;
    
    return cmVal;
}

unsigned int avgStateMachine(unsigned int sumOfReadings, unsigned int curReading, unsigned int stateNum){
    unsigned int sum = 0;
    unsigned int cm = 0;
    
    switch(stateNum){
        case 0:
        {
            dbgOutputEvent(ENTER_STATE_0);
            cm = convertToCM(curReading);
            dbgOutputVal(cm);
            sum = cm;
            break;
        }
        case 1:
        {
            dbgOutputEvent(ENTER_STATE_1);
            cm = convertToCM(curReading);
            dbgOutputVal(cm);
            sum = cm + sumOfReadings;
            break;
        }
        case 2:
        {
            dbgOutputEvent(ENTER_STATE_2);
            cm = convertToCM(curReading);
            dbgOutputVal(cm);
            sum = cm + sumOfReadings;
            break;
        }
        case 3:
        {
            dbgOutputEvent(ENTER_STATE_3);
            cm = convertToCM(curReading);
            dbgOutputVal(cm);
            sum = cm + sumOfReadings;
            sum = sum >> 2;
            dbgUARTVal(sum);
            break;
        }
        default:
        {
            dbgOutputEvent(ERR_IN_DEFAULT_STATE);
            stopBadError();
        }
    }
    
    return sum;
}