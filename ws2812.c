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

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#endif

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}


int main() {
#ifndef PICO_DEFAULT_WS2812_POWER_PIN
#warning lab2 example requires a board with ws2812 compatible power pin
#else 
    const uint POWER_PIN = PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(POWER_PIN);
    gpio_set_dir(POWER_PIN, GPIO_OUT);
    gpio_put(POWER_PIN, 1);
    //set_sys_clock_48();
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while (1) {
        sleep_ms(1000);
        printf("this is a mysterious color generator. Waiting for input:\n");
        while(1){
            int c = getchar_timeout_us(100);
            if(c != PICO_ERROR_TIMEOUT){
                printf("%d",c);
                int r = (rand() % 255); //generate random numbers from 0 to 255
                int g = (rand() % 255);
                int b = (rand() % 255); 
                put_pixel(urgb_u32(r,g,b));
                printf("you are generating the color: r：%d, g:%d, b:%d. \n",r,g,b);
            }
        }
        return 0;
    }
#endif
}
