################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.c 

OBJS += \
./Drivers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.o 

C_DEPS += \
./Drivers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/Source/BasicMathFunctions/%.o: ../Drivers/CMSIS/DSP/Source/BasicMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -DUSE_HAL_DRIVER -DSTM32F429xx -I"E:/AI_test_01/Inc" -I"E:/AI_test_01/Middlewares/ST/AI/AI/include" -I"E:/AI_test_01/Middlewares/ST/AI/AI/data" -I"E:/AI_test_01/Drivers/CMSIS/DSP/Include" -I"E:/AI_test_01/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/AI_test_01/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"E:/AI_test_01/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/AI_test_01/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


