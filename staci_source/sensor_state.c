#include "sensor_state.h"

double SensorOutputState(int readingNum, double curSensorVal, double curSum){
    double retVal = 0;
    
    switch(readingNum){
        case 0:
        {
            retVal = curSensorVal;
            dbgOutputVal();
            break;
        }
          
        case 1:
        {
            retVal = curSensorVal + curSum;
            dbgOutputVal();
            break;
        }
            
        case 2:
        {
            retVal = curSensorVal + curSum;
            dbgOutputVal();
            break;
        }
            
        case 3:
        {
            retVal = (curSensorVal + curSum)/4;
            dbgOutputVal();
            dbgUARTVal();
            break;
        }
            
        default:
        {
            //Error
            break;
        }
    }    
    return retVal;
}
