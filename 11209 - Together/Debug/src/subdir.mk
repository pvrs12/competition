################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/11209\ -\ Together.cpp 

OBJS += \
./src/11209\ -\ Together.o 

CPP_DEPS += \
./src/11209\ -\ Together.d 


# Each subdirectory must supply rules for building sources it contributes
src/11209\ -\ Together.o: ../src/11209\ -\ Together.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/11209 - Together.d" -MT"src/11209\ -\ Together.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


