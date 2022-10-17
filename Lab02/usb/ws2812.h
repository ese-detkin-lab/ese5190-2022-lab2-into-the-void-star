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

void set_neopixel_color(uint32_t color);
