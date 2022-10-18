if (TARGET tinyusb_device)
    add_executable(hello_usb)

    # generate the header file into the source tree as it is included in the RP2040 datasheet
    pico_generate_pio_header(hello_usb ${CMAKE_CURRENT_LIST_DIR}/hello_usb.pio)


    target_sources(hello_usb PRIVATE hello_usb.c ws2812.c)

    include_directories(${CMAKE_CURRENT_LIST_DIR})
    # pull in common dependencies
    target_link_libraries(hello_usb PRIVATE pico_stdlib hardware_pio)
    

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
