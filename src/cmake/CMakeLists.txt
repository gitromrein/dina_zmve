cmake_minimum_required(VERSION 3.22)

set(
    SHARED_SOURCES

    ../Core/Src/main.cpp
    ../Core/Src/dummy.cpp
    ../Core/Src/stm32h7xx_it.c
    ../Core/Src/stm32h7xx_hal_msp.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c
    ../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c
    ../Core/Src/system_stm32h7xx.c
    ../Core/Src/sysmem.c
    ../Core/Src/syscalls.c
)

set(
    MASTER_SOURCES

    ../Core/Src/board.master.cpp
)

set(
    SLAVE_SOURCES

    ../Core/Src/board.slave.cpp
)

set(
    STARTUP_FILE

    ../startup_stm32h753xx.s
)

project(mastercpu)
add_library(mastercpu INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(CXX C ASM)

target_compile_definitions(mastercpu INTERFACE 
	USE_HAL_DRIVER 
	STM32H753xx
    CPU_MASTER
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(mastercpu INTERFACE
    ../Core/Inc
    ../Drivers/STM32H7xx_HAL_Driver/Inc
    ../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy
    ../Drivers/CMSIS/Device/ST/STM32H7xx/Include
    ../Drivers/CMSIS/Include
)

target_sources(mastercpu INTERFACE
    ${SHARED_SOURCES}
    ${MASTER_SOURCES}
    ${STARTUP_FILE}
)

target_link_directories(mastercpu INTERFACE
)

target_link_libraries(mastercpu INTERFACE
)

project(slavecpu)
add_library(slavecpu INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(CXX C ASM)

target_compile_definitions(slavecpu INTERFACE 
	USE_HAL_DRIVER 
	STM32H753xx
    CPU_SLAVE
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(slavecpu INTERFACE
    ../Core/Inc
    ../Drivers/STM32H7xx_HAL_Driver/Inc
    ../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy
    ../Drivers/CMSIS/Device/ST/STM32H7xx/Include
    ../Drivers/CMSIS/Include
)

target_sources(slavecpu INTERFACE
    ${SHARED_SOURCES}
    ${SLAVE_SOURCES}
    ${STARTUP_FILE}
)

target_link_directories(slavecpu INTERFACE
)

target_link_libraries(slavecpu INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


