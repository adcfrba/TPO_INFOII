################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TIMERSW_Driver/TIMERSW.cpp 

CPP_DEPS += \
./src/TIMERSW_Driver/TIMERSW.d 

OBJS += \
./src/TIMERSW_Driver/TIMERSW.o 


# Each subdirectory must supply rules for building sources it contributes
src/TIMERSW_Driver/%.o: ../src/TIMERSW_Driver/%.cpp src/TIMERSW_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_CPP_R2052_ANTIREBOTE_TECLADO\inc" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_CPP_R2052_ANTIREBOTE_TECLADO\src\TECLADO_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_CPP_R2052_ANTIREBOTE_TECLADO\src\UTILS\CALLBACK" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_CPP_R2052_ANTIREBOTE_TECLADO\src\GPIOF_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_CPP_R2052_ANTIREBOTE_TECLADO\src\TIMERSW_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_CPP_R2052_ANTIREBOTE_TECLADO\src\SYSTICK_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_CPP_R2052_ANTIREBOTE_TECLADO\src\GPIO_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-TIMERSW_Driver

clean-src-2f-TIMERSW_Driver:
	-$(RM) ./src/TIMERSW_Driver/TIMERSW.d ./src/TIMERSW_Driver/TIMERSW.o

.PHONY: clean-src-2f-TIMERSW_Driver

