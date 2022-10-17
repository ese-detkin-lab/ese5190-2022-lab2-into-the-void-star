/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hello_usb.pio.h"
#include "ws2812.h"


/*
#define IS_RGBW true
#define NUM_PIXELS 1

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 11
#endif

#ifdef PICO_DEFAULT_WS2812_POWER_PIN
#define WS2812_POWER PICO_DEFAULT_WS2812_POWER_PIN
#else
#define WS2812_POWER 12
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

*/

int main() {
    stdio_init_all();

    // Power up the Neopixel
    const uint LED_PIN = WS2812_POWER;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    // todo get free sm

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    uint32_t color = 0xff0000; //0xRRGGBB

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while (true) {
        /*
        printf("Hello, world!\n");
        set_neopixel_color(color); 
        sleep_ms(100);
        set_neopixel_color(0x00000000);
        sleep_ms(900);
        */
        sleep_ms(1000);
        printf("Waiting for input...\n");
        while(true){
            int c = getchar_timeout_us(100);
            if (c != PICO_ERROR_TIMEOUT) {
                printf("%d",c);
                if (c == 114) {
                    putchar_raw(c);
                    printf("\n");
                    set_neopixel_color(0xff0000);
                    break;
                }
                else if (c == 103) {
                    putchar_raw(c);
                    printf("\n");
                    set_neopixel_color(0x00ff00);
                    break;
                }
                else if (c == 98) {
                    putchar_raw(c);
                    printf("\n");
                    set_neopixel_color(0x0000ff);
                    break;
                }
                else {
                    printf("error input!\n");
                }
            } 
        }
    }
    return 0;
}
