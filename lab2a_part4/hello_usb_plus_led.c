/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "generated/ws2812.pio.h"
#include "hardware/gpio.h"
#include "ws2812.h"


#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#define POWER_PIN 11
#endif

// Set default color
#define BLUE 0x0000FF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define CYAN 0x00FFFF
#define PURPLE 0xFF00FF
#define YELLOW 0xFFFF00
#define WHITE 0xFFFFFF
#define BLACK 0x000000




int main() {
    // init stdio, gpio
    stdio_init_all();
    gpio_init(POWER_PIN);
    gpio_set_dir(POWER_PIN, GPIO_OUT);
    gpio_put(POWER_PIN, 1); // toggle up power pin to switch on WS2812

    PIO pio = pio0; // use pio0
    int sm = 0; // use state machine 0
    uint offset = pio_add_program(pio, &ws2812_program); // get address of ws2812_program
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW); // init ws2812
    

    while (true) {
        printf("Hello, world!\n"); // proof connection
        sleep_ms(1000); // stay for 1s
        int c = getchar_timeout_us(100); // get use input
        if(c != PICO_ERROR_TIMEOUT){// if the time wait is not out of time
            printf("Data = %c,%d \n",c,c);  // show date to user
            if (c == 82||c==114){
                set_neopixel_color(RED); // Red light
            }else if(c==66||c==98){
                set_neopixel_color(BLUE); // blue light
            }else if(c==80||c==112){
                set_neopixel_color(PURPLE); // purple light
            }else if(c==87||c==119){
                set_neopixel_color(WHITE); // white light
            }else if(c==71||c==103){
                set_neopixel_color(GREEN); // green light
            }else if(c==89||c==121){
                set_neopixel_color(YELLOW);  // yellow light
            }else if(c==67||c==99){
                set_neopixel_color(CYAN);  // cyan light
            }else{
                set_neopixel_color(BLACK); // turn off the light
            }
        }else{
            set_neopixel_color(BLACK); // turn off the light
            printf("Input a exist value!\n"); // notice user to choose proper value
        }
    }
    return 0;

}
