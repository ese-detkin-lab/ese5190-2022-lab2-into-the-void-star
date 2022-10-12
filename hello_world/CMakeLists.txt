cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(test_project C CXX ASM)
set(HELLO_PIO_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

include(example_auto_set_url.cmake)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

add_executable(hello_pio)

pico_generate_pio_header(hello_pio ${CMAKE_CURRENT_LIST_DIR}/hello.pio)

target_sources(hello_pio PRIVATE hello.c)

target_link_libraries(hello_pio PRIVATE
        pico_stdlib
        hardware_pio
        )

pico_add_extra_outputs(hello_pio)

# add url via pico_set_program_url
example_auto_set_url(hello_pio)
