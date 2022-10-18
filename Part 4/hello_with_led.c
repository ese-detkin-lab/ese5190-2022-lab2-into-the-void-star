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

#define PICO_DEFAULT_WS2812_PIN 12
#define PICO_DEFAULT_WS2812_POWER_PIN 11

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

void set_neopixel_color(){
    put_pixel(urgb_u32(0x0a,0xba,0xb5));
    sleep_ms(100);
}

int main() {
    //set_sys_clock_48();
    stdio_init_all();
    // Initialize the PICO_DEFAULT_WS2812_POWER_PIN
    gpio_init(PICO_DEFAULT_WS2812_POWER_PIN);
    // Configure the PICO_DEFAULT_WS2812_POWER_PIN as an output
    gpio_set_dir(PICO_DEFAULT_WS2812_POWER_PIN, GPIO_OUT);
    printf("WS2812 Smoke Test, using pin %d", PICO_DEFAULT_WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, PICO_DEFAULT_WS2812_PIN, 800000, IS_RGBW);

    while(true){
        printf("WS2812 Smoke Test, using pin %d", PICO_DEFAULT_WS2812_PIN);
        gpio_put(PICO_DEFAULT_WS2812_POWER_PIN, 1);
        set_neopixel_color();
        put_pixel(urgb_u32(0x00,0x0a,0xb5));
        sleep_ms(100);
    }
    return 0;
}
