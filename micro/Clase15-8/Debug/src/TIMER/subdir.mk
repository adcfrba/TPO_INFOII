################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TIMER/SYSTICK.c 

OBJS += \
./src/TIMER/SYSTICK.o 

C_DEPS += \
./src/TIMER/SYSTICK.d 


# Each subdirectory must supply rules for building sources it contributes
src/TIMER/%.o: ../src/TIMER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\Gustavo\Dropbox\Facultad\LPC845 CL2020\LPC845_SysTick\inc" -I"C:\Users\Gustavo\Dropbox\Facultad\LPC845 CL2020\LPC845_SysTick\src\TIMER" -I"C:\Users\Gustavo\Dropbox\Facultad\LPC845 CL2020\LPC845_SysTick\src\GPIO" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


