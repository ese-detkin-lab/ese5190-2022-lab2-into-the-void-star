cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include(example_auto_set_url.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

project(ws2812 C CXX ASM)
set(WS2812_PIO_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

if (TARGET tinyusb_device)
    add_executable(hello_usb)

    pico_generate_pio_header(hello_usb ${CMAKE_CURRENT_LIST_DIR}/ws2812_header/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

    # pull in common dependencies
    target_sources(hello_usb PRIVATE
        hello_usb.c
        ws2812_header/ws2812.c
        ws2812_header/ws2812.h
    )
    target_link_libraries(hello_usb pico_stdlib hardware_pio)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hello_usb 1)
    pico_enable_stdio_uart(hello_usb 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(hello_usb)

    # add url via pico_set_program_url
    example_auto_set_url(hello_usb)
    
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
