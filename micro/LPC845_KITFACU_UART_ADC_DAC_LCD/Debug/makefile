################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/DRIVER_UART/subdir.mk
-include src/DRIVER_TIMER/subdir.mk
-include src/DRIVER_TECLADO/subdir.mk
-include src/DRIVER_LCD16X2/subdir.mk
-include src/DRIVER_GPIO/subdir.mk
-include src/DRIVER_DISPLAY_7SEG/subdir.mk
-include src/DRIVER_ADC/subdir.mk
-include src/CORE_LPC84x/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LPC845_KITFACU_UART_ADC_DAC_LCD.axf

# Tool invocations
LPC845_KITFACU_UART_ADC_DAC_LCD.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="LPC845_KITFACU_UART_ADC_DAC_LCD.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "Inicio_Debug.ld" -o "LPC845_KITFACU_UART_ADC_DAC_LCD.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) LPC845_KITFACU_UART_ADC_DAC_LCD.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "LPC845_KITFACU_UART_ADC_DAC_LCD.axf"; # arm-none-eabi-objcopy -v -O binary "LPC845_KITFACU_UART_ADC_DAC_LCD.axf" "LPC845_KITFACU_UART_ADC_DAC_LCD.bin" ; # checksum -p LPC845 -d "LPC845_KITFACU_UART_ADC_DAC_LCD.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
