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
#include "generated/ws2812.pio.h"
#include "ws2812.h"


#define IS_RGBW true
#define NUM_PIXELS 150


#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN

#else
#define WS2812_PIN 12
#endif
// Neopixel power is connected to GPIO 11
#define PICO_DEFAULT_WS2812_PIN 11




int main() {
    //  Initialize stdio
    stdio_init_all();
    const uint WS2812_POWER_PIN = PICO_DEFAULT_WS2812_PIN;
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);
    //initialize the WS2818 power pin
    gpio_init(WS2812_POWER_PIN);
    // set neopixel power as output
    gpio_set_dir(WS2812_POWER_PIN, GPIO_OUT);
    // set the neopixel power as high
    gpio_put(WS2812_POWER_PIN, 1);

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    // Loop
    while (true) { 
        //sleep
        sleep_ms(500);
        //For Neopixel
        set_neopixel_color(0x000000);
        // Print Hello World
        printf("Hello World !\n");
    }
    return 0;
}





