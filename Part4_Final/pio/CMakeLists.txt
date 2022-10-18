add_executable(hello_usb_plus_led)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(hello_usb_plus_led ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(hello_usb_plus_led PRIVATE hello_usb.c ws2812.c ws2812.h)

target_link_libraries(hello_usb_plus_led PRIVATE pico_stdlib hardware_pio)

    # enable usb output, disable uart output
pico_enable_stdio_usb(hello_usb_plus_led 1)
pico_enable_stdio_uart(hello_usb_plus_led 0)

pico_add_extra_outputs(hello_usb_plus_led)

# add url via pico_set_program_url
example_auto_set_url(hello_usb_plus_led)


### parallel file
add_executable(pio_ws2812_parallel)

pico_generate_pio_header(pio_ws2812_parallel ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(pio_ws2812_parallel PRIVATE ws2812_parallel.c)

target_compile_definitions(pio_ws2812_parallel PRIVATE
        PIN_DBG1=3)

target_link_libraries(pio_ws2812_parallel PRIVATE pico_stdlib hardware_pio hardware_dma)
pico_add_extra_outputs(pio_ws2812_parallel)

# add url via pico_set_program_url
example_auto_set_url(pio_ws2812_parallel)

