################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GPIOF_Driver/GPIOF.cpp 

CPP_DEPS += \
./src/GPIOF_Driver/GPIOF.d 

OBJS += \
./src/GPIOF_Driver/GPIOF.o 


# Each subdirectory must supply rules for building sources it contributes
src/GPIOF_Driver/%.o: ../src/GPIOF_Driver/%.cpp src/GPIOF_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\UART0_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\MAX30102_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\GPIOF_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\I2C_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\ADC_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\SYSTICK_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\LCD_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\UTILS\CALLBACK" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\inc" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\GPIO_Driver" -I"C:\Users\notebook\Downloads\LPC845_HORNO\LPC845_HORNO\src\TIMERSW_Driver" -Og -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-GPIOF_Driver

clean-src-2f-GPIOF_Driver:
	-$(RM) ./src/GPIOF_Driver/GPIOF.d ./src/GPIOF_Driver/GPIOF.o

.PHONY: clean-src-2f-GPIOF_Driver

