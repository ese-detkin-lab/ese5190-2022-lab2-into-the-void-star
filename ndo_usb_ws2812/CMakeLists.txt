
if (TARGET tinyusb_device)

add_executable(ndo_usb_ws2812)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(ndo_usb_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(ndo_usb_ws2812 PRIVATE usb_ws2812.c)

target_link_libraries(ndo_usb_ws2812 PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(ndo_usb_ws2812)

pico_enable_stdio_usb(ndo_usb_ws2812 1)
pico_enable_stdio_uart(ndo_usb_ws2812 0)


# Additionally generate python and hex pioasm outputs for inclusion in the RP2040 datasheet
add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio
        COMMAND Pioasm -o python ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
        )

    # enable usb output, disable uart output


    # create map/bin/hex/uf2 file etc.

    # add url via pico_set_program_url
elseif(PICO_ON_DEVICE)
    message(WARNING "not building ndo_usb_ws2812 because TinyUSB submodule is not initialized in the SDK")
endif()