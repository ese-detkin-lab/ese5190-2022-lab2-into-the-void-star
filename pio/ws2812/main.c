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
    int cycle=5;
    
    while (1) {
    for(int j=0;j<=220;j=j+4)
    {
        printf("address %08x: %08x\n",0x50200000+j,*((int*)(0x50200000+j)));
    }
        if(flag==1){
            printf("Hello, world!\n");
            flag=0;
            set_neopixel_color(0x0000ff);
        }
        else {
            printf("Hello, world again!\n");
            flag=1;
            set_neopixel_color(0x00ff00);
        }
        sleep_ms(300);
        
    }
    return 0;
}
