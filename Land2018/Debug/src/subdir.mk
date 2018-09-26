################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GPIO.cpp \
../src/Land2018.cpp \
../src/encoder.cpp \
../src/heater.cpp \
../src/max11100_ADC.cpp \
../src/pthreads.cpp \
../src/pwm.cpp \
../src/util.cpp 

OBJS += \
./src/GPIO.o \
./src/Land2018.o \
./src/encoder.o \
./src/heater.o \
./src/max11100_ADC.o \
./src/pthreads.o \
./src/pwm.o \
./src/util.o 

CPP_DEPS += \
./src/GPIO.d \
./src/Land2018.d \
./src/encoder.d \
./src/heater.d \
./src/max11100_ADC.d \
./src/pthreads.d \
./src/pwm.d \
./src/util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


