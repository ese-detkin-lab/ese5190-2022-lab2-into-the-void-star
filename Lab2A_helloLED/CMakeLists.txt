cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()

include(pico_sdk_import.cmake)

project(Lab2A_helloLED C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()
# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

if (TARGET tinyusb_device)
    add_executable(Hello_usb_plus_led Hello_usb_plus_led.c ws2812.c)
    
    
    # pull in common dependencies
    target_link_libraries(Hello_usb_plus_led PRIVATE pico_stdlib hardware_pio hardware_clocks)
    
    # enable usb output, disable uart output
    pico_enable_stdio_usb(Hello_usb_plus_led 1)
    pico_enable_stdio_uart(Hello_usb_plus_led 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(Hello_usb_plus_led)

    # add url via pico_set_program_url
    # example_auto_set_url(Hello_usb)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()



#PRIVATE is about what happens if other targets want to use yours; as a rule of thumb, 
#just mark all your dependencies as PRIVATE unless you have a good reason not to. 