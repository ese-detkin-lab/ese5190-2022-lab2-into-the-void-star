cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()




if (TARGET tinyusb_device)
    add_executable(lab2A ws2812.pio) 

    # generate the header file into the source tree as it is included in the RP2040 datasheet
    pico_generate_pio_header(lab2A ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

    # pull in common dependencies

    target_sources(lab2A PRIVATE ws2812.c ws2812.h hello_usb.c ws2812.pio)
    target_link_libraries(lab2A PRIVATE pico_stdlib hardware_pio)

    pico_enable_stdio_usb(lab2A 1)
    pico_enable_stdio_uart(lab2A 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(lab2A)



elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()











