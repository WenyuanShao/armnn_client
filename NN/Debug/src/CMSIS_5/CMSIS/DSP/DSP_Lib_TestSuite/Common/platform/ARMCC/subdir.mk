################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CMSIS_5/CMSIS/DSP/DSP_Lib_TestSuite/Common/platform/ARMCC/Retarget.c 

OBJS += \
./src/CMSIS_5/CMSIS/DSP/DSP_Lib_TestSuite/Common/platform/ARMCC/Retarget.o 

C_DEPS += \
./src/CMSIS_5/CMSIS/DSP/DSP_Lib_TestSuite/Common/platform/ARMCC/Retarget.d 


# Each subdirectory must supply rules for building sources it contributes
src/CMSIS_5/CMSIS/DSP/DSP_Lib_TestSuite/Common/platform/ARMCC/%.o: ../src/CMSIS_5/CMSIS/DSP/DSP_Lib_TestSuite/Common/platform/ARMCC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c99 -DARM_MATH_CM7 -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/DSP/Include -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/Core/Include -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/NN/Include -O0 -g3 -Wall -c -fmessage-length=0 -Wno-unused-function -Wno-unused-variable -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


