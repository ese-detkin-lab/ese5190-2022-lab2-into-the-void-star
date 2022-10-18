University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Wenxiwei
    Tested on: XiaoXinPro 16ACH 2021
# 3.2
### 1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
One reason is that the timing uncertainty of actually entering an interrupt handler. When the processor is doing the "bit-banging", it cannot be used for other tasks. And also the processor speed is much higher than protocol speed, therefore there will waste mauch time to waiting.

### 2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
GPIO might be a better choice than using the PIO hardware on simpler embedded systems.

### 3. How do you get data into a PIO state machine?
The processor can push data directly into the state machine’s TXFIFO using the pio_sm_put_blocking() function. 

### 4. How do you get data out of a PIO state machine? 
First write a pio code where when we execute an "out" statement, the data is written to the specific pin mentioned in that statement.

### 5. How do you program a PIO state machine?
We need to use these functions, like pio_gpio_init(pio, pin); pio_set_consecutive_pindirs(pio, sm, pin, 1, true);  pio_sm_config c = ws2812_program_default_config(offset); sm_config_sideset_pins(&c, pin); sm_config_out_shift(&c, false, true, rgbw ? 32 : 24); int cycles_per_bit = ws2812_T1 + ws2812_T2 + ws2812_T3; float div = clock_get_hz(clk_sys) / (freq * cycles_per_bit); sm_config_clkdiv(&c, div); pio_sm_init(pio, sm, offset, &c); pio_sm_enable(pio, sm, true).

### 6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
 static inline void put_pixel(uint32_t pixel_grb) {
   pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
   }
   
### 7.  What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
we can use it to build your PIO programs, for you to #include from your C or C++ program. pioasm can also be used directly, and has a few features not used by the C++ SDK, such as generating programs suitable for use with the MicroPython PIO library. And CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET.
   
# 3.3 Photos or scans of annotated code printouts
### ws2812.c
<img width="673" alt="0ebc32f62f73ab1238116e4c5bec5e3" src="https://user-images.githubusercontent.com/114196821/196306979-6ef40198-55a1-471f-9643-4afd3f7d3d89.png">
<img width="669" alt="a222d1380a29db154dd71be7f1d24cc" src="https://user-images.githubusercontent.com/114196821/196307123-e07559ec-7dd9-4e07-bfe8-fffe23a35d8f.png">
<img width="636" alt="820153fe147c1066dbfe9db63ae4b17" src="https://user-images.githubusercontent.com/114196821/196307144-fb02e134-680d-4b98-87b2-8b65939f79dc.png">
<img width="661" alt="6ce74708b866d990e0f17a8ff83e3f9" src="https://user-images.githubusercontent.com/114196821/196307156-68ef2c4e-f693-48ca-a917-3a13b4ae00f8.png">

### generated/ws2812.pio.h
![692268138041952490](https://user-images.githubusercontent.com/114196821/196307753-90ce332d-dc73-482b-a90c-da3b9793dd6c.png)
   
