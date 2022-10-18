University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Meiyi Yu
    Tested on: MacBook Pro (13-inch, 2019), macOS Monterey

Included lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)


### 3.2 Questions
##### Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040? 
If using bit-banging, it will continuously consumes the memory and kernel of the PC, while the computer has other tasks to do.  for slower protocols you might be able to use an IRQ to wake up the processor from what it was doing fast enough (though latency here is a concern) to send the next bit(s). But PC-class processors keep many hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks. 

##### What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 
When the frequency is relatively slow, like LED or push buttons.

##### How do you get data into/out of a PIO state machine? 
data --> TX FIFO (pull)--> OSR (out)--> Scratch X register --> GPIO
<img width="600" alt="sm in out" src="https://user-images.githubusercontent.com/84453030/196310096-0ec36f27-5dcb-4d9c-a8ae-95db20eded8c.png">

##### How do you program a PIO state machine? (referrence Yu Feng)
In general: 1. Determine which PIO instance to use(out of 2) PIO pio = pio0; PIO pio = pio1; 2. Assign instructions into instruction memory with sufficient space uint offset = pio_add_program(pio, &program_name_here) 3. Find an available state machine uint sm = pio_claim_unused_sm(pio, true); some_kind_of_program_init(pio, sm, offset, PICO_DEFAULT_LED_PIN); Up to this point, state machine is ready and running.

##### In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 
pio_sm_put_blocking. Accessed from while loop.

##### What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 
The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040
application. Within the SDK we do not need to invoke pioasm directly, as the CMake function pico_generate_pio_header(TARGET
PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET
for us.

### 3.3 Follow the flow
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/blob/main/3.3.pdf

### 3.4 Register Table
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/blob/main/Lab2table.xlsx

### 3.5 .pio main
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/blob/main/3.5.png

### 3.6 Zooming in
![3 6-10](https://user-images.githubusercontent.com/84453030/196324086-12c44d28-0772-47fb-b852-a40b2e117ef7.jpg)
![3 6-2-11](https://user-images.githubusercontent.com/84453030/196327013-01013362-2095-4903-a19f-8dd4190a6a4f.jpg)

Note: WS2812 LED's luminance and voltages are shown as below.
<img width="680" alt="ws2812-led" src="https://user-images.githubusercontent.com/84453030/196325556-b91d7bcd-ffd5-4eab-93aa-92cd9822e97a.png">

### 3.7
![3 7](https://user-images.githubusercontent.com/84453030/196327032-9730b76f-5b62-4476-acf0-fcfb1b0ed6b0.jpeg)

### 4 light the LED and print out message
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/tree/main/WS2812_LED


## Feedback
I really appreciate that professor draft this thorough and detail worksheet for us, to help us approach to a deeper understanding step by step. However, I think the structure can be more brief and instruction can be more clear. 
Firstly, I hope the worksheet can clearly state as 'written part' and 'coding part', it would make the structure more clear and help us better arrange the time before coming to the lab for code checking.
Secondly, I hope the instruction can be more straightforward and clear.
For example, in 3.4 register table, if you could give us just a one-line example for the register table, explaining where to check in the datasheet and how to derive the value, it would be much clearer and save us lots of time being confused. 
Similar in 3.4, 3.5, 3.6, we spent lots of time to figure out what exactly should we present. The instruction is so vague to me, even now I am not sure what we should do in 3.6 and 3.7. I believe it would not only help us better understand the purpose but also help TAs a lot when grading if you could include a sample spreadsheet(showing rows and columns names) and let us fill out the values/waveforms. 
Again, thank you so much for preparing all the lab materials! We've really learned a lot from this lab!
