/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "ws2812.h"

int main() {
    stdio_init_all();
    ws2812_init();

    while (true) {
        
        char input = getchar_timeout_us(5000);

        if(input=='r')
        {
            set_neopixel_color(0xFF0000);
        }

        else if(input=='g')
        {
            set_neopixel_color(0x00FF00);
        }

        else if(input=='b')
        {
            set_neopixel_color(0x0000FF);
        }

        else
        {
            set_neopixel_color(0x000000);
        }
        
        //printf("Hello, world!\n");
        sleep_ms(1000);
    }
    return 0;
}
