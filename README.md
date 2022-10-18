University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Lab2A-Worked-with-Sushrut-Salil-Thakur

University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Juilee Samir Kotnis
    Tested on: Lenovo Legion , 8 GB ram (15.6-inch, 2020), Windows 11
        
Answers to Questions in Section 3.2 of the Lab 2A assisgnment:
    
Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Bit banging is a method of data transmission using software instead of dedicated hardware to generate transmitted signals and process received signals through GPIO pins.Since more communication errors like glitches and jitters occur when bit banging is used especially when data communication is being performed by the processor at the same time as other tasks. 

What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

Compared to PIO hardware GPIO can be used in cases where low priority tasks such as switching on a LCD display which does not need to be done in a loop and is not time critical.

How do you get data into a PIO state machine?

There is a TX First in First Out register in every state machine which will store the dta loaded by the software and then the state machine is able to read data from this register.

How do you get data out of a PIO state machine?

There is a RX First in First Out register in every state machine which will send the data and the state machine will read it form this register.

How do you program a PIO state machine?

The PIO has 4 independent state machines whcih share instruction memory. When the software loads data in this instruction memory, it sets the input/output mapping and thus programs a PIO state machine.

In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

'pio_sm_put_blocking' function in the code sets the colors to the builtin LED. We need to first incluse the sdk of the pico-examples. Then add that pico sdk link libraries to the CMakeLists.txt file: picostdlib.h and hardware/pio.h b. In the main code call the pio_sm_put_blocking functions with the following parameters: pio instance, state machine instance, 32 bit color data.

What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 

The pioasm is an assembler which translates the assmebly code from the pio.h file into the binary code which needs to to be stored in the state machine. In the CMake file there is a function pico_generate_pio_header(TARGETPIO_FILE) which invokes the Pioasm, which makes it easier as we dont have to invoke it from the SDK.

