################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Inicio.c 

OBJS += \
./src/Inicio.o 

C_DEPS += \
./src/Inicio.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC84X__ -D__REDLIB__ -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


