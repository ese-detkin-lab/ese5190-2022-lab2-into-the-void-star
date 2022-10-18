add_executable(pio_hello_usb)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(pio_hello_usb ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(pio_hello_usb PRIVATE hello_usb.c ws2812.c ws2812.h)

# --------------enable usb, disable uart----------------------
pico_enable_stdio_usb(pio_hello_usb 1)
pico_enable_stdio_uart(pio_hello_usb 0)

target_link_libraries(pio_hello_usb PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(pio_hello_usb)

# add url via pico_set_program_url
example_auto_set_url(pio_hello_usb)

add_executable(pio_hello_usb_parallel)

pico_generate_pio_header(pio_hello_usb_parallel ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(pio_hello_usb_parallel PRIVATE ws2812_parallel.c)

target_compile_definitions(pio_hello_usb_parallel PRIVATE
        PIN_DBG1=3)

target_link_libraries(pio_hello_usb_parallel PRIVATE pico_stdlib hardware_pio hardware_dma)
pico_add_extra_outputs(pio_hello_usb_parallel)

# add url via pico_set_program_url
example_auto_set_url(pio_hello_usb_parallel)

# Additionally generate python and hex pioasm outputs for inclusion in the RP2040 datasheet
add_custom_target(pio_hello_usb_datasheet DEPENDS ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py)
add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio
        COMMAND Pioasm -o python ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
        )
add_dependencies(pio_hello_usb pio_hello_usb_datasheet)