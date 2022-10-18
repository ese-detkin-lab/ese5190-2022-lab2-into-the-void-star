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
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);
    // self defined init func for ws2812
    ws2812_init();


    uint8_t my_toggle_flag = 0;
    while (true) {
        if(my_toggle_flag == 1){
            printf("Green!\n");
            my_toggle_flag = 0;
            set_neopixel_color(0x00ff00);
        }
        else {
            printf("Blue!\n");
            my_toggle_flag  = 1;
            set_neopixel_color(0x0000ff);
        }
        sleep_ms(1000);
    }
    return 0;
}
