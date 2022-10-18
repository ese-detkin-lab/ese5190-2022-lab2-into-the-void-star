/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "ws2812.h"

int main() {
    int color;
    stdio_init_all();
    ws2812_init();
    while(1) {
        printf("The color pattern you want? \n");
        color = getchar_timeout_us(5000);
        if(color == PICO_ERROR_TIMEOUT){
            printf("do not reveive character \n");
        }
        else if (color == 115){
            printf("The system stop. \n");
            break;
        }
        else{
            set_neopixel_color(color);
        }
        sleep_ms(10000);
    }

    return 0;
}


// // print the value of the register
// int main(){
//     uint32_t grb = 0x0000FF;
//     int *rgtr = 0x50200000;
//     int *gpiopin = 0x40014060;
//     while (1)
//     {
//         stdio_init_all();
//         printf("the value of registers used in PIO 0 \n");
//         ws2812_init();
//         printf("%08x, \tvalue = %08x \n", gpiopin, *(gpiopin));
//         set_led(grb);
//         // for (int i = 61; i < 81; i++)
//         // {
//         //     printf("%08x, \tvalue = %08x \n", rgtr+i, *(rgtr+i));
//         // }
//         printf("%08x, \tvalue = %08x \n", gpiopin, *(gpiopin));
//         sleep_ms(5000);
//     }
    
//     return 0;
// }
