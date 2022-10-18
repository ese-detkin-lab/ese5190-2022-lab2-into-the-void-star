University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Shu Xu
        shux@seas.upenn.edu
    Tested on: Windows 10 Home

# Overview
In this lab, we will set up our laptops/PC for QT PY RP2040 development using C/C++ SDK. We will first set up our devices with the required environment. Then we will learn the basis of programmable I/O (PIO) modules by studying the RP2040 datasheet, pico SDK datasheet and any other references avaliable online. Finally, we will build our own serial console that interact between user input and onboard Neopixel.

# Part 1 & 2 SDK Set up
The [set up guide](https://github.com/shux3/ese5190_lab2_setups/blob/main/README.md) is based on laptop with Windows Home System shown as below:

  |System        |               Windows 10 Home                   |
  |--------------|-------------------------------------------------|
  |System Version|			21H2			   |
  |System Type	 |   64-bit operating system, x64-based processor  |
  |Processor     |Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz 2.40 GHz|
  
  Notice that there are more than one tools to get your own PC ready for the development using C/C++ SDK.
  
  # Part 3 Talking LED
  In this part, we will go through the datasheet of RP2040 to answer some questions regarding the application of RP2040 modules and build paper models.
  ## Resources
  Here are some useful resources that may help you finish this lab:
  - [Cornell ECE4760 Git Page](https://ece4760.github.io/): In-depth exploration of the PIO and DMA modules.
  - [Harvard free CS50 course](https://pll.harvard.edu/course/cs50-introduction-computer-science): A self-pace free C language course
  - [C reference book](https://publications.gbdirect.co.uk/c_book/)
  - [RP2040 Product Homepage](https://www.raspberrypi.com/products/rp2040/)
  - [RP2040 Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)
  - [Pico SDK Datasheet](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)
  
  ## 3.2 PIO Q&A
  • Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

"Bit-Banging" is a method of data transmission that use software to behave like hardwares to generate signals and set bis directly to hardwares. The key differences between "Bit-Banging" on different devices are timing. As the speed of controller goes up, it becomes harder and harder for all instructions to catch on time. Furthermore, it is expected to run mutiple complicated tasks on our laptop CPUs, any small interupt would cause fatal error to "Bit-Banging".

 • What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

LEDs and pushed buttons.

 • How do you get data into/out a PIO state machine?
	
There are four state machines in a PIO. Each of the state machine has two FIFOs. FIFOs are data queues to transmit pull/push data between PIO and the rest of the components. There are two shift registers connected to these two FIFOs, ISR(input, connected to RX FIFO) and OSR(output, connected to TX FIFO). Notice that these two FIFOs can also be set to transmit in the same direction in order to increase the transmission size of each time.

 • How do you program a PIO state machine?

To program a PIO, first we need to configure PIO properly. Using C, we can use code to transfer the pio file into a header file containing the PIO program binary, helper functions, and other useful information for later programming.
The C program consists of functions such as *pio_sm_put_blocking()* to put states into state machines.
After that *pio_add_program()* is used to find space on PIO instruction memory and load our program on it.
	
 • In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

*pio_sm_put_blocking()* is used to tell PIO to set LED color. It is not directly called from the main code. Instead, a function called *put_pixel()* is called to take in the wanted grb values, and *pio_sm_put_blocking()* is called to configure the presigned pio(either pio0 or pio1) with the corresponding grb values.

 • What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

*pioasm* is the program that handles the assembly program in the .pio file and translate it into the binary program to be loaded into the PIO state machine. In the example, the *pioasm* binary under *build/tools/pioasm* directory, which is built automatically.

## 3.3 Follow the Flow
In this part, we will printout the following two files:
- **ws2812.c**
- **generated/ws2812.pio.h**
Then annotation for each funtion/line will be added to [this printout](https://github.com/shux3/ese5190-2022-lab2-into-the-void-star/blob/main/P3/3.3code_printout.pdf).

## 3.4 Color by number
In this part, I have picked red as my favorite color, and created a [spreadsheet](https://github.com/shux3/ese5190-2022-lab2-into-the-void-star/blob/main/P3/3.4Initial%20PIO0%20register%20states.xlsx) to list the initial values of some registers of RP2040 PIO section.

## 3.5 Modeling Time
In this part, PIO program is studied by following a list of items using charts. The items being included in this [paper model](https://github.com/shux3/ese5190-2022-lab2-into-the-void-star/blob/main/P3/3.5paper_model.pdf) include time interval, instrcution, delay cycles and so on.

## 3.6 Zooming in

## 3.7 Timing Diagram

## Summary for modeling tools
In part 3, we have used both spreadsheets and handwriting models to answer the questions. In general, spreadsheets are feasible to follow dozens of values through different states, but it is kind of rigid to use since you don't have much options other than sheets. Handwriting models, on the other hand, are more flexible to explain abstract ideas and models, while it might be less organized and less efficient while dealing with too much information.

# Part 4 Hello, Blinkenlight
This is the final task of this lab. In [this part](https://github.com/shux3/ese5190-2022-lab2-into-the-void-star/tree/main/P4_code), we will modify the given RP2040 example *hello_usb* and *WS2812* to combine a new project that makes the neopixel blink when users send serial commands. This part is a good practice to build on existing files and modify the code to fit in a different device.

	

