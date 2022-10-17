# University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

   Name: Yuan Chi
   Tested on: MacBook Air (13-inch, 2019), macOS Monterey 12.6

## Brief responses to the reading questions in 3.2.

1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?<br>
If the processor is interrupted to attend to one of the hard peripherals it is also responsible for, it can be fatal to the timing of any bit-banged protocol. And the ratio between the processor speed and protocol speed is big, so the processor will spend uselessly idling in between GPIO accesses.

2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?<br>
