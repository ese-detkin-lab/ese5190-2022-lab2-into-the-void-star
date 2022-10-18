/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//Header files
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

//defining NUM_PIXELS to 150
#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#endif


void set_neopixel_color(uint32_t color) { 
   
    pio_sm_put_blocking(pio0, 0, color << 8u);
} 
char c;
int main() {
    //set_sys_clock_48();
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    void set_color(uint32_t color){
        printf("Blink \n");
        set_neopixel_color(color);
        sleep_ms(2000);
        set_neopixel_color(0x000000);
    }
    int t = 0;
    while (1) {
        printf("Enter any character\n");
        scanf("%c", &c);  
        printf("Character = %c\n",c);
        sleep_ms(100);
        const uint LED_PIN = 11;
        gpio_init(LED_PIN);
        gpio_set_dir(LED_PIN, GPIO_OUT);
        gpio_put(LED_PIN, 1);
        uint32_t color;
        switch(c) {
            case 'r':
                set_color(0x00FF00);
                printf("Red");
                break;
            case 'g':
                set_color(0xFF0000);
                printf("Green");
                break;
            case 'b':
                set_color(0x0000FF);
                printf("Blue");
                break;
            default:
                printf("Error\n");

        }
    }
}
 

// If 'r' then red color, 'g' then green, and 'b' then blue