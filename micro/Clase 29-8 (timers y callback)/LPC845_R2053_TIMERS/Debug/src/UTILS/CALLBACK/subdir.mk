################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/UTILS/CALLBACK/CALLBACK.cpp 

OBJS += \
./src/UTILS/CALLBACK/CALLBACK.o 

CPP_DEPS += \
./src/UTILS/CALLBACK/CALLBACK.d 


# Each subdirectory must supply rules for building sources it contributes
src/UTILS/CALLBACK/%.o: ../src/UTILS/CALLBACK/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_R2053_TIMERS\inc" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_R2053_TIMERS\src\UTILS\CALLBACK" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_R2053_TIMERS\src\TIMERSW_Driver" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_R2053_TIMERS\src\SYSTICK_Driver" -I"C:\Users\gusta\Dropbox\Facultad\LPC845 CL2020\LPC845_R2053_TIMERS\src\GPIO_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


