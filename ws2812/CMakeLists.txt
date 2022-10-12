cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
include(example_auto_set_url.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

project(ws2812 C CXX ASM)
set(WS2812_PIO_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(ws2812 ws2812.c)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(ws2812 PRIVATE ws2812.c)

target_link_libraries(ws2812 PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(ws2812)

# add url via pico_set_program_url
example_auto_set_url(ws2812)

# pico_enable_stdio_usb(${PROJECT_NAME} 0)
# pico_enable_stdio_uart(${PROJECT_NAME} 1)

# add_executable(pio_ws2812_parallel)

# pico_generate_pio_header(pio_ws2812_parallel ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

# target_sources(pio_ws2812_parallel PRIVATE ws2812_parallel.c)

# target_compile_definitions(pio_ws2812_parallel PRIVATE
#         PIN_DBG1=3)

# target_link_libraries(pio_ws2812_parallel PRIVATE pico_stdlib hardware_pio hardware_dma)
# pico_add_extra_outputs(pio_ws2812_parallel)

# # add url via pico_set_program_url
# example_auto_set_url(pio_ws2812_parallel)

# # Additionally generate python and hex pioasm outputs for inclusion in the RP2040 datasheet
# add_custom_target(pio_ws2812_datasheet DEPENDS ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py)
# add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
#         DEPENDS ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio
#         COMMAND Pioasm -o python ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
#         )
# add_dependencies(pio_ws2812 pio_ws2812_datasheet)