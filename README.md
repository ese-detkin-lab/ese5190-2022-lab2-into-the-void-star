University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) YOUR NAME HERE
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

## 3.2 

1) The interface speed of WS2812 LED string is 400-1200KHz, but most of the processors on our laptop runs way faster than that. For my laptop, the processor used is 2.3GHz Intel Core i5. In this case, the speed of my processor is almost 2000 times faster than the speed of WS2812 LED string. According to the Pico C SDK manual, bit-banging becomes impractical at this point as it becomes too hard to deal with the timing uncertainty of actually entering an interrupt handler if using IRQ. 

    Besides, when doing bit-banging, the processor becomes busy and cannot deal with other tasks. If the processor is interrupted even for a short period of time for one of the hard peripherals it is also responsible for, this can be fatal to the timing of bit-banging the WS2812 LED. As my processor is almost 2000 times faster than the speed of WS2812 LED string, too much time will be spent idling uselessly in between accessing GPIOs.

2) Directly using the GPIO might be a better choice than using the PIO hardware when working on some simple embedded systems, and when dealing with LED and push buttons.
3) We push the data into the state machine's TX FIFO using functions, like "pio_sm_put_blocking()".
4) To get data out of the state machine, we need to write a pio program, in which we can use "out" instruction to take data bits out of the output shift register (OSR).
5) We write a state machine init function.
