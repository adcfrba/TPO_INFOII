################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SYSTICK/systick.cpp 

CPP_DEPS += \
./src/SYSTICK/systick.d 

OBJS += \
./src/SYSTICK/systick.o 


# Each subdirectory must supply rules for building sources it contributes
src/SYSTICK/%.o: ../src/SYSTICK/%.cpp src/SYSTICK/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\clase15-08\inc" -I"C:\Users\notebook\Documents\INFO II 2023\micro\clase15-08\src\GPIO" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-SYSTICK

clean-src-2f-SYSTICK:
	-$(RM) ./src/SYSTICK/systick.d ./src/SYSTICK/systick.o

.PHONY: clean-src-2f-SYSTICK

