################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAR/har_Postprocessing.c \
../Src/HAR/har_Preprocessing.c \
../Src/HAR/har_Processing.c \
../Src/HAR/har_ProcessingTest.c 

OBJS += \
./Src/HAR/har_Postprocessing.o \
./Src/HAR/har_Preprocessing.o \
./Src/HAR/har_Processing.o \
./Src/HAR/har_ProcessingTest.o 

C_DEPS += \
./Src/HAR/har_Postprocessing.d \
./Src/HAR/har_Preprocessing.d \
./Src/HAR/har_Processing.d \
./Src/HAR/har_ProcessingTest.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAR/%.o: ../Src/HAR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -DUSE_HAL_DRIVER -DSTM32F429xx -I"E:/AI_test_01/Inc" -I"E:/AI_test_01/Middlewares/ST/AI/AI/include" -I"E:/AI_test_01/Middlewares/ST/AI/AI/data" -I"E:/AI_test_01/Drivers/CMSIS/DSP/Include" -I"E:/AI_test_01/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/AI_test_01/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"E:/AI_test_01/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/AI_test_01/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


