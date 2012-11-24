################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/maploader/TMXLoader.cpp \
../src/maploader/base64.cpp 

OBJS += \
./src/maploader/TMXLoader.o \
./src/maploader/base64.o 

CPP_DEPS += \
./src/maploader/TMXLoader.d \
./src/maploader/base64.d 


# Each subdirectory must supply rules for building sources it contributes
src/maploader/%.o: ../src/maploader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"../include" -I../include/sdl -I"../include/maploader" -I"../include/tinyxml" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


