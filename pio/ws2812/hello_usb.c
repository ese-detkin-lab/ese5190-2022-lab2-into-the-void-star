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


    uint8_t flag=0;
    while (true) {
        if(flag == 0){
            printf("GREEN!\n");
            flag=1;
            set_neopixel_color(0x00ff00);
        }
        else if (flag == 1) {
            printf("BLUE\n");
            flag=2;
            set_neopixel_color(0x0000ff);
        }
        else{
            printf("RED\n");
            flag=0;
            set_neopixel_color(0xff0000);
        }
        sleep_ms(500);
    }
    return 0;
}
