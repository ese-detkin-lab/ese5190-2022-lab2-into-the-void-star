/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "ws2812.pio.h"
#include "ws2812.h"

#define neopixel_power 11

int main() {
    stdio_init_all();

    gpio_init(neopixel_power);
    gpio_set_dir(neopixel_power, GPIO_OUT);
    gpio_put(neopixel_power,1);

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);



    while (true) {

        
        
        printf("hello, World!\n");
        set_neopixel_color(0x0000ff);
        sleep_ms(1000);
        printf("hello, World!\n");
        set_neopixel_color(0);
        sleep_ms(1000);
        
    }
    return 0;
}
