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
#include "D:\pico\pico-sdk\src\boards\include\boards\adafruit_qtpy_rp2040.h"

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif
#define PICO_DEFAULT_WS2812_POWER_PIN 11



void set_neopixel_color(uint32_t color) { 
    // your implementation goes here 
    uint32_t rc = color>>16;
    uint32_t gc  = color<<16;
    gc=gc>>24;
    uint32_t bc = color<<24;
    bc=bc>>24;
    uint32_t color_new = ((rc<<8)|(gc<<16)|(bc));
    pio_sm_put_blocking(pio0, 0, color_new << 8u);
} 

int main() {
    //set_sys_clock_48();
    const uint POW_PIN = PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(POW_PIN);
    gpio_set_dir(POW_PIN, GPIO_OUT);
    gpio_put(POW_PIN, 1);
    stdio_init_all();
    

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    const int y;
    int t = 0;

    while (1) {

        int c = getchar_timeout_us (5000);
       if(c!=-1)
       {
         set_neopixel_color(0xFF00FF);
         sleep_ms(500);
        set_neopixel_color(0);

       }
        }
    }
