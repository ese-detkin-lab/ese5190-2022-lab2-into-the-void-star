
cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(hello_usb_plus_led C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

# include(example_auto_set_url.cmake)


if (TARGET tinyusb_device)
    add_executable(hello_usb_plus_led
            hello_usb_plus_led.c
            )

    # pull in common dependencies
    target_link_libraries(hello_usb_plus_led PRIVATE pico_stdlib hardware_pio pico_stdio)

    target_sources(hello_usb_plus_led PRIVATE ws2812.c)

    pico_generate_pio_header(hello_usb_plus_led ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hello_usb_plus_led 1)
    pico_enable_stdio_uart(hello_usb_plus_led 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(hello_usb_plus_led)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
