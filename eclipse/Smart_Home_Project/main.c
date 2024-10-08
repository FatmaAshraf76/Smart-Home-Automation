#include "lcd.h"
#include "lm35_sensor.h"
#include "buzzer.h"
#include "flame_sensor.h"
#include "leds.h"
#include "ldr.h"
#include "adc.h"
#include "pwm.h"
#include "motor.h"

int main(void)
{
	uint8 Temperature;
	uint8 Intensity;
	uint8 Fire;

	DcMotor_State state =CW;

	PWM_Timer0_Start();
	ADC_init();
	LCD_init();
	DcMotor_Init();
	Buzzer_init();
	FlameSensor_init();
	LEDS_init();

	LCD_moveCursor(0,4);
	LCD_displayString("FAN IS ");
	LCD_moveCursor(1,0); /* Move the cursor to the second row */
	LCD_displayString("TEMP=   LDR=   %");
	while(1)
	{
		Temperature=LM35_getTemperature();
		Intensity=LDR_getLightIntensity();
		Fire=FlameSensor_getValue();
        if(Fire)
        {
        	FlameSensor(Fire);
        }
        else
        {
    		Automatic_Fan_Speed_Control(state , Temperature);
    		Automatic_Lighting_Control(Intensity);
    		FlameSensor(Fire);
        }
	}
}

