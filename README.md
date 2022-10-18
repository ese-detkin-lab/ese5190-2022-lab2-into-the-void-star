University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    SUSHRUT THAKUR   worked with JUILEE SAMIR KOTNIS
    Tested on: Lenovo Legion 5 AMD ryzen 5 , 32 gb ram (15.6-inch, 2022), Windows 11


Code is as follows - 

![1](https://user-images.githubusercontent.com/114092860/196417940-4622d02a-9ff7-4074-b8ab-d916ab4a0c19.png)

![2](https://user-images.githubusercontent.com/114092860/196419252-12c78c78-6be7-4f75-8b04-40cb0eb084c3.png)

![3](https://user-images.githubusercontent.com/114092860/196419264-88785738-baf9-469e-992f-4c88bf692665.png)

![4](https://user-images.githubusercontent.com/114092860/196419290-c96b970d-3c89-45c5-976b-5a18c28c4698.png)

![5](https://user-images.githubusercontent.com/114092860/196419317-4567f16d-331c-449c-8fb2-f7a2e76c61c5.png)

![6](https://user-images.githubusercontent.com/114092860/196419394-46dcc0cd-59e8-4e95-8622-18d92ff40ebb.png)


Questions from Section 3.2

1.Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
Bitbanging is used for data transmission mainly in microcontrollers using software instead of dedicated hardware to generate transmittted signals and process received signals through gpio pins. More communication errors like glitches and jitters occur when bit banging is used especially when data communication is being performed by the microcontroller at the same time as other tasks. 


2.What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
Tasks with are not done frequently like in a loop. Low priority tasks which are not dependent on real time critical deadlines like switching on and off an external peripheral like LCD.

3.How do you get data into a PIO state machine?
In the first shift register we have TX in each state machine in PIO. This register is used to get data which the system software will be able to read. 

4.How do you get data out of a PIO state machine?
In the first shift register we have TX in each state machine in PIO. This register is used to output data which the system software will be able to read. 

5. How do you program a PIO state machine? 
PIO has 4 PIO state machines. All these 4 state machines have shared instruction memory. The system software will handle this via its memory set, then set the i/o mapping and get the PIO running. 

6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
'pio_sm_put_blocking' function in the code sets the colors to the builtin LED. We need to first incluse the sdk of the pico-examples. Then add that pico sdk link libraries to the CMakeLists.txt file: picostdlib.h and hardware/pio.h b. In the main code call the pio_sm_put_blocking functions with the following parameters: pio instance, state machine instance, 32 bit color data.


7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
It is an assembler that translates assembly level code from pio.h file into binary code which is loaded in the state machine. Cmake file has a function pico_generate_pio_header(TARGETPIO_FILE) which invokes the pioasm so we dont need to invoke it from the SDK.



Output GIFS- 


![](https://github.com/sushrut-upenn/ESE-lab-2A-worked-with-Juilee-Samir-Kotnis/blob/main/blinking-color%20(1).gif)


![](https://github.com/sushrut-upenn/ESE-lab-2A-worked-with-Juilee-Samir-Kotnis/blob/main/Serial-and-blinking%20(1).gif)

Spreadsheet link - 
https://github.com/sushrut-upenn/ESE-lab-2A-worked-with-Juilee-Samir-Kotnis/blob/main/3.4-embedded%20spreadsheet%20(1).xlsx
