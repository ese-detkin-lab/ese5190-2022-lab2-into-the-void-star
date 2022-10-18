cmake_minimum_required(VERSION 3.12)
# INCLUDE PICO SDK CMAKE FUNCTIONS (must be before project)
include(pico_sdk_import.cmake)

# CREATE A CMAKE PROJECT CALLED USBTest
project(Hello_LeD C CXX ASM)
add_executable(hello_usb_ws2812)
# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_sdk_init()

target_sources(hello_usb_ws2812 PRIVATE hello_usb_ws2812.c ws2812.c ws2812.h) 
target_link_libraries(hello_usb_ws2812 PRIVATE pico_stdlib hardware_pio pico_stdio)

pico_generate_pio_header(hello_usb_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

pico_enable_stdio_usb(hello_usb_ws2812 1)
pico_enable_stdio_uart(hello_usb_ws2812 0)

pico_add_extra_outputs(hello_usb_ws2812)






