#include "common_macros.h" /* For GET_BIT Macro */
#include "ldr.h"
#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for  Reads the LDR sensor value.
 * Then returns the light intensity.
 */
 uint16 LDR_getLightIntensity(void)
 {
	 uint8 Light_Intensity = 0;

	 uint16 adc_value = 0;

	 /* Read ADC channel where the LDR sensor is connected */
	 adc_value = ADC_readChannel(LDR_CHANNEL_ID );

	 /* Calculate the Light Intensity from the ADC value*/
	 Light_Intensity= (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

 	return Light_Intensity;
 }
