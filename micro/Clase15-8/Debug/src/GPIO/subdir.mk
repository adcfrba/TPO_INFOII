################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO/GPIO.c 

C_DEPS += \
./src/GPIO/GPIO.d 

OBJS += \
./src/GPIO/GPIO.o 


# Each subdirectory must supply rules for building sources it contributes
src/GPIO/%.o: ../src/GPIO/%.c src/GPIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\Clase15-8\src\SYSTICK" -I"C:\Users\notebook\Documents\INFO II 2023\micro\Clase15-8\inc" -I"C:\Users\notebook\Documents\INFO II 2023\micro\Clase15-8\src\GPIO" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-GPIO

clean-src-2f-GPIO:
	-$(RM) ./src/GPIO/GPIO.d ./src/GPIO/GPIO.o

.PHONY: clean-src-2f-GPIO

