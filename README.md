University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    SIDDHANT MATHUR
    www.linkedin.com/in/siddhantmathur14
    Tested on: HP PAVILION X360, WINDOWS 10 (WSL)



# 3 TALKING LEDs

# 3.2  PIO

Q) Why is bit-banging impractical on your laptop, despite it having a  much faster processor than the RP2040?

- PC-class processors keep hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks. Thus, bit - banging is impractical on a laptop despite it having much higher processor speeds.

Q) What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 

- A PIO state machine gets a lot more done in one cycle than a Cortex-M0+ when it comes to I/O: for example, sampling a GPIO value, toggling a clock signal and pushing to a FIFO all in one cycle, every cycle. However , a PIO state machine is not remotely capable of running general purpose software.

Q)How do you get data into a PIO state machine?

- The state machine needs to be told which GPIO to output to depending on which pin group would be used ( out pin in this case) . Also , the GPIO needs to be told that the PIO is in control of it. Lastly , make sure that the PIO is driving the output enable line high.

Q)How do you get data out of a PIO state machine?

- The RP2040 has two PIO blocks, each of them with four state machines. Each PIO block has a 32-slot instruction memory which is visible to the four state machines in the block. We need to load our program into this instruction memory before any of our state machines can run the program. Once the program is loaded, we find a free state machine and tell it to run our program. 

Q) How do you program a PIO state machine?

- Programming a PIO state machine requires pushing data into the TX FIFO from which it will be transmitted to the state machine and then executed.

Q) In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

- The function pio_sm_put_blocking() writes data to the TX FIFO queue and blocks it if it is full.

Q)What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

- The assmebler compiles Assembly code into a human readable format. CMake function pico_generate_pio_header(TARGET PIO_FILE) invokes pioasm automatically and adding the generated header to the include path of the target TARGET.

# 3.3 FOLLOW THE FLOW

##  ANNOTATIONS FOR ws2812.c

* The code for ```ws2812.c``` has been annotated with comments.

![embedded_c1](https://user-images.githubusercontent.com/114244849/196307976-05af9e2a-d3d2-4847-a077-d6c97631ee3d.JPG)


![embedded_c2](https://user-images.githubusercontent.com/114244849/196308018-2ddacf39-faf4-4dc2-bf59-087eda721dcb.JPG)


![embedded_c3](https://user-images.githubusercontent.com/114244849/196308030-3c1b25bc-5c22-4dd1-a0da-bd543f8170bf.JPG)


![embedded_c4](https://user-images.githubusercontent.com/114244849/196308049-ac4486b3-2af8-4518-99c4-45e7b3e78523.JPG)


![embedded_c5](https://user-images.githubusercontent.com/114244849/196308069-88e2dddb-4e3c-42c7-804f-8d6d05becd84.JPG)



##  ANNOTATIONS FOR ws2812.pio.h

* The code for ```ws2812.pio.h``` has been annotated with comments.

![embedded_h1](https://user-images.githubusercontent.com/114244849/196355989-a4ea90cf-5813-4533-aba3-f1060ab84ee2.JPG)

![embedded_h2](https://user-images.githubusercontent.com/114244849/196356067-867041a5-4a26-4be2-bc4c-af5e2e332eb1.JPG)

![embedded_h3](https://user-images.githubusercontent.com/114244849/196356150-34570339-2ca8-42b2-9cd0-c4048fa06903.JPG)

![embedded_h4](https://user-images.githubusercontent.com/114244849/196356241-aa914f54-79a1-4543-a976-7e1c4b70845a.JPG)

![embedded_h5](https://user-images.githubusercontent.com/114244849/196356300-8d6653ef-a938-448f-bf05-5fac8d3a23b3.JPG)


## 3.4 COLOR BY NUMBER

The Excel file containing all the register  values can be accessed through the given link: [Excel link](https://github.com/Siddmathur14/ese5190-2022-lab2-into-the-void-star/blob/main/ESE519-Spreadsheet.xlsx)

## 3.5  MODELING TIME 

![WhatsApp Image 2022-10-18 at 03 12 39](https://user-images.githubusercontent.com/114244849/196362052-a35447a9-db77-41d2-b68d-aaea8a9abedf.jpeg)


## 3.6 & 3.7  ZOOMING IN AND TIMING DIAGRAM

The Excel File contains timing data for packet transfer to the **ws2812** module :[Excel Link](https://github.com/Siddmathur14/ese5190-2022-lab2-into-the-void-star/blob/main/ESE5190-3.7%20(2).xlsx)

## 4   HELLO BLINKENLIGHT







https://user-images.githubusercontent.com/114244849/196412619-aa4f86cc-6e59-4941-aeed-088d7eb4bb30.mp4



