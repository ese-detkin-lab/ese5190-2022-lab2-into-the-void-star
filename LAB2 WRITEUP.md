# Introduction 
This is for the Lab2 of ESE 5190, in which we are getting start with programming by PICO SDK, and trying to understand the lower level work flow in RP2040 behind the high level C programming.
I finished the lab together with teammate Qiwen Luo. 

# Setup
please see readme.md of this repository. 
# 3.2 Q&A
Read Chapter 3 in the Pico C SDK manual, and try to understand how the PIO module is used to communicate with a WS2812 module in the example. Some questions to guide your reading:
• Why is bit-banging impractical on your laptop, despite it having a
much faster processor than the RP2040? 
It would waste a lot of resource and once one cycle is not updated it would cause great uncertainty. 
• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 
When need absolute precision of protocol timing, do a lot of simple, repetitive calculations, need only simple interface to host software. 
• How do you get data into a PIO state machine?
The assembly language pull 
• How do you get data out of a PIO state machine? 
Out 
• How do you program a PIO state machine? 
In .pio file 
• In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How ?  
put_pixel using a put method to put the unit32 data into the fifo
is this function accessed from the main “application” code?
• What role does the pioasm “assembler” play in the example, and
how does this interact with CMake?

# 3.3 Annotated Code

![3 31](https://user-images.githubusercontent.com/44985032/196376373-5d9c392b-d320-459c-9c7c-45d18de3312a.jpg)
![3 32](https://user-images.githubusercontent.com/44985032/196376382-f48aeb1c-8cc6-4577-9352-45d94d0e5d55.jpg)
![3 33](https://user-images.githubusercontent.com/44985032/196376392-fdab6e7e-c2f9-4acc-af85-1e8c33f13da8.jpg)

# 3.4 Register Table 
see attached [PIO datasheet.xlsx](https://github.com/villyye97/ese5190-2022-lab2-into-the-void-star/files/9808359/PIO.datasheet.xlsx)

# 3.5 Paper Model 
![3 5](https://user-images.githubusercontent.com/44985032/196376787-d2550246-a3fe-428e-b782-fccaf20e8b95.jpg)

# 3.6 & 3.7 Pocket Transmission Spreadsheet and Polished Timing Diagram 
I finished this part together with Qiwen Luo so the graph is the same. 

Discussion: 
o What were some strengths/weaknesses of
working with paper?
It is straight-forward; however, it is not automated so it may be extremely inefficient for large programs. 
o What were some strengths/weaknesses of
working with spreadsheets?
1. it is somewhat automated, since we can use the formatting and function to achieve certain tasks; 
2. it could be easily saved electronically. 
3. however, it is still not efficient enough for large programs. 
o How might you approach this task using
other tools available to you?
the compiling and debugging tools of the IDE which could automatically keep track of variables in the program. 
![3 6](https://user-images.githubusercontent.com/44985032/196377219-f90b429b-6166-44a5-b869-474a80d5a721.png)

# 4.2  
I only uploaded my modified files for part 4.2 since the usb_helloworld has been checked off by TAs in the lab session. 

Description: 
I modified the code based on the original WS2812.c file, so that it would allow for an input of keybroad, and no matter what is typed to the putty connection, it would generate a random combination of R,G,B value and reflect the color on the LED of the broad. In other world, type, and see what color the broad can show! Also, as debug tools, the serial connection will also return the key we have typed, and the color we have generated, including its RGB value. 

I would like to name it "blind color box" :)
Example Picture and GIF: 
<img width="505" alt="PART4" src="https://user-images.githubusercontent.com/44985032/196379098-92f0e24e-8a07-4e81-896d-0ed1210e6f32.png">


