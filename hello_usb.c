#include "ws2812_header/ws2812.h"

int main(){

    stdio_init_all();
    sleep_ms(3000);
    printf("Initializing...\n\n");

    while (true){
        stdio_flush();
        printf("Input Color in HEX, Press m to Exit:\n");
        char colors[6];
        bool is_invalid = false;
        int count = 0;

        while (count < 6){

            int c = getchar_timeout_us(4 * 1000 * 1000);
            if (c == PICO_ERROR_TIMEOUT){
                printf("Input Time Out.\n");
                is_invalid = true;
                break;
            }else if ((char)c == 'm'){
                set_neopixel_color((uint32_t)0x000000);
                printf("GG!\n");
                return 0;
            }else if (!isxdigit(c)){
                printf("Invalid Color Input.\n");
                is_invalid = true;
                break;
            }

            colors[count] = (char)c;
            count++;
        }

        if (is_invalid){
            is_invalid = false;
            continue;
        }else{
            printf("The color is: ");
            uint32_t result = (uint32_t)strtol(colors, NULL, 16);
            printf("%06x\n", result);
            set_neopixel_color(result);
        }
    }
}