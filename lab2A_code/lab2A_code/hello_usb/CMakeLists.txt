if (TARGET tinyusb_device)
    add_executable(lab2A)
    pico_generate_pio_header(lab2A ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)
    target_sources(lab2A PRIVATE hello_usb.c ws2812.c)
 
    # pull in common dependencies
    target_link_libraries(lab2A pico_stdlib hardware_pio )

    # enable usb output, disable uart output
    pico_enable_stdio_usb(lab2A 1)
    pico_enable_stdio_uart(lab2A 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(lab2A)
    
    example_auto_set_url(lab2A)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()


