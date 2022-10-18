cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()
# rest of your project

if (TARGET tinyusb_device)
    add_executable(hello_usb_plus_led hello_usb_plus_led.c
            ws2812.h ws2812.c ws2812.pio ws2812.pio.h adafruit_itsybitsy_rp2040.h)

    # pull in common dependencies
    target_link_libraries(hello_usb_plus_led pico_stdlib hardware_pio)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hello_usb_plus_led 1)
    pico_enable_stdio_uart(hello_usb_plus_led 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(hello_usb_plus_led)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb_plus_led because TinyUSB submodule is not initialized in the SDK")
endif()