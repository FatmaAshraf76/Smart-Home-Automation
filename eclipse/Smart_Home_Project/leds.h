#ifndef LEDS_H_
#define LEDS_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*  Positive Logic and Negative Logic mode configuration.
 *  if value = 1 -->Positive Logic
 *  if value = 0 -->Negative Logic
 *  */
#define LOGIC_MODE 1

/* LEDS HW Ports and Pins Ids */
#define RED_LED_PORT_ID                 PORTB_ID
#define RED_LED_PIN_ID                  PIN5_ID

#define GREEN_LED_PORT_ID               PORTB_ID
#define GREEN_LED_PIN_ID                PIN6_ID

#define BLUE_LED_PORT_ID                PORTB_ID
#define BLUE_LED_PIN_ID                 PIN7_ID

#if(LOGIC_MODE == 1)
   #define LED_ON                      LOGIC_HIGH
   #define LED_OFF                     LOGIC_LOW
#elif(LOGIC_MODE == 0)
   #define LED_ON                      LOHIC_LOW
   #define LED_OFF                     LOGIC_HIGH
#endif

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	RED,GREEN,BLUE
}LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for Initializes all Leds (red, green, blue) pins direction.
 * Turn off all the Leds.
 */
 void LEDS_init(void);

 /*
  * Description :
  * Function responsible for Turns on the specified LED.
  */
 void LED_on(LED_ID id);

 /*
   * Description :
   * Function responsible for  Turns off the specified LED.
   */
 void LED_off(LED_ID id);

 /*
     * Description :
     * Automatic Lighting Control: Based on the LDR readings
     * the system controls three LEDs according to light intensity thresholds.
     */
 void Automatic_Lighting_Control(uint8 Intensity);


#endif /* LEDS_H_ */
