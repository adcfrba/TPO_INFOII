################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/CORE_LPC84x/aeabi_romdiv_patch.s 

C_SRCS += \
../src/CORE_LPC84x/cr_startup_lpc84x.c \
../src/CORE_LPC84x/crp.c \
../src/CORE_LPC84x/mtb.c 

OBJS += \
./src/CORE_LPC84x/aeabi_romdiv_patch.o \
./src/CORE_LPC84x/cr_startup_lpc84x.o \
./src/CORE_LPC84x/crp.o \
./src/CORE_LPC84x/mtb.o 

C_DEPS += \
./src/CORE_LPC84x/cr_startup_lpc84x.d \
./src/CORE_LPC84x/crp.d \
./src/CORE_LPC84x/mtb.d 


# Each subdirectory must supply rules for building sources it contributes
src/CORE_LPC84x/%.o: ../src/CORE_LPC84x/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -g3 -mcpu=cortex-m0 -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/CORE_LPC84x/%.o: ../src/CORE_LPC84x/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC84X__ -D__REDLIB__ -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_GPIO" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_TECLADO" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_LCD16X2" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_ADC" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_DISPLAY_7SEG" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_UART" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\DRIVER_TIMER" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src\CORE_LPC84x" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_KITFACU_UART_ADC_DAC_LCD\src" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


