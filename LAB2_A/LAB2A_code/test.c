#include <stdio.h>
#include "pico/stdlib.h"
#include "ws2812/ws2812.h"

int main() {
    stdio_init_all();
    neopixel_init();
    int my_toggle_flag=0;
    int c;
    while(true){
    while((c=getchar_timeout_us(0))!= EOF){
            putchar_raw(c);
            my_toggle_flag=1;
        }
        if(my_toggle_flag==1){
            printf("send a char");
            set_neopixel_color(0xff0000);
            my_toggle_flag=0;
        }
        else{
            set_neopixel_color(0x000000);
        }
        sleep_ms(5);
    }
    return 0;
}


