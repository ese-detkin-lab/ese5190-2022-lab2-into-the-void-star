University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Sai Koushik S S
    LinkedIn: https://www.linkedin.com/in/sai-koushik-3bbbb8235/
    koushik@seas.upenn.edu
    Tested on: Lenovo Legion 5i



# Readme

## 3.2

Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
A laptop has many layers of abstraction due to which precise timing cannot be obtained which generates latency. hence, even if the processor in a laptop is powerful, it fails to generate this precise timing, which is required for embedded devices with high switching speeds.

What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
GPIO pins can be used for implementation of standard protocols. For basic requirements, GPIO pins are mostly sufficient.

How do you get data into a PIO state machine? 
Data is transmitted from FIFO to OSR. This is internally connected to the inputs of the state machine.

How do you get data out of a PIO state machine? 
We use an out statement in PIO code to write the bits to a specific pin(s). It works like FIFO pull by setting output direction

How do you program a PIO state machine?
Select among the available 2 PIO instances. Load code to instruction memory. Make a free state machine to run the desired program

 In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
  pio_sm_put_blocking() is used to block the FIFO queue when full. Data is sent to TX FIFO queue, if there is a slot available.
 
 What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
 The assembly C code is described in a easier way using the pioasm assembler. pico_generate_pio_header has to be called in the CMake file to create a header file which invokes pioasm
 
 ## 3.3: Follow the flow:
 ![IMG_0066](https://user-images.githubusercontent.com/64246696/196426266-7b2a6c0c-489e-4ae4-8000-de5cc18ce27d.PNG)
![IMG_0067](https://user-images.githubusercontent.com/64246696/196426270-9a84ea3c-b67d-4b8f-b496-9a4fbe8c6949.PNG)
![IMG_0068](https://user-images.githubusercontent.com/64246696/196430947-24db1dbe-4a72-474e-99b2-bfe30bf599d3.PNG)



## 3.4: Color by Number

Initial register spreadsheet
[3.4 Lab2.xlsx](https://github.com/koushik-sss/ese5190-2022-lab2-into-the-void-star-sai/files/9810214/3.4.Lab2.xlsx)

## 3.5: Modeling Time:
![IMG_0065](https://user-images.githubusercontent.com/64246696/196426568-3ac39330-6e0d-436c-bc07-54213eac2733.PNG)


## 3.6 and 3.7:
[3.7 lab2.xlsx](https://github.com/koushik-sss/ese5190-2022-lab2-into-the-void-star-sai/files/9810230/3.7.lab2.xlsx)

## 4: Hello, Blinkenlight
The repository contains the folder called 'pio' which contains the necessary code: https://github.com/koushik-sss/ese5190-2022-lab2-into-the-void-star-sai/tree/main/pio

Video:


https://user-images.githubusercontent.com/64246696/196428106-24c61d9b-6543-4413-a91d-726137dca013.mp4



## Decisions Taken
This lab was performed after going through several documents and online examples on how a PIO and state machine works.

The readings provided were really useful in understanding the code.
https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf
https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf
https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf


## Reflections
What were some strengths/weaknesses of working with paper?
Strength: easy to edit and follow

What were some strengths/weaknesses of working with spreadsheets?
Weakness: Annoying to navigate

How might you approach this task using other tools available to you?
Taking some time understanding the content in the other tools. Video tutorials help a lot!

 


