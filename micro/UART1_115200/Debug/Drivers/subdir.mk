################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/dr_pll.c \
../Drivers/dr_systick.c 

C_DEPS += \
./Drivers/dr_pll.d \
./Drivers/dr_systick.d 

OBJS += \
./Drivers/dr_pll.o \
./Drivers/dr_systick.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c Drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\notebook\Documents\INFO II 2023\micro\UART1_115200\GPIO" -I"C:\Users\notebook\Documents\INFO II 2023\micro\UART1_115200\src" -I"C:\Users\notebook\Documents\INFO II 2023\micro\UART1_115200\Drivers" -I"C:\Users\notebook\Documents\INFO II 2023\micro\UART1_115200\UART" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers

clean-Drivers:
	-$(RM) ./Drivers/dr_pll.d ./Drivers/dr_pll.o ./Drivers/dr_systick.d ./Drivers/dr_systick.o

.PHONY: clean-Drivers

