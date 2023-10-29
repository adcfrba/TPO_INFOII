################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DRIVER_UART/UART1_Driver.c \
../src/DRIVER_UART/UART_SW_Driver.c 

OBJS += \
./src/DRIVER_UART/UART1_Driver.o \
./src/DRIVER_UART/UART_SW_Driver.o 

C_DEPS += \
./src/DRIVER_UART/UART1_Driver.d \
./src/DRIVER_UART/UART_SW_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
src/DRIVER_UART/%.o: ../src/DRIVER_UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC84X__ -D__REDLIB__ -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


