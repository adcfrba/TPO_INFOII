################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SYSTICK/SYSTICK.c 

C_DEPS += \
./src/SYSTICK/SYSTICK.d 

OBJS += \
./src/SYSTICK/SYSTICK.o 


# Each subdirectory must supply rules for building sources it contributes
src/SYSTICK/%.o: ../src/SYSTICK/%.c src/SYSTICK/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\Clase15-8\src\SYSTICK" -I"C:\Users\notebook\Documents\INFO II 2023\micro\Clase15-8\inc" -I"C:\Users\notebook\Documents\INFO II 2023\micro\Clase15-8\src\GPIO" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-SYSTICK

clean-src-2f-SYSTICK:
	-$(RM) ./src/SYSTICK/SYSTICK.d ./src/SYSTICK/SYSTICK.o

.PHONY: clean-src-2f-SYSTICK

