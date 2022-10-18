/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "ws2812.h"

int main() {
    rp_init();
    turn_on_pixel();

    uint32_t rgb = 0x00000000;
    int i = 0;
    while (true) {
        printf("Current brightness is %d at i = %d\n", rgb, i);
        sleep_ms(100);
        set_pixel_color(rgb);
        sleep_ms(1000);
        if (!i) {
            rgb = 0x00123456;
            i = 1;
        } else {
            rgb = 0x00ff00ff;
            i = 0;
        }
    }
    return 0;
}
