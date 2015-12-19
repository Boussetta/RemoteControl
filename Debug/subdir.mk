################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../remote.c 

OBJS += \
./remote.o 

C_DEPS += \
./remote.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"C:\Users\Wissem\workspace\Remote Control" -I"C:\Users\Wissem\workspace\Remote Control\writer task" -I"C:\Users\Wissem\workspace\Remote Control\reader task" -I"C:\Users\Wissem\workspace\Remote Control\shell task" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


