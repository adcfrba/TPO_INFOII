################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TIMERMAX_Driver/timers.c 

C_DEPS += \
./src/TIMERMAX_Driver/timers.d 

OBJS += \
./src/TIMERMAX_Driver/timers.o 


# Each subdirectory must supply rules for building sources it contributes
src/TIMERMAX_Driver/%.o: ../src/TIMERMAX_Driver/%.c src/TIMERMAX_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\TIMERMAX_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\inc" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\I2C_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\CTIMER" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\IO" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\MAX30102" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\ADC_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\UTILS" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\SYSTICK_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\TECLADO_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\TIMERSW_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\GPIO_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\GPIOF_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\LPC845_TPO\src\UART0_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-TIMERMAX_Driver

clean-src-2f-TIMERMAX_Driver:
	-$(RM) ./src/TIMERMAX_Driver/timers.d ./src/TIMERMAX_Driver/timers.o

.PHONY: clean-src-2f-TIMERMAX_Driver

