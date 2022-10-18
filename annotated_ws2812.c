/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif


//This function writes a colored pixel to the FIFO once there is room.
static inline void put_pixel(uint32_t pixel_grb) {
(35)    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}


//This function converts a set of rgb values into a single value in grb ordering.
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
(34)    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}


//This function cycles through a pattern of red, green, blue, and black, before restarting.
void pattern_snakes(uint len, uint t) {
(30)for (uint i = 0; i < len; ++i) {
(31)    uint x = (i + (t >> 1)) % 64;
(32)    if (x < 10)
(33)        put_pixel(urgb_u32(0xff, 0, 0));
        else if (x >= 15 && x < 25)
            put_pixel(urgb_u32(0, 0xff, 0));
        else if (x >= 30 && x < 40)
            put_pixel(urgb_u32(0, 0, 0xff));
        else
            put_pixel(0);
    }
}

//This function cycles through random color patterns.
void pattern_random(uint len, uint t) {
    if (t % 8)
        return;
    for (int i = 0; i < len; ++i)
        put_pixel(rand());
}


//This function produces a pattern that randomly chooses between black and white.
void pattern_sparkle(uint len, uint t) {
    if (t % 8)
        return;
    for (int i = 0; i < len; ++i)
        put_pixel(rand() % 16 ? 0 : 0xffffffff);
}


//This function cycles through different shades of grey.
void pattern_greys(uint len, uint t) {
    int max = 100; // let's not draw too much current!
    t %= max;
    for (int i = 0; i < len; ++i) {
        put_pixel(t * 0x10101);
        if (++t >= max) t = 0;
    }
}


//This typedef holds an array mapping pattern names to strings.
typedef void (*pattern)(uint len, uint t);
const struct {
    pattern pat;
    const char *name;
} pattern_table[] = {
        {pattern_snakes,  "Snakes!"},
        {pattern_random,  "Random data"},
        {pattern_sparkle, "Sparkles"},
        {pattern_greys,   "Greys"},
};


//The main method starts by initializing and loading our program into a PIO, and then repeatedly picks a random pattern to cycle through.
int main() {
    //set_sys_clock_48();
(1) stdio_init_all();
(2) printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
(3) PIO pio = pio0;
(4) int sm = 0;
(5) uint offset = pio_add_program(pio, &ws2812_program);

(6) ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

(22)int t = 0;
(23)while (1) {
(24)    int pat = rand() % count_of(pattern_table);
(25)    int dir = (rand() >> 30) & 1 ? 1 : -1;
(26)    puts(pattern_table[pat].name);
(27)    puts(dir == 1 ? "(forward)" : "(backward)");
(28)    for (int i = 0; i < 1000; ++i) {
(29)        pattern_table[pat].pat(NUM_PIXELS, t);
            sleep_ms(10);
            t += dir;
        }
    }
}
