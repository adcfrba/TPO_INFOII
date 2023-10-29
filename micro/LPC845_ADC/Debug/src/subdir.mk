################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cr_cpp_config.cpp \
../src/cr_startup_lpc84x.cpp \
../src/mainADC.cpp 

C_SRCS += \
../src/crp.c \
../src/mtb.c 

S_SRCS += \
../src/aeabi_romdiv_patch.s 

CPP_DEPS += \
./src/cr_cpp_config.d \
./src/cr_startup_lpc84x.d \
./src/mainADC.d 

C_DEPS += \
./src/crp.d \
./src/mtb.d 

OBJS += \
./src/aeabi_romdiv_patch.o \
./src/cr_cpp_config.o \
./src/cr_startup_lpc84x.o \
./src/crp.o \
./src/mainADC.o \
./src/mtb.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.s src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -g3 -mcpu=cortex-m0 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\inc" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\UART0_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\ADC_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\TECLADO_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\UTILS\CALLBACK" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\GPIOF_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\TIMERSW_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\SYSTICK_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\GPIO_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\inc" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\UTILS" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\SYSTICK_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\TECLADO_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\TIMERSW_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\GPIO_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\GPIOF_Driver" -I"C:\Users\notebook\Documents\INFO II 2023\micro\LPC845_ADC\src\UART0_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/aeabi_romdiv_patch.o ./src/cr_cpp_config.d ./src/cr_cpp_config.o ./src/cr_startup_lpc84x.d ./src/cr_startup_lpc84x.o ./src/crp.d ./src/crp.o ./src/mainADC.d ./src/mainADC.o ./src/mtb.d ./src/mtb.o

.PHONY: clean-src

