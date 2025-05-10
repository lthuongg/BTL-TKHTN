################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Sensor/sensor.c 

OBJS += \
./Core/Sensor/sensor.o 

C_DEPS += \
./Core/Sensor/sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Sensor/%.o Core/Sensor/%.su Core/Sensor/%.cyclo: ../Core/Sensor/%.c Core/Sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/LE TUAN THANH/Desktop/Doan_totnghiep/Firmware/Core/Lora" -I"C:/Users/LE TUAN THANH/Desktop/Doan_totnghiep/Firmware/Core/hdc1080" -I"C:/Users/LE TUAN THANH/Desktop/Doan_totnghiep/Firmware/Core/Sensor" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Sensor

clean-Core-2f-Sensor:
	-$(RM) ./Core/Sensor/sensor.cyclo ./Core/Sensor/sensor.d ./Core/Sensor/sensor.o ./Core/Sensor/sensor.su

.PHONY: clean-Core-2f-Sensor

