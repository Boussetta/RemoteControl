################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../reader\ task/reader.c 

OBJS += \
./reader\ task/reader.o 

C_DEPS += \
./reader\ task/reader.d 


# Each subdirectory must supply rules for building sources it contributes
reader\ task/reader.o: ../reader\ task/reader.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"C:\Users\Wissem\workspace\Remote Control" -I"C:\Users\Wissem\workspace\Remote Control\writer task" -I"C:\Users\Wissem\workspace\Remote Control\reader task" -I"C:\Users\Wissem\workspace\Remote Control\shell task" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"reader task/reader.d" -MT"reader\ task/reader.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


