################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GPIO_Driver/GPIO.cpp 

OBJS += \
./src/GPIO_Driver/GPIO.o 

CPP_DEPS += \
./src/GPIO_Driver/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
src/GPIO_Driver/%.o: ../src/GPIO_Driver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_CPP_R2052\inc" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_CPP_R2052\src\UTILS\CALLBACK" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_CPP_R2052\src\TIMERSW_Driver" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_CPP_R2052\src\SYSTICK_Driver" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_CPP_R2052\src\GPIO_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


