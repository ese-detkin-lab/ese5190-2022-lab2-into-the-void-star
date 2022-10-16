#ifndef _WS2812_H
#define _WS2812_H
void set_neopixel_color(uint32_t color); 
#endif

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "adafruit_qtpy_rp2040.h"

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 12 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#endif

#ifdef PICO_DEFAULT_WS2812_POWER_PIN
#define LED_PIN PICO_DEFAULT_WS2812_POWER_PIN
#else
// default to pin 11 if the board doesn't have a power WS2812 pin defined
#define LED_PIN 11
#endif