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
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#endif

int main() {
    //Initialize stdio
    stdio_init_all();
    
    printf("WS2812 Smoke Test, using pin %d",WS2812_PIN);
    //initialize the WS2818 power pin
    gpio_init(11);
    // set neopixal power as output
    gpio_set_dir(11,GPIO_OUT);
    // set the neopixel power as high
    gpio_put(11,1);

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio,&ws2812_program);
    ws2812_program_init(pio,sm,offset,WS2812_PIN,800000,IS_RGBW);
    // Loop
    while (true) 
    {

     /*
    if (getchar_timeout_us(0) == -1) { 
        set_neopixel_color(0x00FF00); 
    } else { 
        set_neopixel_color(0x00FF00); 
    } 
    sleep_ms(100);
    */ 

     
        // sleep
        sleep_ms(500);
        // for Neopixel
        set_neopixel_color(0x00FFFF);
        printf("Hello, world!\n");
       
    }
    return 0;
}