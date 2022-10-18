### 3.2 PIO
*Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?*\
Our PC processors store many hundreds of instructions in-flight on a single core at once, thus disadvantageous when trying to juggle hard real time tasks.

*What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?*\
When frequency is low as in for LEDs and push buttons

*How do you get data into a PIO state machine?*\
*pull* from Tx FIFO to output shift register (OSR)

*How do you get data out of a PIO state machine?*\
*out* from OSR to Rx FIFO

*How do you program a PIO state machine?*\
With PIO ASM, I/O is mapped and state machine is triggered

*In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?*\
`pio_sm_put_blocking`\
by including ‘ws2812.pio.h’ in the code and using ‘put_pixel’ function to input colour value

*What role does the pioasm “assembler” play in the example, and how does this interact with CMake?*\
The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040 application.\
The CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target

### 3.3 Follow the flow
The annotated code is saved by the name of [*3dot3_FollowTheFlow.pdf*](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/3dot3_FollowtheFlow.pdf)\
Please view the file.

### 3.4 Colour by Number
*Which PIO instance is being used?*\
PIO 0

*Which state machine is being used with this PIO instance?*\
SM0

*Which pin is this state machine configured to control?*\
Pin 2

*How long is this state machine’s clock cycle?*\
8 nanoseconds (125MHz)

*How much is this state machine’s clock scaled-down relative to the system clock? (i.e. the “clock divisor”)*\
It is 15.625

*In which direction will this state machine shift bits out of its “output shift register”?*\
Left shift

*Which TxFn is used for sending and RxFn used for receiving?*\
TxF0 and RxF0\
\
The register values are maintained in a spreadsheet named [*3dot4_ColourbyNumber.xlsx*](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/3dot4_ColourByNumber.xlsx)

### 3.5 Modeling Time
*What basic circuitry does a WS2812 LED need to operate?*\
Circuit implemening controls and signal reshaping

*How do you connect a WS2812 to a microcontroller?*\
WS2812: DIN port to GPIO port in RP2040

*How does a WS2812 translate bits to color values?*\
First 24bit data sent, then remaining data is sent to the next pixel through the DO port.

*How do you send a single 1 or 0 bit to the WS2812?*\
Ugh, not sure.

*How many bits does it take to send a single color value?*\
8 for Red component, 8 for green component and 8 for blue component.

*What happens if you send more bits than this in a packet?*\
Only 24 bits retained and rest sent to output port.

*How do you tell a WS2812 you’re done sending data?*\
Reset code for at least 50us

*How do you send data to more than one WS2812 in a chain?*\
Serially.\
\
![image](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/3dot5_ModelingTime.png)

### 3.6 Zooming In
The data is in a spreadsheet named [*3dot6_ZoomingIn.xlsx*](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/3dot6_ZoomingIn.xlsx); please check that out.

### 3.7 Timing Diagram
![image](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/3dot7_TimingDiagram.png)

### 4 Hello, BlinkenLight
The code folder is in the main repository.
I have made changes to the program named `ws2812.c` itself.

### 5 Submission
**What were some strengths/weaknesses of working with paper?**\
*Strengths:*
- Quicker and more in pace with thought process
- Easier becasue of habit

*Weakness:*
- Untidy, not organised overall
- Paper will be wasted since in future, I will probably be referring to online documents.

**What were some strengths/weaknesses of working with spreadsheets?**\
*Strengths:*
- Well sorted, especially for more information
- Editable

*Weakness:*
- Relatively more time-taking

**How might you approach this task using other tools available to you?**
- Online Forums
- Debugging functions (print) in code

**Feedback**\
I recognise the professor's efforts to help us familiarise with different aspects of embedded systems. For his efforts to be truly effective, I believe the worksheet could be concise and clearer, with well defined sections and requirements. Some examples can be solved in the beginning of the lab for us to interpret.
Although there is no problem in asking the TAs for help, I believe it would be better if the tasks were realisable by the student (and partner) alone in a single lab session. It would help us be self reliant. I would rather ask the TAs for simply clarifications.
Lastly, I think it would be great if we could complete the lab related work within the lab session. For worksheets and other similar tasks, wouldn't it be great if we could work on them in class together and ask the professor whenever we are stuck!? That would give us a hands-on of the concept the professor is teaching.
Thank you for putting together the lab.
