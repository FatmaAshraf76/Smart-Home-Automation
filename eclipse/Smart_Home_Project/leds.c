#include "common_macros.h" /* For GET_BIT Macro */
#include "leds.h"
#include "gpio.h"
#include "lcd.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for Initializes all Leds (red, green, blue) pins direction.
 * Turn off all the Leds.
 */
void LEDS_init(void)
{
    GPIO_setupPinDirection(RED_LED_PORT_ID , RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LED_OFF);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LED_OFF);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LED_OFF);
}

/*
 * Description :
 * Function responsible for Turns on the specified LED.
 */
void LED_on(LED_ID id)
{
	if(id==RED)
	{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LED_ON);
	}
	else if(id==GREEN)
	{
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LED_ON);
	}
	else if(id==BLUE)
	{
 		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LED_ON);
	}
}

/*
 * Description :
 * Function responsible for  Turns off the specified LED.
 */
void LED_off(LED_ID id)
{
	if(id==RED)
    {
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LED_OFF);
	}
	else if(id==GREEN)
    {
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LED_OFF);
	}
	else if(id==BLUE)
	{
 		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LED_OFF);
	}
}

/*
 * Description :
 * Automatic Lighting Control: Based on the LDR readings
 * the system controls three LEDs according to light intensity thresholds:
 * Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
 * Intensity 16–50%: Red and Green LEDs turn ON.
 * Intensity 51–70%: Only the Red LED turns ON.
 * Intensity > 70%: All LEDs are turned OFF
 */
void Automatic_Lighting_Control(uint8 Intensity)
{
	if((Intensity<100) &&(Intensity>=10))
	{
		LCD_moveCursor(1,14);
		LCD_displayString(" ");
	}
	else if(Intensity<10)
	{
		LCD_moveCursor(1,13);
		LCD_displayString("  ");
	}
	LCD_moveCursor(1,12);
	LCD_intgerToString(Intensity);
	if(Intensity<=15)
    {
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LED_ON);
	    GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LED_ON);
	    GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LED_ON);
    }
	else if((Intensity>=16) && (Intensity<=50))
	{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LED_ON);
	    GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LED_ON);
	    GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LED_OFF);
	}
	else if((Intensity>=51) && (Intensity<=70))
	{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LED_ON);
	    GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LED_OFF);
	    GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LED_OFF);
	}
	else
	{
		 GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LED_OFF);
		 GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LED_OFF);
		 GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LED_OFF);
	}
}
