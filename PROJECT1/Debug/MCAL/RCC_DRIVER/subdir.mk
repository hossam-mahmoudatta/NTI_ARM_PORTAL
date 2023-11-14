################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC_DRIVER/RCC_PROGRAM.c 

OBJS += \
./MCAL/RCC_DRIVER/RCC_PROGRAM.o 

C_DEPS += \
./MCAL/RCC_DRIVER/RCC_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC_DRIVER/%.o MCAL/RCC_DRIVER/%.su MCAL/RCC_DRIVER/%.cyclo: ../MCAL/RCC_DRIVER/%.c MCAL/RCC_DRIVER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F100xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-RCC_DRIVER

clean-MCAL-2f-RCC_DRIVER:
	-$(RM) ./MCAL/RCC_DRIVER/RCC_PROGRAM.cyclo ./MCAL/RCC_DRIVER/RCC_PROGRAM.d ./MCAL/RCC_DRIVER/RCC_PROGRAM.o ./MCAL/RCC_DRIVER/RCC_PROGRAM.su

.PHONY: clean-MCAL-2f-RCC_DRIVER

