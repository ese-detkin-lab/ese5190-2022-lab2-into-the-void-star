/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "ws2812.h"

int my_toggle_flag = 0;

//void set_neopixel_color();

int main() {
    
    gpio_init(11);
    //set_sys_clock_48();
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    gpio_set_dir(11, GPIO_OUT);
    gpio_put(11, 1);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    
    while (true) {
        //printf("test\n");
        if (my_toggle_flag == 1){
            set_neopixel_color(0x00FF00);
            my_toggle_flag = 0;
            printf("Hello,World!\n");
        }
        else{
            set_neopixel_color(0x0000FF);
            printf("Hello!\n");
            my_toggle_flag = 1;
        }
        sleep_ms(100);
    }
    return 0;
}
