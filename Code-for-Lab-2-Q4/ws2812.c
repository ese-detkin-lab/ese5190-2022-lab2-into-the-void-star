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
    pio_sm_put_blocking(pio0, 0, color << 8u);      //Write a word of data in state machines's TX FIFO. Block if the TX FIFO is full.
} 
void blink(uint32_t color, int n){
    //The LED will blink 4 times with respective color. 500ms on and 500ms off.
    for (int j=1; j<n+1;j++){
        printf("Blink cycle %d\n", j);
        set_neopixel_color(color);
        sleep_ms(500);
        set_neopixel_color(0x000000);
        sleep_ms(500);
    }
}
int i;
int main() {
    stdio_init_all();       // Initialize all of present standard stdio types that are linked into binary 
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);      //Display which pin is used as WS2812_PIN

    PIO pio = pio0;     //Chooses which PIO instance to be used from 2 available ones i.e. pio0 and pio1
    int sm = 0;     //State machine is set to be 0
    uint offset = pio_add_program(pio, &ws2812_program);       //Find allocation where there is enough space to store our program

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);      //Instantiate an instance of driver program

    int t = 0;
    while (1) {
        //Take a number as an input
        printf("Enter any number\n");
        scanf("%d", &i);  
        printf("Number = %d\n",i);
        sleep_ms(100);
        // Adafruit QT Py have power pin by default set to zero. So we need to manually set it to 1. This does't apply to RPi pico as it automatically sets it to 1
        const uint LED_PIN = 11;        //Defining neopixel power pin 
        gpio_init(LED_PIN);     //Initializing GPIO pin
        gpio_set_dir(LED_PIN, GPIO_OUT);        // Set the pin as output
        gpio_put(LED_PIN, 1);       //Set the pin high
        uint32_t color;
        switch(i) {
            case 1:
                printf("Red LED will blink once\n");
                blink(0x00FF00,i);
                break;
            case 2:
                printf("Green LED will blink twice\n");
                blink(0xFF0000,i);
                break;
            case 3:
                printf("Blue LED will blink thrice\n");
                blink(0x0000FF,i);
                break;
            default:
                printf("Error\n");

        }
    }
}