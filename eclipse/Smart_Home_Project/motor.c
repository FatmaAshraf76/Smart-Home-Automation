#include "common_macros.h" /* For GET_BIT Macro */
#include "motor.h"
#include "gpio.h"
#include "lcd.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for Initializes the DC motor by setting the direction for the motor pins and stopping the
 * motor at the beginning.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, PIN_OUTPUT);
	//GPIO_setupPinDirection(MOTOR_E_PORT_ID, MOTOR_E_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);

	duty_cycle(0);
}

/*
 * Description :
 * Function responsible for Controls the motor's state (Clockwise/Anti-Clockwise/Stop) .
 * adjusts the speed based on the input duty cycle.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	if(state==CW) //clockwise
	{
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	}
	else if(state==A_CW) //anti_clockwise
	{
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_HIGH);
	}
	else if(state==STOP) //stop
	{
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	}
	duty_cycle(speed);
}

/*
 * Description :
 * Automatic Fan Speed Control:
 * Fan speed is automatically adjusted based on room temperature controlled by a PWM signal.
 * The fan operates at different speeds based on temperature ranges:
 * Temperature ≥ 40°C: Fan ON at 100% speed.
 * Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
 * Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
 * Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
 * Temperature < 25°C: Fan OFF.
 */
void Automatic_Fan_Speed_Control(DcMotor_State state, uint8 Temperature)
{
	LCD_moveCursor(1,5);
	LCD_intgerToString(Temperature);

	if(Temperature>=40)
    {
		DcMotor_Rotate(state, 100);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
    }
	else if((Temperature>=35) && (Temperature<40))
	{
		DcMotor_Rotate(state, 75);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
	}
	else if((Temperature>=30) && (Temperature<35))
	{
		DcMotor_Rotate(state, 50);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
	}
	else if((Temperature>=25) && (Temperature<30))
	{
		DcMotor_Rotate(state, 25);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
	}
	else
	{
		DcMotor_Rotate(state, 0);
		LCD_moveCursor(0,11);
		LCD_displayString("OFF");
	}
}
