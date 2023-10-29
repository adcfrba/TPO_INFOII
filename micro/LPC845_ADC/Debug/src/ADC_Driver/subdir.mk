################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ADC_Driver/ADC.cpp 

CPP_DEPS += \
./src/ADC_Driver/ADC.d 

OBJS += \
./src/ADC_Driver/ADC.o 


# Each subdirectory must supply rules for building sources it contributes
src/ADC_Driver/%.o: ../src/ADC_Driver/%.cpp src/ADC_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\inc" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\UART0_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\ADC_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\TECLADO_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\UTILS\CALLBACK" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\GPIOF_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\TIMERSW_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\SYSTICK_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\GPIO_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-ADC_Driver

clean-src-2f-ADC_Driver:
	-$(RM) ./src/ADC_Driver/ADC.d ./src/ADC_Driver/ADC.o

.PHONY: clean-src-2f-ADC_Driver

