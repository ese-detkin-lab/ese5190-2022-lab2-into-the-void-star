University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) Ying Xu
        (TODO) anniexu6@seas.upenn.edu
    Tested on: (TODO) MacBook Air(M1), macOS Big Sur version 11.6

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

##

3.2

• Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Above certain speeds — say a factor of 1000 below the processor clock speed — IRQs become impractical, in part due to the timing uncertainty of actually entering an interrupt handler. 


• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

Whilst dealing with something like an LED string is possible using "bit-banging", once your hardware protocol gets faster to the point that it is of similar order of magnitude to your system clock speed, there is really not much you can hope to do. The main case where software GPIO access is the best choice is LEDs and push buttons.

• How do you get data into a PIO state machine?

Put data into the FIFO_TXn register of the PIO state machine.


• How do you get data out of a PIO state machine? 

The OSR is a staging area for data entering the state machine through the TX FIFO. Data is pulled fromthe TX FIFO into the OSR one 32-bit chunk at a time.


• How do you program a PIO state machine?

Running pioasm on the .pio file and ask it to spit out SDK code and configuring the PIO SM when using the program.


• In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

pio_sm_put_blocking(pio,sm,data)

• What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

we can use it to build your PIO programs, for you to #include from your C or C++ program. pioasm can also be used directly, and has a few features not used by the C++ SDK, such as generating programs suitable for use with the MicroPython PIO library. And CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET.

##

3.3 FOLLOW THE FLOW

ws2812.c



![image](https://user-images.githubusercontent.com/114256663/196360794-c3925af2-80cd-4cfb-8d8b-11c713c27ce4.png)
![image](https://user-images.githubusercontent.com/114256663/196360918-9e946275-6ce9-401b-a2ea-d163311c171c.png)
![image](https://user-images.githubusercontent.com/114256663/196360945-bf6d4822-034f-4a37-8a3d-2a60c3b98d4d.png)


ws2812.pio.h

![image](https://user-images.githubusercontent.com/114256663/196360995-afff3ecc-8e01-42b1-ab8d-5872e657991e.png)
![image](https://user-images.githubusercontent.com/114256663/196361042-5f670421-c243-4e08-a9da-32ad88367e9e.png)
![image](https://user-images.githubusercontent.com/114256663/196361083-42576315-242e-4bef-8f69-724077189e98.png)



3.4 COLOR BY NUMBER

<img width="1100" alt="image" src="https://user-images.githubusercontent.com/114256663/196361243-cb8268c1-4792-4d60-ae2b-a67debcbbbda.png">
<img width="1110" alt="image" src="https://user-images.githubusercontent.com/114256663/196361279-38707571-c132-4f1f-97a0-29fa8498bbf2.png">







3.5 MODELING TIME

o What basic circuitry does a WS2812 LED need to operate?
shift

o How do you connect a WS2812 to a microcontroller?
A serial data input to WS2812

o How does a WS2812 translate bits to color values? o How do you send a single 1 or 0 bit to the WS2812? o How many bits does it take to send a single color value?


o What happens if you send more bits than this in a packet? o How do you tell a WS2812 you’re done sending data?


o How do you send data to more than one WS2812 in a chain?






3.6 ZOOMING IN
















