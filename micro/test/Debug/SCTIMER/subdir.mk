################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SCTIMER/sctimer.c 

C_DEPS += \
./SCTIMER/sctimer.d 

OBJS += \
./SCTIMER/sctimer.o 


# Each subdirectory must supply rules for building sources it contributes
SCTIMER/%.o: ../SCTIMER/%.c SCTIMER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\SCTIMER" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\CTIMER" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\Drivers" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\GPIO" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\IO" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\LCD" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\src" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\Teclado" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\Timers" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\UART" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\I2C" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-SCTIMER

clean-SCTIMER:
	-$(RM) ./SCTIMER/sctimer.d ./SCTIMER/sctimer.o

.PHONY: clean-SCTIMER

