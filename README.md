University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

```
Yixuan Wang
LinkedIn: https://www.linkedin.com/in/yixuan-wang-21ba40251/
Tested on: ASUS TUF Gaming F15, Windows 11
```
 
## 3.2

Reading questions: 

**1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?**

 For slower protocols you might be able to use an IRQ to wake up the processor. But when above certain speeds，IRQs become impractical, in part due to the timing uncertainty of actually entering an interrupt handler. And it's a tough job to make sure the GPIO reading and writing happens on the exact cycle required.
 
**2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?**
 
 The main cases where software GPIO access is the best choice is LEDs and push buttons.
 
**3. How do you get data into a PIO state machine?**

For RP2040, each state machine (SM) has four registers, X & Y, and the input and output shift registers (ISR and OSR). There are two FIFOs one for incoming data, the other for outgoing. When you want to get data into the SM, you can first push it to the TX FIFO, and when your state machine is ready for the next chunk of data, it pulls it.
And we can use the “out” instruction to take one bit from the FIFO.(FIFOs are data queues, implemented in hardware. Each state machine has two FIFOs, between the state machine and the system bus, for data travelling out of (TX) and into (RX) the chip. )

**4.How do you get data out of a PIO state machine?**

We can use the "pull" instruction to takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR).Data moves from the FIFO to the OSR one word (32 bits) at a time. 

**5. How do you program a PIO state machine?**
We need to load our program into instruction memory before any of our state machines can run the program. The function pio_add_program() finds free space for our program in a given PIO’s instruction memory, and loads it.

**6.In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?**

`pio_sm_put_blocking` is directly responsible for telling the PIO to set the LED to a new color. This function is accessed from `put_pixel`.

**7.What role does the pioasm “assembler” play in the example, and how does this interact with CMake?**

Programs that translates assembly code into binary are generally referred to as assemblers.The SDK includes an assembler for PIO, called pioasm. The SDK handles the details of building this tool for you behind the scenes, and then using it to build your PIO programs, for you to #include from your C or C++ program. pioasm can also be used directly, and has a few features not used by the C++ SDK, such as generating programs suitable for use with the MicroPython PIO library.But within the SDK you do not need to invoke pioasm directly, as the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.


## 3.3
[ws2812.c](https://github.com/Sharonun/ese5190-2022-lab2-into-the-void-star/blob/main/3.3/ws2812.pdf)

[ws2812.pio.h](https://github.com/Sharonun/ese5190-2022-lab2-into-the-void-star/blob/main/3.3/ws2812.pio.h.pdf)


## 3.4

If I choose RGB:0x001031

then GRB is 0001 0000 0000 000 0011 0001

[spreadsheet of initial PIO register states](https://github.com/Sharonun/ese5190-2022-lab2-into-the-void-star/blob/main/3.4.xls)



## 4.HELLO, BLINKENLIGHT 

[folder](https://github.com/Sharonun/ese5190-2022-lab2-into-the-void-star/tree/main/ws2812)

To make WS2812 example working on RP2040, we need to enable power to LED.
1. find the right pin to set for NeoPixel power

<img width="857" alt="image" src="https://user-images.githubusercontent.com/114169032/196422135-f4c08c17-94dc-4184-9c5a-344a7c629db1.png">

2.initialize this pin via the SDK

`gpio_init(11);` 

3.set the pin as an “output,” and set the pin “high,”

` gpio_put(11, 1);`

And we need to make some changes in the CMakelists file in ws2812 folder to enable usb output.
Add:

`pico_enable_stdio_usb(pio_ws2812 1)`

`pico_enable_stdio_uart(pio_ws2812 0)`




