if (TARGET tinyusb_device)
    add_executable(WS2812_LED WS2812_LED.c)


    # pull in common dependencies
    target_link_libraries(WS2812_LED PRIVATE pico_stdlib hardware_pio)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(WS2812_LED 1)
    pico_enable_stdio_uart(WS2812_LED 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(WS2812_LED)

    # add url via pico_set_program_url
    example_auto_set_url(WS2812_LED)



# generate the header file into the source tree as it is included in the RP2040 datasheet
    pico_generate_pio_header(WS2812_LED ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

    target_sources(WS2812_LED PRIVATE WS2812_LED.c)

    elseif(PICO_ON_DEVICE)
        message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
    endif()

