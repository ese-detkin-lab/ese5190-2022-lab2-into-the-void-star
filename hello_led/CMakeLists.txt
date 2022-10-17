if (TARGET tinyusb_device)

	add_executable(hello_usb_plus_led hello_usb_plus_led.c)

	# generate the header file into the source tree as it is included in the RP2040 datasheet
	pico_generate_pio_header(hello_usb_plus_led ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

	target_sources(hello_usb_plus_led PRIVATE hello_usb_plus_led.c)

	target_link_libraries(hello_usb_plus_led PRIVATE pico_stdlib hardware_pio)
	pico_add_extra_outputs(hello_usb_plus_led)

	pico_enable_stdio_usb(hello_usb_plus_led 1)
	pico_enable_stdio_uart(hello_usb_plus_led 0)

	pico_add_extra_outputs(hello_usb_plus_led)

	# add url via pico_set_program_url
	example_auto_set_url(hello_usb_plus_led)

elseif(PICO_ON_DEVICE)
	   message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()


