################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/arm_signal_converge_data.c \
../src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/arm_signal_converge_example_f32.c \
../src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/math_helper.c 

OBJS += \
./src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/arm_signal_converge_data.o \
./src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/arm_signal_converge_example_f32.o \
./src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/math_helper.o 

C_DEPS += \
./src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/arm_signal_converge_data.d \
./src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/arm_signal_converge_example_f32.d \
./src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/math_helper.d 


# Each subdirectory must supply rules for building sources it contributes
src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/%.o: ../src/CMSIS_5/CMSIS/DSP/Examples/ARM/arm_signal_converge_example/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c99 -DARM_MATH_CM7 -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/DSP/Include -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/Core/Include -I/users/graceliu/armnn_expr/NN/src/CMSIS_5/CMSIS/NN/Include -O0 -g3 -Wall -c -fmessage-length=0 -Wno-unused-function -Wno-unused-variable -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


