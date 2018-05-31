#ifndef _SENSOR_STATE_H    /* Guard against multiple inclusion */
#define _SENSOR_STATE_H

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    
    /*
        @param readingNum, curSensorVal, curSum
        @return sum of sensor values
     */
    double SensorOutputState(int readingNum, double curSensorVal, double curSum);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
