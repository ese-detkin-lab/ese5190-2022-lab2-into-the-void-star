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

#include "/home/ruturajn/Git-Repos/pico/pico-sdk/src/boards/include/boards/adafruit_qtpy_rp2040.h"

#define IS_RGBW true
#define NUM_PIXELS 150
#define PICO_DEFAULT_WS2812_POWER_PIN 11

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

/* static inline void put_pixel(uint32_t pixel_grb) { */
/*     pio_sm_put_blocking(pio0, 0, pixel_grb << 8u); */
/* } */

/* static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) { */
/*     return */
/*             ((uint32_t) (r) << 8) | */
/*             ((uint32_t) (g) << 16) | */
/*             (uint32_t) (b); */
/* } */

void set_neopixel_color(uint32_t color_num){
    //
    uint32_t r_num = color_num >> 16;
    uint32_t g_num = color_num << 16;
    g_num = g_num >> 24;
    uint32_t b_num = color_num << 24;
    b_num = b_num >> 24;
    uint32_t color_final = ((r_num << 8) |
                            (g_num << 16)|
                            (b_num));
    pio_sm_put_blocking(pio0, 0, color_final << 8u);
}


int main() {
    //set_sys_clock_48();
    const uint POWER_PIN_NAME = PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(POWER_PIN_NAME);
    gpio_set_dir(POWER_PIN_NAME, GPIO_OUT);
    gpio_put(POWER_PIN_NAME, 1);
    stdio_init_all();

    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while(1){
        int user_inp = getchar_timeout_us(5000);
        if(user_inp != 1){
            set_neopixel_color(0xffafaf);
            sleep_ms(500);
            set_neopixel_color(0);
        }
        sleep_ms(1000);
    }
    
    /* while(1){ */
    /*     // If hello world is printed, blink the LED, with a certain color. */
    /*     if (printf("Hello! World\n")){ */
    /*         /1* put_pixel(urgb_u32(0xaf, 0, 0xfa)); *1/ */
    /*         put_pixel(urgb_u32(0xaf, 0, 0xfa)); */
    /*         sleep_ms(500); */
    /*         /1* put_pixel(0); *1/ */
    /*     } */
        
    /*     // Sleep for 1 second for smooth operation. */
    /*     sleep_ms(1000); */
    }
}
