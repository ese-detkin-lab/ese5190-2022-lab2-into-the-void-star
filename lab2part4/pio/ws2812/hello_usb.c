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
        printf("Hello, world!\n");
        sleep_ms(1000);
        set_neopixel_color(0x00ffffff);
        sleep_ms(1000);
        set_neopixel_color(0x00ff0022);
        sleep_ms(1000);
        set_neopixel_color(0x0000ee22);
    }
    return 0;
}
