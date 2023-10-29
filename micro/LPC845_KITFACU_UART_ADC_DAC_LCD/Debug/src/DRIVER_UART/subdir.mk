################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DRIVER_UART/UART1_Driver.c 

OBJS += \
./src/DRIVER_UART/UART1_Driver.o 

C_DEPS += \
./src/DRIVER_UART/UART1_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
src/DRIVER_UART/%.o: ../src/DRIVER_UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC84X__ -D__REDLIB__ -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_GPIO" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_TECLADO" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_LCD16X2" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_ADC" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_DISPLAY_7SEG" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_UART" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_TIMER" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\CORE_LPC84x" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


