#ifndef _SENSOR_STATE_H    /* Guard against multiple inclusion */
#define _SENSOR_STATE_H


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


   unsigned int avgStateMachine(unsigned int sumOfReadings, unsigned int curReading, unsigned int stateNum);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
