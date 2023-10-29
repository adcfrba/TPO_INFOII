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
	arm-none-eabi-gcc -c -x assembler-with-cpp -DNDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -mcpu=cortex-m0 -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/CORE_LPC84x/%.o: ../src/CORE_LPC84x/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC84X__ -D__REDLIB__ -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


