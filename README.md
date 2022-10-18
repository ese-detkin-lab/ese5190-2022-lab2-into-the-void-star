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

    `pio_sm_put_blocking( )`
    
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

In this section, the '-' mark at value of each register means reserved bits. Typically, the reserved bits are 0.

![RegistersList pdf-1](https://user-images.githubusercontent.com/105755054/196303985-a43fec52-266b-4753-9e2b-b64c75201475.jpg)

![RegistersList pdf-2](https://user-images.githubusercontent.com/105755054/196304040-262523b5-f352-491c-8b5a-1d5c4c469b47.jpg)

![RegistersList pdf-3](https://user-images.githubusercontent.com/105755054/196304050-264d93b0-a61a-4bb8-b3fa-32529a3b0421.jpg)

![RegistersList pdf-4](https://user-images.githubusercontent.com/105755054/196304054-d83195a2-34e0-4087-bcab-18afa7b36b9e.jpg)

![RegistersList pdf-5](https://user-images.githubusercontent.com/105755054/196304082-8ca30244-a173-456a-85d2-9225e3fdeeca.jpg)


---
## 3.5 Paper Model

<img width="535" alt="Screen Shot 2022-10-17 at 10 48 42" src="https://user-images.githubusercontent.com/105755054/196209326-631d6fe1-1563-4dba-b458-52a19de88699.png">

<img width="574" alt="Screen Shot 2022-10-17 at 10 49 07" src="https://user-images.githubusercontent.com/105755054/196209357-818e3375-fed5-45c2-a731-74495861bc17.png">

<img width="574" alt="Screen Shot 2022-10-17 at 10 48 55" src="https://user-images.githubusercontent.com/105755054/196209379-a80d80df-a9d9-4cf7-94e8-6d008e1d472b.png">

The data sheet is helpful to let us understand how the ws2812 working. Basically, there are three LED(R G B) in series. Additionally, each LED are controlled by 3 bytes (24 bits), and the signal passes through each LED in turn.

![Image](https://user-images.githubusercontent.com/105755054/196055362-e8af9b5c-858f-42a9-abbd-538c12d73a2e.jpeg)
At this diagram above T1, T2, and T3 are equal to 2, 5, and 3 individually.

When the code go through L3 and L8 the FIFO is empty, and there are data in FIFO when the code execute at L4 and L6.

---
## 3.6 Packet Transmission Spreadsheet

![Image](https://user-images.githubusercontent.com/105755054/196237649-b749536e-71ec-4699-99d7-c5d490415a0e.jpeg)

---
## 3.7 Polished Timing Diagram

![Image37](https://user-images.githubusercontent.com/105755054/196304174-58ecaf65-be06-4571-b594-c5ebc394cd97.jpeg)

---
## 4 USB+WS2812 Code Folder

This folder is Called Lab2a. 

## Conclusion
In this experiment, I mainly use pencil and paper to draw pictures, which I feel is different from using electronic equipment. In addition, the data sheet of 2040 and the data sheet of C SDK can be combined to better understand the data transmission mode and working principle of each register.
