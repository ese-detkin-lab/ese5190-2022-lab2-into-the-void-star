#include <stdio.h>
#include <stdlib.h>

#ifndef WS2812_H_
#define WS2812_H_

void ws2812_init();
void set_neopixel_color(int color);
void set_led(uint32_t pixel_grb);

#endif