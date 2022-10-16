/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "adafruit_qtpy_rp2040.h"
#include "ws2812.h"

int flag = 1;

int main() {
    stdio_init_all();
    
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
        
        if (flag){
            printf("Hello, world!\n");
            set_neopixel_color(0xFF0000); //green
            flag = 0;
        }
        else{
            printf("Bye!\n");
            set_neopixel_color(0x00FF00);
            flag = 1;
        }
        
        sleep_ms(1000);
    }
    return 0;
}
