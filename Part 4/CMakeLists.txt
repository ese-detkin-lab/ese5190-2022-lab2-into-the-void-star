cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(hello_with_led C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# add hello_with_led
add_executable(hello_with_led hello_with_led.c)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(hello_with_led ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_link_libraries(hello_with_led PRIVATE pico_stdlib hardware_pio)

# enable usb output, disable uart output
pico_enable_stdio_usb(hello_with_led 1)
pico_enable_stdio_uart(hello_with_led 0)

pico_add_extra_outputs(hello_with_led)

