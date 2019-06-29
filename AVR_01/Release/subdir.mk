################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADCINT_prog.c \
../ADC_prog.c \
../DIO_prog.c \
../EXTINT0_prog.c \
../EXTINT1_prog.c \
../EXTINT2_prog.c \
../GIE_prog.c \
../I2C_prog.c \
../LCD_prog.c \
../LED_prog.c \
../SEVENSEG_prog.c \
../SPIINT_prog.c \
../SPI_prog.c \
../SWITCH_prog.c \
../TIM0_prog.c \
../UARTINT_prog.c \
../UART_prog.c \
../main.c 

OBJS += \
./ADCINT_prog.o \
./ADC_prog.o \
./DIO_prog.o \
./EXTINT0_prog.o \
./EXTINT1_prog.o \
./EXTINT2_prog.o \
./GIE_prog.o \
./I2C_prog.o \
./LCD_prog.o \
./LED_prog.o \
./SEVENSEG_prog.o \
./SPIINT_prog.o \
./SPI_prog.o \
./SWITCH_prog.o \
./TIM0_prog.o \
./UARTINT_prog.o \
./UART_prog.o \
./main.o 

C_DEPS += \
./ADCINT_prog.d \
./ADC_prog.d \
./DIO_prog.d \
./EXTINT0_prog.d \
./EXTINT1_prog.d \
./EXTINT2_prog.d \
./GIE_prog.d \
./I2C_prog.d \
./LCD_prog.d \
./LED_prog.d \
./SEVENSEG_prog.d \
./SPIINT_prog.d \
./SPI_prog.d \
./SWITCH_prog.d \
./TIM0_prog.d \
./UARTINT_prog.d \
./UART_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


