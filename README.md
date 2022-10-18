University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Zhijing Yao
    Tested on: MacBook Pro (13-inch, 2018), macOS Big Sur 11.7

## 3.2 

# Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

1) The interface speed of WS2812 LED string is 400-1200KHz, but most of the processors on our laptop runs way faster than that. For my laptop, the processor used is 2.3GHz Intel Core i5. In this case, the speed of my processor is almost 2000 times faster than the speed of WS2812 LED string. According to the Pico C SDK manual, bit-banging becomes impractical at this point as it becomes too hard to deal with the timing uncertainty of actually entering an interrupt handler if using IRQ. 

    Besides, when doing bit-banging, the processor becomes busy and cannot deal with other tasks. If the processor is interrupted even for a short period of time for one of the hard peripherals it is also responsible for, this can be fatal to the timing of bit-banging the WS2812 LED. As my processor is almost 2000 times faster than the speed of WS2812 LED string, too much time will be spent idling uselessly in between accessing GPIOs.

2) Directly using the GPIO might be a better choice than using the PIO hardware when working on some simple embedded systems, and when dealing with LED and push buttons.
3) We push the data into the state machine's TX FIFO using functions, like "pio_sm_put_blocking()".
4) To get data out of the state machine, we need to write a pio program, in which we can use "out" instruction to take data bits out of the output shift register (OSR).
5) We need to program a pio configuration file using functions such as pio_gpio_init(pio, pin); pio_set_consecutive_pindirs(pio, sm, pin, 1, true);  pio_sm_config c = ws2812_program_default_config(offset); sm_config_sideset_pins(&c, pin); sm_config_out_shift(&c, false, true, rgbw ? 32 : 24); int cycles_per_bit = ws2812_T1 + ws2812_T2 + ws2812_T3; float div = clock_get_hz(clk_sys) / (freq * cycles_per_bit); sm_config_clkdiv(&c, div); pio_sm_init(pio, sm, offset, &c); pio_sm_enable(pio, sm, true) to configure the state machine arguments.
6) It's the 

   static inline void put_pixel(uint32_t pixel_grb) {
   pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
   }

7) s
