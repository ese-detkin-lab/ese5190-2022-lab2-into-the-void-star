cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

if (TARGET tinyusb_device)
    #add_executable(pio_ws2812 ws2812.c ws2812.pio )
    add_executable(pio_hello_usb ws2812.pio)
    
    pico_generate_pio_header(pio_hello_usb ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)
    # pull in common dependencies
    target_sources(pio_hello_usb PRIVATE ws2812.c ws2812.h hello_usb.c ws2812.pio) 
    target_link_libraries(pio_hello_usb pico_stdlib hardware_pio )
    #target_link_libraries(pio_ws2812 PRIVATE pico_stdlib hardware_pio )
    # enable usb output, disable uart output
    pico_enable_stdio_usb(pio_hello_usb 1)
    pico_enable_stdio_uart(pio_hello_usb 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(pio_hello_usb)
    #pico_add_extra_outputs(pio_ws2812)
    # add url via pico_set_program_url
    #example_auto_set_url(hello_usb)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
