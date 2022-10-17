#ifndef __WS2812_H
#define __WS2812_H

// neopixel on Py QT =RP2040: neo_pwr: gpio 11, neopix:gpio 12
#define NEOPIX 12
#define NEOPWR 11
#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN 12//PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

//translate RGB order to GRB order and 
void set_neopixel_color(uint32_t color);

void ws2812_init();
#endif