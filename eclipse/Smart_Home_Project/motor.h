#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* motor HW Ports and Pins Ids */
#define MOTOR_IN1_PORT_ID                 PORTB_ID
#define MOTOR_IN1_PIN_ID                  PIN0_ID

#define MOTOR_IN2_PORT_ID                 PORTB_ID
#define MOTOR_IN2_PIN_ID                  PIN1_ID

#define MOTOR_E_PORT_ID                   PORTB_ID
#define MOTOR_E_PIN_ID                    PIN3_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	CW,A_CW,STOP
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for Initializes the DC motor by setting the direction for the motor pins and stopping the
 * motor at the beginning.
 */
 void DcMotor_Init(void);

 /*
  * Description :
  * Function responsible for Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based
  * on the input duty cycle.
  */
 void DcMotor_Rotate(DcMotor_State state, uint8 speed);

 /*
  * Description :
  * Automatic Fan Speed Control:
  * Fan speed is automatically adjusted based on room temperature controlled by a PWM signal.
  * The fan operates at different speeds based on temperature ranges.
  */
 void Automatic_Fan_Speed_Control(DcMotor_State state, uint8 Temperature);

#endif /* MOTOR_H_ */
