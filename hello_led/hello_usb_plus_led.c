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
#define IS_RGBW true
#define NUM_PIXELS 150


#define WS2812_PIN 12
#define WS2812_POWER_PIN 11

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

uint32_t color;
void set_neopixel_color(int t1, int t2, int t3) {
  color = urgb_u32(0xDA+t1, 0x70+t2, 0xD6+t3);
}

int main() {
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    gpio_init(WS2812_POWER_PIN);
    gpio_set_dir(WS2812_POWER_PIN, true);
    gpio_put(WS2812_POWER_PIN, true);

    gpio_put(WS2812_PIN, true);
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
 

    while (1) {
        set_neopixel_color(t1, t2, t3);
        put_pixel(color);      
        printf("Current color is: %lu", color, "\n");
        printf("Hello, world!\n");
        sleep_ms(1000);
        printf("\n");
        t1 += 1;
        t2 += 10;
        t3 += 100;
        sleep_ms(500); 
    }
}
