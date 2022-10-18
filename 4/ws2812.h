#ifndef ws2812_h
#define ws2812_h

#include <stdio.h>
#include <boards/adafruit_qtpy_rp2040.h>
#include "pico/stdlib.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

void set_neopixel_color(uint32_t color);
void ws2812_init();

#endif