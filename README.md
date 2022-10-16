University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Yuchen Wang
        wangyuchen0303@gmail.com
    Tested on:  MacBook Pro (14-inch, 2021), macOS Monterey 12.6
---
# Lab WRITEUP
## 3.2 Questions Responses

- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
    
    The custom hardware components take care of specific tasks that the more general multi-tasking CPU is not designed for.

- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
    
    Whilst dealing with something like an LED string is possible using *"bit-banging"*, once your hardware protocol gets faster to the point that it is of similar order of magnitude to your system clock speed, there is really not much you can hope to do. The main case where software GPIO access is the *best* choice is LEDs and push buttons.
    
- How do you get data into a PIO state machine?

    The pull instruction takes one data item from the transmit FIFO buffer, and places it in the *output shift register* (OSR). Data moves from the FIFO to the OSR one word (32 bits) at a time.
    
- How do you get data out of a PIO state machine?

    The OSR is able to *shift* this data out, one or more bits at a time, to further destinations, using an out instruction.

- How do you program a PIO state machine?

    There are two ways to program a PIO state machine, using C++ SDK or MicroPython.
    
- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

    `pio_sm_put_blocking(pio, sm, 1)`
    
     First you have to include the correct headers, and when you run this code, it will link to the corresponding file and find the value from the state machine, then pop out those value from FIFO to LED pins.
     
- What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

   Pioasm was bootstrapped for your programs before building any applications that depend on it. As the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.

---
## 3.3 Annotated Code Printouts

![Image](https://user-images.githubusercontent.com/105755054/196012565-afd1c4de-caf1-4c58-a3e2-f469d011db82.jpeg)

![Image 2](https://user-images.githubusercontent.com/105755054/196012569-53654f26-ae30-4703-b3a4-5bf9b3aa8728.jpeg)

![Image 3](https://user-images.githubusercontent.com/105755054/196012571-f698f843-393e-47d6-b038-8fdac8d70601.jpeg)

![Image](https://user-images.githubusercontent.com/105755054/196012788-df3de967-bf7d-4952-b550-a80a06b085e3.jpeg)

---
## 3.4 Spreadsheet of Initial PIO Register States
![RegistersList pdf-1](https://user-images.githubusercontent.com/105755054/196050204-15c5054d-1764-47c8-b078-31bc4dd3c712.jpg)
![RegistersList pdf-2](https://user-images.githubusercontent.com/105755054/196050208-bf5a4185-40f2-4286-8f0c-38881ef84298.jpg)
![RegistersList pdf-3](https://user-images.githubusercontent.com/105755054/196050211-b99ef704-952c-488b-aab3-231274b23e2a.jpg)
![RegistersList pdf-4](https://user-images.githubusercontent.com/105755054/196050215-d4e2bf67-053e-4b8b-b69e-ff847d3adbb1.jpg)
![RegistersList pdf-5](https://user-images.githubusercontent.com/105755054/196050219-4a86271e-f3e2-45b9-8ee8-65e16d9fc4bb.jpg)

---
## 3.5 Paper Model

![Image](https://user-images.githubusercontent.com/105755054/196055362-e8af9b5c-858f-42a9-abbd-538c12d73a2e.jpeg)

---
## 3.6 Packet Transmission Spreadsheet

---
## 3.7 Polished Timing Diagram

---
## 4 USB+WS2812 Code Folder

This folder is Called Lab2a. 


