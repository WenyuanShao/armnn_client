################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CMSIS_5/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.c 

OBJS += \
./src/CMSIS_5/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.o 

C_DEPS += \
./src/CMSIS_5/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.d 


# Each subdirectory must supply rules for building sources it contributes
src/CMSIS_5/CMSIS/DSP/Source/TransformFunctions/%.o: ../src/CMSIS_5/CMSIS/DSP/Source/TransformFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c99 -DARM_MATH_CM3 -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/DSP/Include -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/Core/Include -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/NN/Include -O3 -g3 -Wall -c -fmessage-length=0 -Wno-unused-function -Wno-unused-variable -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


