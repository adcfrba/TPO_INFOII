################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc84x.c \
../src/crp.c \
../src/main.c \
../src/mtb.c 

S_SRCS += \
../src/aeabi_romdiv_patch.s 

C_DEPS += \
./src/cr_startup_lpc84x.d \
./src/crp.d \
./src/main.d \
./src/mtb.d 

OBJS += \
./src/aeabi_romdiv_patch.o \
./src/cr_startup_lpc84x.o \
./src/crp.o \
./src/main.o \
./src/mtb.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.s src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -g3 -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\SCTIMER" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\CTIMER" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\Drivers" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\GPIO" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\IO" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\LCD" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\src" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\Teclado" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\Timers" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\UART" -I"C:\Users\notebook\Documents\INFO II 2023\TPO\TPO_INFOII\micro\test\I2C" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/aeabi_romdiv_patch.o ./src/cr_startup_lpc84x.d ./src/cr_startup_lpc84x.o ./src/crp.d ./src/crp.o ./src/main.d ./src/main.o ./src/mtb.d ./src/mtb.o

.PHONY: clean-src

