################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MAX30102/SpO2Calculator.cpp \
../src/MAX30102/max30102.cpp 

CPP_DEPS += \
./src/MAX30102/SpO2Calculator.d \
./src/MAX30102/max30102.d 

OBJS += \
./src/MAX30102/SpO2Calculator.o \
./src/MAX30102/max30102.o 


# Each subdirectory must supply rules for building sources it contributes
src/MAX30102/%.o: ../src/MAX30102/%.cpp src/MAX30102/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\I2C_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\GPIOLCD_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\LCD_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\inc" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\MAX30102" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\ADC_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\UART0_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\UTILS\CALLBACK" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\GPIOF_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\TIMERSW_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\SYSTICK_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\MICROMCU\LPC845_TPO\src\GPIO_Driver" -Os -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-MAX30102

clean-src-2f-MAX30102:
	-$(RM) ./src/MAX30102/SpO2Calculator.d ./src/MAX30102/SpO2Calculator.o ./src/MAX30102/max30102.d ./src/MAX30102/max30102.o

.PHONY: clean-src-2f-MAX30102

