

#ifndef _WS2812_H
#define _WS2812_H

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN

#else

#define WS2812_PIN 12
#endif

void set_neopixel_color(uint32_t color); 

#endif