################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/AnswerCheckList.c \
../Core/Src/CircuitProcessor.c \
../Core/Src/CircularBuffer.c \
../Core/Src/ExtendedBoard.c \
../Core/Src/ExtendedBoard_PinWork.c \
../Core/Src/Keyboard.c \
../Core/Src/RandomSequenceWithoutRepetitions.c \
../Core/Src/StandProcessor.c \
../Core/Src/StandProcessorLLF.c \
../Core/Src/UART.c \
../Core/Src/dfr0299.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/AnswerCheckList.o \
./Core/Src/CircuitProcessor.o \
./Core/Src/CircularBuffer.o \
./Core/Src/ExtendedBoard.o \
./Core/Src/ExtendedBoard_PinWork.o \
./Core/Src/Keyboard.o \
./Core/Src/RandomSequenceWithoutRepetitions.o \
./Core/Src/StandProcessor.o \
./Core/Src/StandProcessorLLF.o \
./Core/Src/UART.o \
./Core/Src/dfr0299.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/AnswerCheckList.d \
./Core/Src/CircuitProcessor.d \
./Core/Src/CircularBuffer.d \
./Core/Src/ExtendedBoard.d \
./Core/Src/ExtendedBoard_PinWork.d \
./Core/Src/Keyboard.d \
./Core/Src/RandomSequenceWithoutRepetitions.d \
./Core/Src/StandProcessor.d \
./Core/Src/StandProcessorLLF.d \
./Core/Src/UART.d \
./Core/Src/dfr0299.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/AnswerCheckList.cyclo ./Core/Src/AnswerCheckList.d ./Core/Src/AnswerCheckList.o ./Core/Src/AnswerCheckList.su ./Core/Src/CircuitProcessor.cyclo ./Core/Src/CircuitProcessor.d ./Core/Src/CircuitProcessor.o ./Core/Src/CircuitProcessor.su ./Core/Src/CircularBuffer.cyclo ./Core/Src/CircularBuffer.d ./Core/Src/CircularBuffer.o ./Core/Src/CircularBuffer.su ./Core/Src/ExtendedBoard.cyclo ./Core/Src/ExtendedBoard.d ./Core/Src/ExtendedBoard.o ./Core/Src/ExtendedBoard.su ./Core/Src/ExtendedBoard_PinWork.cyclo ./Core/Src/ExtendedBoard_PinWork.d ./Core/Src/ExtendedBoard_PinWork.o ./Core/Src/ExtendedBoard_PinWork.su ./Core/Src/Keyboard.cyclo ./Core/Src/Keyboard.d ./Core/Src/Keyboard.o ./Core/Src/Keyboard.su ./Core/Src/RandomSequenceWithoutRepetitions.cyclo ./Core/Src/RandomSequenceWithoutRepetitions.d ./Core/Src/RandomSequenceWithoutRepetitions.o ./Core/Src/RandomSequenceWithoutRepetitions.su ./Core/Src/StandProcessor.cyclo ./Core/Src/StandProcessor.d ./Core/Src/StandProcessor.o ./Core/Src/StandProcessor.su ./Core/Src/StandProcessorLLF.cyclo ./Core/Src/StandProcessorLLF.d ./Core/Src/StandProcessorLLF.o ./Core/Src/StandProcessorLLF.su ./Core/Src/UART.cyclo ./Core/Src/UART.d ./Core/Src/UART.o ./Core/Src/UART.su ./Core/Src/dfr0299.cyclo ./Core/Src/dfr0299.d ./Core/Src/dfr0299.o ./Core/Src/dfr0299.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

