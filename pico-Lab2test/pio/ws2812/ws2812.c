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
#include "boards/adafruit_qtpy_rp2040.h"

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif


void set_neopixel_color(uint32_t color);
static inline void put_pixel(uint32_t pixel_grb);
void set_neopixel_color(uint32_t color)
{
 uint32_t r= color&(uint32_t)0x00ff0000;
 uint32_t g= color&(uint32_t)0x0000ff00;
 uint32_t b= color&(uint32_t)0x000000ff;
 put_pixel(r |g|b);
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



int main() {
    //set_sys_clock_48();
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    //set the power pin of ws2812 to on
    const uint WS2812_POWER_PIN=PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(WS2812_POWER_PIN);
    gpio_set_dir(WS2812_POWER_PIN,GPIO_OUT);
    gpio_put(WS2812_POWER_PIN,1);


    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    //int t=0;  
    while (1) {
        printf("case1\n");
        set_neopixel_color(0x33ff99);
        sleep_ms(800);
        printf("case2\n");
        set_neopixel_color(0xff3399);
        sleep_ms(800);
        }
}
    

    
