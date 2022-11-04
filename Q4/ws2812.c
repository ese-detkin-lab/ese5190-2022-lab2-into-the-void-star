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
#define WS2812_PIN 12
#endif


void set_neopixel_color(uint32_t color) { 
   
    pio_sm_put_blocking(pio0, 0, color << 8u);
} 
int k;
int main() {
    //set_sys_clock_48();
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    void blink(uint32_t color){
        // for(int i=0;i<4;i++){
        // printf("Blink cycle = %d\n",i);
         printf("Blink cycle\n");
        set_neopixel_color(color);
        sleep_ms(2000);
        set_neopixel_color(0x000000);
        // sleep_ms(500);
        // }
    }
    int t = 0;
    while (1) {
        printf("Enter any number\n");
        scanf("%d", &k);  
        printf("Number = %d\n",k);
        sleep_ms(100);
        const uint LED_PIN = 11;
        gpio_init(LED_PIN);
        gpio_set_dir(LED_PIN, GPIO_OUT);
        gpio_put(LED_PIN, 1);
        uint32_t color;
        switch(k) {
            case 1:
            color=0x00FF00;
            // printf("Case 1\n");
            blink(color);
            break;
            case 2:
            color=0xFF0000;
            // printf("Case 2\n");
            blink(color);
            break;
            case 3:
            color=0x0000FF;
            // printf("Case 3\n");
            blink(color);
            break;
            default:
            printf("Error");
    // code block
        }
        
        // for(int i=0;i<10;i++){
        // set_neopixel_color(0x00FF00);
        // sleep_ms(500);
        // set_neopixel_color(0x000000);
        // sleep_ms(500);
        // }
        
    }
}