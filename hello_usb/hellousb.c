#include <stdio.h>
#include "pico/stdlib.h"
#include "ws2812.h"

int main() {
    stdio_init_all();

    ws2812_init();

    while (true) {
	    // Read from USB
        //RGB: 0xFF0000, 0x00FF00, 0x0000FF

        char input  = getchar_timeout_us(5000);

        //if read char == r,  set_neopixel_color(0xFF0000); 
        if (input == 'r')
        {
        set_neopixel_color(0xFF0000); 
        }
        if (input == 'g')
        {
        set_neopixel_color(0x00FF00); 
        }
        if (input == 'b')
        {
        set_neopixel_color(0x0000FF); 
        }
        else
        {
            set_neopixel_color(0x00000); 
        }
        sleep_ms(1000);
    }
    return 0;
}