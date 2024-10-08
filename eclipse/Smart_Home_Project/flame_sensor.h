#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* FLAME SENSOR HW Ports and Pins Ids */
#define FLAME_SENSOR_PORT_ID                 PORTD_ID
#define FLAME_SENSOR_PIN_ID                  PIN2_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for Initializes the flame sensor pin direction.
 */
 void FlameSensor_init(void);

 /*
  * Description :
  * Function responsible for Reads the value from the flame sensor and returns it.
  */
 uint8 FlameSensor_getValue(void);

 /*
   * Description :
   * Function responsible for activate the buzzer
   * if FlameSensor Reads a value -->BUZZER ON
   * else   -->BUZZER ON
   */
 void FlameSensor(uint8 value);


#endif /* FLAME_SENSOR_H_ */
