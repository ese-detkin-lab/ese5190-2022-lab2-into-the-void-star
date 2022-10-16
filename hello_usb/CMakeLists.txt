cmake_minimum_required(VERSION 3.19)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(pico_sdk_import.cmake)
project(blink_aamir_project C CXX ASM)
set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

pico_sdk_init()
add_executable(blink hellousb.c ws2812.c)
target_link_libraries(blink pico_stdlib hardware_pio)
project(pico_examples C CXX ASM)
add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )
target_link_libraries(blink pico_stdlib hardware_pio hardware_dma)
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})



pico_add_extra_outputs(blink)

pico_enable_stdio_usb(blink 1) 
pico_enable_stdio_uart(blink 0)
