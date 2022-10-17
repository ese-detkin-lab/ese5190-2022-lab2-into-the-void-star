#ifndef _WS2812_H
#define _WS2812_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "../generated/ws2812.pio.h"
#include "boards/adafruit_qtpy_rp2040.h"

void set_neopixel_color(uint32_t color);

#endif