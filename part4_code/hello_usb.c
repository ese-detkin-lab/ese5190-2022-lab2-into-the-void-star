/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "ws2812.h"
#include "ws2812.pio.h"

int main() {
    stdio_init_all();
    
    //printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);
    gpio_init(11);
    gpio_set_dir(11, GPIO_OUT);
    gpio_put(11, 1);
    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while (true) {
        char c = getchar();
        if (c==114)
            {   printf("Helljo,Red!");
                set_neopixel_color(0x00ff00);
            }
        else if (c=103)
            {
            printf("Hello,Green!");
            set_neopixel_color(0xff0000);
            }
        else if (c=98)
            {
            printf("Hello,Blue!");
            set_neopixel_color(0xff0000);
            }
        }
        


    
    return 0;
}
