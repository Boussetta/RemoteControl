################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../writer\ task/writer.c 

OBJS += \
./writer\ task/writer.o 

C_DEPS += \
./writer\ task/writer.d 


# Each subdirectory must supply rules for building sources it contributes
writer\ task/writer.o: ../writer\ task/writer.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"C:\Users\Wissem\workspace\Remote Control" -I"C:\Users\Wissem\workspace\Remote Control\writer task" -I"C:\Users\Wissem\workspace\Remote Control\reader task" -I"C:\Users\Wissem\workspace\Remote Control\shell task" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"writer task/writer.d" -MT"writer\ task/writer.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


