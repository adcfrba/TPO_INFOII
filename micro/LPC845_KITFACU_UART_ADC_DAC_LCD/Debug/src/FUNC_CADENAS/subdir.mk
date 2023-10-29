################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FUNC_CADENAS/Cadenas.c 

OBJS += \
./src/FUNC_CADENAS/Cadenas.o 

C_DEPS += \
./src/FUNC_CADENAS/Cadenas.d 


# Each subdirectory must supply rules for building sources it contributes
src/FUNC_CADENAS/%.o: ../src/FUNC_CADENAS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC84X__ -D__REDLIB__ -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\DRIVER_GPIO" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\DRIVER_TECLADO" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\DRIVER_LCD16X2" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\DRIVER_ADC" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\DRIVER_DISPLAY_7SEG" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\FUNC_CADENAS" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\DRIVER_UART" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\DRIVER_TIMER" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src\CORE_LPC84x" -I"C:\Users\GJF-Trabajo\Dropbox\Proyectos\LPC845\Inicio\src" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


