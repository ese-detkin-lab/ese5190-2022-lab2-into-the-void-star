add_executable(hello_LED_usb)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(hello_LED_usb ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

# target_sources(hello_LED PRIVATE ws2812.c)
target_sources(hello_LED_usb PRIVATE ws2812.h ws2812.c hello_LED.c)

# pull in common dependencies
target_link_libraries(hello_LED_usb pico_stdlib hardware_pio)

# enable usb output, disable uart output
pico_enable_stdio_usb(hello_LED_usb 1)
pico_enable_stdio_uart(hello_LED_usb 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(hello_LED_usb)

# add url via pico_set_program_url
example_auto_set_url(hello_LED_usb)
