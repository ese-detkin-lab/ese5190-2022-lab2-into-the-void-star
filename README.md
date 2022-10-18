# ESE5190_Lab2A

University of Pennsylvania, ESE 5190: Intro to Embedded Systems
 
 Dvisha Kishore Bakarania
 <br />
 LinkedIn: [Dvisha Bakarania](https://www.linkedin.com/in/dvisha-bakarania-9370b2146?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BNtJBfZpDTEKluhukjP7uqg%3D%3D) 

## **3.2**:

1.Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Bit-banging is hard and even though the processor is much faster than RP2040, the processor isn’t really designed for that. For "bit-banging" one needs to sit the processor in a carefully timed loop, often painstakingly written in assembly, trying to make sure the GPIO reading and writing happens on the exact cycle required and this requires really hard work if indeed possible at all. ). Also, your processor is now busy doing the "bit-banging", and cannot be used for other tasks. If the processor is interrupted even for a few microseconds to attend to one of the hard peripherals it is also responsible for, this can be fatal to the timing of any bit-banged protocol. And due to this, it is not advisable to use bit-banging.

2.What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

For running general purpose softwares, GPIO is used as PIO is not capable of running general purpose softwares.

3.How do you get data into a PIO state machine?

From the transmit FIFO buffer, we take one data item and place it in the output shift register (OSR). This data moves one word at a time (32 bits) from the FIFO to the OSR. The OSR is capable of shifting its data out, one or more bits at a time to further destinations. 

4.How do you get data out of a PIO state machine?

The state machine needs to be told which GPIO or GPIOs to set as output. There are four different pin groups which are used by different instructions in different situations. The GPIO also needs to be told that PIO is in control of it (GPIO function select). PIO can drive the ‘output enable’ line up and down programmatically using certain instructions.

5.How do you program a PIO state machine

The RP2040 has two PIO blocks, each of them with four state machines. Each PIO block has a 32-slot instruction memory which is visible to the four state machines in the block. Our program needs to be loaded into this instruction memory before any of our state machines can run the program. Once the program is loaded, we find a free state machine and tell it to run our program. We can order multiple state machines to run the same program, or tell each state machine to run a different program. The state machine stalls if we don’t provide any data in the TX FIFO, for which it is waiting. We need to write a function to push the data into the TX FIFO. In this way, we can successfully program a PIO state machine.



6.In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

In the example, the pio_sm_put_blocking() function is responsible at the lowest level for telling the PIO to set the LED to a new color. It takes its input from the pixel_rgb. It falls within the put_pixel() function. The put_pixel() function takes its arguments from another function urgb_u32(), which defines the RGB values of the colors to be displayed on the LED.
This function is being accessed using the puts() function. We pass pattern_table[] as an argument for this function. The pattern table lets us access various patterns in which we want our LEDs to blink. In each of these pattern functions, the put_pixel function is being calles. This leads to the color changing action which is required for our program to function.

7.What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

pioasm tool is used to convert the assembler code to binary. We use the CMake function to invoke the pioasm and add the generated header to the include path of our target. The actual function being used it pico_generate_pio_header(TARGETPIO_FILE).


## **3.3:**

**ws2812.c**

![annotate](https://user-images.githubusercontent.com/114099174/196359189-e3124e6f-f716-4df4-ad38-e6d48f870599.png)

![sc2](https://user-images.githubusercontent.com/114099174/196360040-5684455b-66af-4fbc-9f27-c788e86e64e3.png)

![sc3](https://user-images.githubusercontent.com/114099174/196360075-6a9ef7d6-4bed-4683-aa91-a6e2dd1d8749.png)


**ws2812.pio**

![sc4](https://user-images.githubusercontent.com/114099174/196361956-7126eb36-765d-4c9b-9316-4116d74dea26.png)

![sc5](https://user-images.githubusercontent.com/114099174/196361794-4e132bf9-49d1-4174-b431-c3fa40012229.png)

![sc6](https://user-images.githubusercontent.com/114099174/196361806-a9327dfe-67b8-487a-8f7d-585d59911ab4.png)

![sc8](https://user-images.githubusercontent.com/114099174/196362727-d8b758d1-3752-40ee-b179-39ae1111d429.png)

![sc9](https://user-images.githubusercontent.com/114099174/196362789-f35b7447-e0d5-476f-b591-3a489e1f4a35.png)


## **3.4**

The link to the Excel sheet acn be found here: [3.4_color_by_number](https://github.com/dvishab/ESE5190_Lab2A/files/9807554/3.4.xlsx) 

## **3.5**

![3 5_1](https://user-images.githubusercontent.com/114099174/196369240-d4bb2d29-c2a6-42e2-8c17-e84d4f82b8e3.jpeg)

![3 5_2](https://user-images.githubusercontent.com/114099174/196369328-0fe6fb5f-924d-4ff4-9533-ea59a031706c.jpeg)


## **3.6-3.7**

This spreadsheet contains the register value over the packet transmission. Follow this link: [3.6-3.7](https://github.com/dvishab/ESE5190_Lab2A/files/9807802/3.7-3.6.xlsx)

## **4**


![WhatsApp_Video_2022-10-18_at_6_03_00_AM_AdobeExpress](https://user-images.githubusercontent.com/114099174/196410152-f4b6a20a-5e66-4fc0-b24f-b9c6f4a612ad.gif)

