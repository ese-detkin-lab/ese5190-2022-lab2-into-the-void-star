/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "ws2812.h"


#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN

#else
#define WS2812_PIN 12
#define WS2812_Power_PIN 11
#endif



int main() {
    //set_sys_clock_48();
    stdio_init_all();
    gpio_init(WS2812_Power_PIN);
    gpio_set_dir(WS2812_Power_PIN, GPIO_OUT);
    gpio_put(WS2812_Power_PIN, 1);
         
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while (true) {
        printf("Hello, world!\n");
        set_neopixel_color(0XFFFF00);
        sleep_ms(1000);
    }
    return 0;    
 
    }

