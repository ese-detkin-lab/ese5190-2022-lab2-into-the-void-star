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
#define WS2812_POWER_PIN 11
#define WS2812_PIN 12

#endif

void turn_on_NeoPixel_power(){
    const uint led_pin = WS2812_POWER_PIN;
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
    gpio_put(led_pin,1);
}

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
void set_color(int color_change){ 
  color = urgb_u32(0x10+color_change, 0, 0x10+color_change);
}

int main() {
    stdio_init_all();
    printf("Start");

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    turn_on_NeoPixel_power();
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    int color_change=0;
    while (1) {
        printf("Hello, world! \n");
        sleep_ms(500);
        set_color(color_change);
        put_pixel(color);
        sleep_ms(500);
        put_pixel(urgb_u32(0, 0, 0));
        sleep_ms(500);       
        
        if(color_change<20)
            color_change++;
        if(color_change>20)
            color_change=0;
    }
}
