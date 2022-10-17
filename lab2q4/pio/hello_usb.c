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


    uint8_t toggle=0;
    while (true) {
        if(toggle==1){
            printf("Hello, world!\n");
            toggle=0;
            set_neopixel_color(0x00ff0000);
        }
        else {
            printf("Byebye, world!\n");
            toggle=1;
            set_neopixel_color(0x000000ff);
        }
        sleep_ms(1000);
    }
    return 0;
}
