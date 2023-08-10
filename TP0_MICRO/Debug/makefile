################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/GPIO/subdir.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := TP0_MICRO
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: TP0_MICRO.axf

# Tool invocations
TP0_MICRO.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="TP0_MICRO.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "TP0_MICRO_Debug.ld" -o "TP0_MICRO.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) TP0_MICRO.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "TP0_MICRO.axf"; # arm-none-eabi-objcopy -v -O binary "TP0_MICRO.axf" "TP0_MICRO.bin" ; # checksum -p LPC845 -d "TP0_MICRO.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
