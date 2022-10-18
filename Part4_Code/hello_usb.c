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
    sleep_ms(3000);
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);
    // self defined init func for ws2812
    ws2812_init();


    uint8_t toggle=0;
    while (true) {
        if(toggle==1){
            printf("This is Green!\n");
            toggle=0;
            set_neopixel_color(0x00ff00);
        }
        else {
            printf("This is Blue!\n");
            toggle=1;
            set_neopixel_color(0x0000ff);
        }
        sleep_ms(1000);
    }
    return 0;
}
