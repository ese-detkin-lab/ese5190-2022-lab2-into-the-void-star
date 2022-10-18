University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Rongqian Chen
    Tested on: Alienware m15 R2, Windows 10

## 3.2: Questions respond:
• Why is bit-banging impractical on your laptop, despite it having amuch faster processor than the RP2040?  
Because CPU is not good at working with external interrupt, which will interfere the main process. So PIO is a ideal choice for repeat and quick-response works.  
• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?  
The work with low frequency, like buttons and LEDs.  
• How do you get data into a PIO state machine?  
Use TX FIFO   
• How do you get data out of a PIO state machine?  
Use RX FIFO  
• How do you program a PIO state machine?  
Use PIO assembly language  
• In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?  
Function pio_sm_put_blocking(), which push data to the TX FIFO queue and blocks it if it is full.  
• What role does the pioasm “assembler” play in the example, and how does this interact with CMake?  
The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040 application, which is easier to read.   

If you use CMake to built the pico-examples repository at any point, you will likely already have a pioasm binary in your build directory, located under build/tools/pioasm/pioasm, which was bootstrapped for you before building any applications that depend on it.  

## 3.3: Photos or scans of annotated code printouts
<img src="https://user-images.githubusercontent.com/43904091/196311475-c432f835-f4be-4434-b6fc-fca20a870a00.jpg" width=60% height=60%>
<img src="https://user-images.githubusercontent.com/43904091/196311843-0772d974-db0a-425e-9164-4eaa60422255.jpg" width=60% height=60%>
<img src="https://user-images.githubusercontent.com/43904091/196311978-7848be81-21b6-4b02-bc27-170a9ef38db9.jpg" width=60% height=60%>
<img src="https://user-images.githubusercontent.com/43904091/196312008-7c79594e-1e1f-4559-a0de-417f08f87bf9.jpg" width=60% height=60%>
<img src="https://user-images.githubusercontent.com/43904091/196312046-39b14045-c51e-44eb-b0ef-7210522950ba.jpg" width=60% height=60%>

## 3.4: spreadsheet of initial PIO register states

![sheet1](https://user-images.githubusercontent.com/43904091/196312357-ba4b0863-7209-4f46-a40e-6da4ffb67107.png)
![sheet2](https://user-images.githubusercontent.com/43904091/196312436-ca3c9b54-b532-4a8b-8d44-ae7321539ca5.png)
![sheet3](https://user-images.githubusercontent.com/43904091/196312446-73aa62f8-8de3-4de6-975d-a3a0283dff30.png)

## 3.5: A photo or scan of your paper model

<img src="https://user-images.githubusercontent.com/43904091/196321164-aecb007e-cfed-4e54-bd7a-af883e48e467.jpg" width=80% height=80%>

## 3.6 & 3.7： packet transmission spreadsheet and timing diagram
![1d0a647cb1ac0c1b5477e998113af2e](https://user-images.githubusercontent.com/43904091/196325630-3fc3f7a4-e2c9-43bb-a78c-3fbc013964b8.jpg)

## reflection on the tools
o What were some strengths/weaknesses of working with paper?  
Paper can describe the theory in detail, but it's sometimes abstract to working with paper without experiment.  
o What were some strengths/weaknesses of working with spreadsheets?  
It takes time to make spreadsheet, but it's convenient and clear to navigate information you need.  
o How might you approach this task using other tools available to you?  
It will be helpful to use waveform simulation software on this project.  

## 4 : USB + WS2812 Folder
The folder is here: 

The program drive the LED light change in 3 colors alternatively: Red, Green, and Blue. And the serial is printing the color at the same time.

![LED blink](https://user-images.githubusercontent.com/43904091/196331090-df37d558-a31b-4693-bfd0-7a754d3f077c.gif)
