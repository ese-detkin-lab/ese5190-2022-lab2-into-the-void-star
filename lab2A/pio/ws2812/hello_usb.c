/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "ws2812.h"

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
#define WS2812_POWER_PIN 11
#endif

int main() {
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    turn_on_NeoPixel_power();
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    turn_on_NeoPixel_power();
    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
        set_rgb(0x00ff00ff);
        sleep_ms(1000);
        set_rgb(0x004500ab);
        sleep_ms(1000);
        set_rgb(0x000088aa);
        sleep_ms(1000);
        set_rgb(0x00ffff88);
    }
    return 0;
}
