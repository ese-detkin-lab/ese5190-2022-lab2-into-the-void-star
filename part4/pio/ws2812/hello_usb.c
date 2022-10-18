/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "ws2812.h"

int main() {
    rp_init();
    turn_on_pixelpower();
    
    while (true) {
        printf("White Light Open\n");
        set_neopixel_color(0x00ffffff);
        sleep_ms(1000);
        printf("Red Light Open\n");
        set_neopixel_color(0x00ff0000);
        sleep_ms(1000);
        printf("Green Light Open\n");
        set_neopixel_color(0x0000ff00);
        sleep_ms(1000);
        printf("Blue Light Open\n");
        set_neopixel_color(0x000000ff);
        sleep_ms(1000);
    }
    return 0;
}
