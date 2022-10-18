University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Chenye Xiong
        Email: xcyxcy@seas.upenn.edu
    Tested on: MacBook Pro (13-inch, M2, 2022), macOS Monterey 12.6

(Chenye Xiong)

# Brief responses to the reading questions in 3.2 of the Pico C SDK manual

### Why is bit-bang impractical on our laptop, despite it having a much faster processor than the RP2040 ?

1. It is too fast. The processor of our laptop isn't designed for this and it has a lot of work to do. In response to the growing distance between processors and memory, PC-class processors is trying to switch rapidly between hard real time tasks. If the processor is busy doing the ""bit-banging", it cannot be used for other tasks.

2. Above certain speeds - say a factor of 1000 below the processor clock speed - IPQs become impartical, in part due to the timing uncertainty of actually entering an interrupt hander.

3. Whilst dealing with something like an LED string is possible using "bit-banging", once your hardware protocol gets faster to the point that it is of similar order of magnitude to your system clock speed, there is not much you can hope to do.

### What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

1. For slower protocols.
2. In early days when processors were much slower and less tasks,the distance between the processor and memory was shorter, or the layer of software and hardware between processor and the outside was less and smaller, the GPIO could be a better choice.
3. On simpler embedded system.
4. LEDs and push buttons.

### How do you get data into a PIO state machine?

1. Loads a program into a PIO's instruction memory.
2. Sets up a PIO state machine to run the program.
3. Interacts with the state machine once it is running.

### How do you get data out of a PIO state machine?

1. The state machine needs to be told which GPIO or GPIOs to output to.
2. The GPIO also needs to be told that PIO is in control of it.
3. If we are using the pin for output only, we need to make sure that PIO is driving the output enable line high. PIO can drive this line up amd down programmatically.

### How do you program a PIO state machine?
1. Loads a program into a PIO's instruction memory.
2. Sets up a PIO state machine to run the program.
3. Interacts with the state machine once it is running.

The main ingredients in this recipe are:
- A PIO program
- Some software, written in C, to run the whole show
- A cmake file describing how these two are combined into a program image to load onto a PR2040-based development board

### In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

 `pio_sm_put_blocking()`

### What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

1. Translating assembly code into binary.
2. Building your PIO programs for you to `#include` from your C or C++ program.
3. It can also be used directly, and it can generate programs suitable for use with the MicroPython PIO library.
4. Within the SDK you do not need to invoke pioasm directly, as the CMake function `pico_generate_pio_header(TARDET PIO_FILE)` takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.

# Part 3.3
Decision:

I annotated the code based on the information on the pico_SDK manual

My annotated code:

(ws2812.h)

<div align=center><img width="800" height="900" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.3%20FLOW/WS2812.C2.jpeg"/></div>
<div align=center><img width="800" height="900" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.3%20FLOW/WS2812.C1.jpeg"/></div>

(ws2812.c)

<div align=center><img width="800" height="900" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.3%20FLOW/WS2812.H2.jpeg"/></div>
<div align=center><img width="800" height="900" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.3%20FLOW/WS2812.H1.jpeg"/></div>

# Part 3.4

Decisions:

I checked the RP2040 datasheet and found all the registers then listed them and their information in my spreadsheet.

My spreadsheet about registers:

[link](https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/SPREADSHEET%20LAB2A.xlsx)

# Part 3.5

Decisions；

I readed the  chapter 3 of pico_c_SDK manual carefully and then learned many items such as the FIFO. I also learned about their functions and when it was used. After annotating the code comprehensively, I drew the charts.


My charts:

<div align=center><img width="800" height="400" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.5%20(2).jpg"/></div>

<div align=center><img width="800" height="500" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.5(3).jpg"/></div>

<div align=center><img width="800" height="500" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.5.jpg"/></div>

# Part 3.6

Decision:

I considered about the delay and the charts in Part 3.5. Also, I assumed the voltage according to the WS2812 datasheet.

<div align=center><img width="800" height="200" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/voltage.png"/></div>

My new spreadsheet:

[link](https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/3.6%20spreadsheet.xlsx)

# Part 3.7

Decision:

I considering the spreadsheet in part 3.6 and drew it on paper.

My TIMING GIADRAM:

<div align=center><img width="800" height="550" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/3.7.jpg"/></div>

## Conclusion:

The weaknesses of working with paper: I can draw the plot clearly and more readable. Also, it is much easier to operate.

The strengths of working with paper: Maybe not very accurate.

The weaknesses of working with spreadsheet: It is a little hard to operate and spend more time.

The strengths of working with spreadsheet: It is accurate and easy to modify.

The tools:

- Some videos about registers in youtube

- Lots of manuals

# Part 4: HELLO, BLINKENLIGHT

1. Creating a new test folder outside the pico-examples folder.
2. Copying documents from pico-examples folder.
3. Modifying CMakelists files.
4. Modifying WS2812 code.
4. Building a new folder inside the test folder.
5. Running the new .uf2 file.

## Creating a new test folder outside the pico-examples folder.

<div align=center><img width="800" height="500" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/new%20folder.png"/></div>

## Copying documents from pico-examples folder.

1. Copying the "pio" folder from the pico-example.
2. Copying the "CMake" folder from the pico-example.
3. Copying the "CMakeLists.txt" file from the pico-example folder.
4. Copying the files which are not folders inside the pico-examples folder.

<div align=center><img width="800" height="350" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/files%20inside%20test.png"/></div>

## Modifying CMakelists files.

1. Modifying CmakeLists.txt which is copied from pico-examples folder.

From:

<div align=center><img width="650" height="400" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/former.png"/></div>

To:

<div align=center><img width="650" height="400" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/after.png"/></div>

2. Modifying the CMakeLists.txt in the ws2812 folder.

- Copying two two lines to the CMakeLists.txt in the ws2812 folder from the CMakeLists.txt in the usb folder in the hello_world folder:

<div align=center><img width="650" height="400" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/hello%20world.png"/></div>

- Changing the path hello_usb to pio_ws2812:

<div align=center><img width="650" height="400" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/cmake%20in%20ws2812.png"/></div>

## Modifying WS2812 code.

1. Changing the pin from 2 to 12 in line 22:

<div align=center><img width="800" height="200" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/pin12.png"/></div>

2. Adding `gpio_init(11)` after `printf("WS2812 Smoke Test, using pin %d", WS2812_PIN)`:

<div align=center><img width="800" height="200" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/int11.png"/></div>

3. Adding 
```
$ gpio_set_dir(11, GPIO_OUT)
$ gpio_put(11,1)

```
after 

```
uint offset = pio_add_program(pio, &ws2812_program)

```
<div align=center><img width="800" height="200" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/add%20gpio.png"/></div>

4. Adding `printf("Hello, world!\n")` inside the `while` loop and outside the `for` loop

<div align=center><img width="800" height="400" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/images/add%20print.png"/></div>

## Building a new folder inside the test folder.

Using terminal and runing several commands which were used in setup.

## Running the new .uf2 file

Draging the .uf2 file into the RP1-RP2 and then using the screen command in terminal, then:

<div align=center><img width="600" height="800" src="https://github.com/xcyxcyxcyxcy/ese5190-2022-lab2-into-the-void-star/blob/main/part4.gif"/></div>

I changed the name of the color to number to make the output more readable.
