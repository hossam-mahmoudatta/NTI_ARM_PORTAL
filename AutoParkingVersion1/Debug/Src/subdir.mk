################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DELAY_PROG.c \
../Src/GPIO.c \
../Src/MOTOR_program.c \
../Src/NVIC_PROG.c \
../Src/RCC_PROG.c \
../Src/SYSTICK_PROG.c \
../Src/TIMER2_program.c \
../Src/TIMER3_program.c \
../Src/TIMER_program.c \
../Src/USART_PROG.c \
../Src/lcd.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/ultrasonic.c 

OBJS += \
./Src/DELAY_PROG.o \
./Src/GPIO.o \
./Src/MOTOR_program.o \
./Src/NVIC_PROG.o \
./Src/RCC_PROG.o \
./Src/SYSTICK_PROG.o \
./Src/TIMER2_program.o \
./Src/TIMER3_program.o \
./Src/TIMER_program.o \
./Src/USART_PROG.o \
./Src/lcd.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/ultrasonic.o 

C_DEPS += \
./Src/DELAY_PROG.d \
./Src/GPIO.d \
./Src/MOTOR_program.d \
./Src/NVIC_PROG.d \
./Src/RCC_PROG.d \
./Src/SYSTICK_PROG.d \
./Src/TIMER2_program.d \
./Src/TIMER3_program.d \
./Src/TIMER_program.d \
./Src/USART_PROG.d \
./Src/lcd.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DELAY_PROG.cyclo ./Src/DELAY_PROG.d ./Src/DELAY_PROG.o ./Src/DELAY_PROG.su ./Src/GPIO.cyclo ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/MOTOR_program.cyclo ./Src/MOTOR_program.d ./Src/MOTOR_program.o ./Src/MOTOR_program.su ./Src/NVIC_PROG.cyclo ./Src/NVIC_PROG.d ./Src/NVIC_PROG.o ./Src/NVIC_PROG.su ./Src/RCC_PROG.cyclo ./Src/RCC_PROG.d ./Src/RCC_PROG.o ./Src/RCC_PROG.su ./Src/SYSTICK_PROG.cyclo ./Src/SYSTICK_PROG.d ./Src/SYSTICK_PROG.o ./Src/SYSTICK_PROG.su ./Src/TIMER2_program.cyclo ./Src/TIMER2_program.d ./Src/TIMER2_program.o ./Src/TIMER2_program.su ./Src/TIMER3_program.cyclo ./Src/TIMER3_program.d ./Src/TIMER3_program.o ./Src/TIMER3_program.su ./Src/TIMER_program.cyclo ./Src/TIMER_program.d ./Src/TIMER_program.o ./Src/TIMER_program.su ./Src/USART_PROG.cyclo ./Src/USART_PROG.d ./Src/USART_PROG.o ./Src/USART_PROG.su ./Src/lcd.cyclo ./Src/lcd.d ./Src/lcd.o ./Src/lcd.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/ultrasonic.cyclo ./Src/ultrasonic.d ./Src/ultrasonic.o ./Src/ultrasonic.su

.PHONY: clean-Src

