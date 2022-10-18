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
#include "generated/ws2812.pio.h"

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#endif

#define WS2812_POWER_PIN 11

int main() {
    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);
    
    turn_on_LED_power();
    printf("WS2812 Power Enabled, pin %d", WS2812_POWER_PIN);
    
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    
    bool LEDon = false;
    char userInput;

    while (true) {
    	userInput = getchar_timeout_us(0);
    	if(userInput == '1'){
    	    LEDon = true;
    	    printf("Command 1 Received, the LED has been turned on. \n");
    	    printf("Waiting for your next command. \n");
    	    
    	}else if(userInput == '0'){
    	    LEDon = false;
	    printf("Command 0 Received, the LED has been turned off. \n");
    	    printf("Waiting for your next command. \n");
    	}else{
	    
    	}
    	
    	if(LEDon){
            set_neopixel_color(0x0a, 0xba, 0xb5);
        }else{
            set_neopixel_color(0x00,0x00,0x00);
        }
        
    }
    return 0;
}

