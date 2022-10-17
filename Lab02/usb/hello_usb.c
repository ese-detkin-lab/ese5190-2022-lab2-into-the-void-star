/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hello_usb.pio.h"
#include "ws2812.h"

int main() {
    stdio_init_all();

    // Power up the Neopixel
    const uint LED_PIN = WS2812_POWER;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    // todo get free sm

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    uint32_t color = 0xff0000; //0xRRGGBB

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while (true) {
        sleep_ms(1000);
        printf("Waiting for input. Choose one from r ,g ,b...\n");
        while(true){
            int c = getchar_timeout_us(100);
            if (c != PICO_ERROR_TIMEOUT) {
                printf("%d",c);
                // 114 is ASCII for 'r'
                if (c == 114) {
                    putchar_raw(c);
                    printf("\n");
                    set_neopixel_color(0xff0000);
                    break;
                }
                // 103 is ASCII for 'g'
                else if (c == 103) {
                    putchar_raw(c);
                    printf("\n");
                    set_neopixel_color(0x00ff00);
                    break;
                }
                // 98 is ASCII for 'b'
                else if (c == 98) {
                    putchar_raw(c);
                    printf("\n");
                    set_neopixel_color(0x0000ff);
                    break;
                }
                else {
                    printf("error input!\n");
                }
            } 
        }
    }
    return 0;
}
