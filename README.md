# ESE 5190: Intro to Embedded Systems, Lab 2A

Name: James Ciardullo

Dev environment: 2019 16-inch MacBook Pro, MacOS Monterey 12.6

## 3.2 Reading Questions

**• Why is bit-banging impractical on your laptop, despite it having a
much faster processor than the RP2040?**

PC processors keep many instructions on a single core at once, which can cause issues when trying to context switch between hard real time tasks.

**• What are some cases where directly using the GPIO might be a
better choice than using the PIO hardware?**

When working with LEDs or push buttons.

**• How do you get data into a PIO state machine?**

The pull instruction takes one data item from the transmit FIFO buffer, and places it in the output shift register.

**• How do you get data out of a PIO state machine?**

The OSR shifts this data out using an out instruction.

**• How do you program a PIO state machine?**

We can create a .pio file using C to set up the PIO state machine.

**• In the example, which low-level C SDK function is directly
responsible for telling the PIO to set the LED to a new color? How
is this function accessed from the main “application” code?**

The pio\_sm\_put\_blocking() accomplishes this. It is accessed through the put\_pixel() call which is called from pattern\_table[pat].pat(NUM\_PIXELS, t) in the main method, which indexes an array of different patterns and picks a particular subroutine to run, which calls put\_pixel().

**• What role does the pioasm “assembler” play in the example, and
how does this interact with CMake?**

The pioasm builds the PIO program by changing the assembly code into binary for the machine to read. CMake invokes pioasm automatically so the developer doesn’t have to.

## 3.3 Annotated Printouts
I didn't have access to a working printer while doing this part, so I annotated the files directly. Detailed function comments and number markings are written in the [annotated\_ws2812.c](https://github.com/jciardullo/ese5190-2022-lab2-into-the-void-star/blob/main/annotated_ws2812.c) and [annotated\_ws2812.pio.h](https://github.com/jciardullo/ese5190-2022-lab2-into-the-void-star/blob/main/annotated_ws2812.pio.h) files.

## 3.4 Register Spreadsheet
Attached as the [3.4\_Register\_Spreadsheet.xlsx](https://github.com/jciardullo/ese5190-2022-lab2-into-the-void-star/blob/main/3.4_Register_Spreadsheet.xlsx) file.

## 3.5 Paper Model
Handdrawn and scanned as [3.5\_Paper\_Model.pdf](https://github.com/jciardullo/ese5190-2022-lab2-into-the-void-star/blob/main/3.5_Paper_Model.pdf).

## 3.6 & 3.7 Packet Transmission
I combined both problems in a single spreadsheet diagram under [3.6\_&\_3.7\_Packet\_Transmission.pdf](https://github.com/jciardullo/ese5190-2022-lab2-into-the-void-star/blob/main/3.6_%26_3.7_Packet_Transmission.pdf).

## Reflection

In modeling my documents, I had to consider how I would intend to capture all of the important info needed for the different registers/values, as well as weigh the advantages/disadvantages of drawing vs using online software like Google Sheets.

**• What were some strengths/weaknesses of working with paper?**

Working with paper made things quicker to write/draw out. However, it was less neat and readable, and making mistakes took more time to correct.

**• What were some strengths/weaknesses of working with spreadsheets?** 

With a spreadsheet, I was able to quickly correct mistakes and easily redesign my table if necessary. The downside to this is that I could not draw things such as graphs, and the overall process would take me longer.

**• How might you approach this task using other tools available to you?**

In the future, I might consider using other online software to create time graphs associated with logic highs and lows of certain registers.

## 4 hello\_usb\_plus\_led
Files associated with my working code for part 4 of the lab are under the [4\_hello\_usb\_plus\_led](https://github.com/jciardullo/ese5190-2022-lab2-into-the-void-star/tree/main/4_hello_usb_plus_led) directory. I included all of the files that I needed to have in order to compile the main hello\_usb\_plus\_led.c.