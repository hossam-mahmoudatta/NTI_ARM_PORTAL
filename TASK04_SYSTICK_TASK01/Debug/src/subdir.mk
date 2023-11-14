################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO_PROGRAM.c \
../src/RCC_PROGRAM.c \
../src/SYSTICK_PROGRAM.c \
../src/main.c \
../src/syscalls.c \
../src/sysmem.c 

OBJS += \
./src/GPIO_PROGRAM.o \
./src/RCC_PROGRAM.o \
./src/SYSTICK_PROGRAM.o \
./src/main.o \
./src/syscalls.o \
./src/sysmem.o 

C_DEPS += \
./src/GPIO_PROGRAM.d \
./src/RCC_PROGRAM.d \
./src/SYSTICK_PROGRAM.d \
./src/main.d \
./src/syscalls.d \
./src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/GPIO_PROGRAM.cyclo ./src/GPIO_PROGRAM.d ./src/GPIO_PROGRAM.o ./src/GPIO_PROGRAM.su ./src/RCC_PROGRAM.cyclo ./src/RCC_PROGRAM.d ./src/RCC_PROGRAM.o ./src/RCC_PROGRAM.su ./src/SYSTICK_PROGRAM.cyclo ./src/SYSTICK_PROGRAM.d ./src/SYSTICK_PROGRAM.o ./src/SYSTICK_PROGRAM.su ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su ./src/syscalls.cyclo ./src/syscalls.d ./src/syscalls.o ./src/syscalls.su ./src/sysmem.cyclo ./src/sysmem.d ./src/sysmem.o ./src/sysmem.su

.PHONY: clean-src

