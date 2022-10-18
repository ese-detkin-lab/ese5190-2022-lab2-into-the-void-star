#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hello_usb.pio.h"

#define IS_RGBW true

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 11
#endif

#ifdef PICO_DEFAULT_WS2812_POWER_PIN
#define WS2812_POWER PICO_DEFAULT_WS2812_POWER_PIN
#else
#define WS2812_POWER 12
#endif

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

//break down the color data and reorganiz and set to output
void set_neopixel_color(uint32_t color) {
    uint32_t r_32 = (color & 0xff0000) >> 16u;
    uint32_t g_32 = (color & 0x00ff00) >> 8u;
    uint32_t b_32 = (color & 0x0000ff);
    uint8_t r = r_32;
    uint8_t g = g_32;
    uint8_t b = b_32;
    put_pixel(urgb_u32(r, g, b));
}