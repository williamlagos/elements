################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CFont.cpp \
../src/CGame.cpp \
../src/CImage.cpp \
../src/CMultiImage.cpp \
../src/CSprite.cpp \
../src/MenuState.cpp \
../src/PauseState.cpp \
../src/PlayState.cpp \
../src/TextureManager.cpp \
../src/main.cpp 

OBJS += \
./src/CFont.o \
./src/CGame.o \
./src/CImage.o \
./src/CMultiImage.o \
./src/CSprite.o \
./src/MenuState.o \
./src/PauseState.o \
./src/PlayState.o \
./src/TextureManager.o \
./src/main.o 

CPP_DEPS += \
./src/CFont.d \
./src/CGame.d \
./src/CImage.d \
./src/CMultiImage.d \
./src/CSprite.d \
./src/MenuState.d \
./src/PauseState.d \
./src/PlayState.d \
./src/TextureManager.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"../include" -I"../include/maploader" -I"../include/tinyxml" -I/usr/include/SDL -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


