################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../shell\ task/shell.c 

OBJS += \
./shell\ task/shell.o 

C_DEPS += \
./shell\ task/shell.d 


# Each subdirectory must supply rules for building sources it contributes
shell\ task/shell.o: ../shell\ task/shell.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"C:\Users\Wissem\workspace\Remote Control" -I"C:\Users\Wissem\workspace\Remote Control\writer task" -I"C:\Users\Wissem\workspace\Remote Control\reader task" -I"C:\Users\Wissem\workspace\Remote Control\shell task" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"shell task/shell.d" -MT"shell\ task/shell.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


