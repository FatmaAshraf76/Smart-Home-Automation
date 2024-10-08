################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../buzzer.c \
../flame_sensor.c \
../gpio.c \
../lcd.c \
../ldr.c \
../leds.c \
../lm35_sensor.c \
../main.c \
../motor.c \
../pwm.c 

OBJS += \
./adc.o \
./buzzer.o \
./flame_sensor.o \
./gpio.o \
./lcd.o \
./ldr.o \
./leds.o \
./lm35_sensor.o \
./main.o \
./motor.o \
./pwm.o 

C_DEPS += \
./adc.d \
./buzzer.d \
./flame_sensor.d \
./gpio.d \
./lcd.d \
./ldr.d \
./leds.d \
./lm35_sensor.d \
./main.d \
./motor.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


