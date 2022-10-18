#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "ws2812/ws2812.h"
typedef void (*pattern)(uint len, uint t);
const struct {
    uint32_t color ;
    char *name;
} color_table[] = {
        {0xff0000,  "Red!"},
        {0x00ff00,  "Green!"},
        {0x0000ff, "Blue!"},
};
int main() {
    stdio_init_all();
    neopixel_init();
    int my_toggle_flag=0;
    int c;
    while(true){
    //output example
    int flag = rand() % 3;
    printf(color_table[flag].name);
    printf("\n");
    set_neopixel_color(color_table[flag].color);
    




    /* input example
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
        }*/

        sleep_ms(1000);
        //sleep_ms(5);
    }
    return 0;
}


