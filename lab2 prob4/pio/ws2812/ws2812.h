#ifndef _WS2812_H
#define _WS2812_H

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#define WS2812_POWER_PIN  11
#endif

void set_neopixel_color(uint32_t color);



#endif