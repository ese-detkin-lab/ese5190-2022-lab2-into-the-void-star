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
#include "ws2812.h"
#include "ws2812.pio.h"

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

int main() {
    stdio_init_all();

    gpio_init(11);
    gpio_set_dir(11, GPIO_OUT);
    gpio_put(11, true);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, 12, 800000, IS_RGBW);

    while (1) {
        if (getchar_timeout_us(0) == -1) {
            set_neopixel_color(0xFF0000);
        } else {
            set_neopixel_color(0x00FF00);
        }
        sleep_ms(100);
    }
}