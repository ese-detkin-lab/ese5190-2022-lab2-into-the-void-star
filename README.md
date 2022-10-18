University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Zhijing Yao
    Tested on: MacBook Pro (13-inch, 2018), macOS Big Sur 11.7

## 3.2 PIO

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

7) We can use it to build PIO programs, for us to #include from your C or C++ program. pioasm can also be used directly, and has a few features not used by the C++ SDK, such as generating programs suitable for use with the MicroPython PIO library. CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET.


## 3.3 FOLLOW THE FLOW

The link to our annotated code printouts is https://github.com/ZhijingY/ESE519-lab2/blob/main/hw2_writeup/3.3.pdf.

## 3.4 COLOR BY NUMBER

The link to our spreadsheet of initial PIO register states is https://github.com/ZhijingY/ESE519-lab2/blob/main/hw2_writeup/3.4_RegistersList.docx.

## 3.5 MODELING TIME

The link to our electronic paper model is https://github.com/ZhijingY/ESE519-lab2/blob/main/hw2_writeup/3.5.pdf.

## 3.6 ZOOMING IN & 3.7 TIMING DIAGRAM

The link to our complete packet transmission spreadsheet and polished timing diagram is https://github.com/ZhijingY/ESE519-lab2/blob/main/hw2_writeup/3.6_3.7.xlsx.

## 4.0 HELLO, BLINKENLIGHT

The link to my working USB + WS2812 code folder is https://github.com/ZhijingY/ESE519-lab2/tree/main/test.
