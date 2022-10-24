University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) Maxi Liu
        (TODO) 
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

(TODO: Your README)

3.4
<img width="1261" alt="image" src="https://user-images.githubusercontent.com/58932929/196333062-38b37420-ab21-4073-974b-7e9cf1b22687.png">
3.5
Basic circuitry:
<img width="685" alt="image" src="https://user-images.githubusercontent.com/58932929/196333197-e0e73085-7a7b-421f-a8aa-87404ffbb8e2.png">

How do you connect a WS2812 to a microcontroller?
Connect by use, and the data transfer is serial.

How does a WS2812 translate bits to color values?
From the datasheet, we can see that 
<img width="646" alt="image" src="https://user-images.githubusercontent.com/58932929/196334063-118ac902-9d9c-451c-b153-5ef3ceb81b51.png">
There are 3 colors, R,G and B. So we basiclly have 3 8 bits numbers to controll the color.
Attention!!! Here in WS2182, color sequence is GRB not RGB

How do you send a single 1 or 0 bit to the WS2812?
For data input, we can see the data sheet :
<img width="333" alt="image" src="https://user-images.githubusercontent.com/58932929/196334571-fe794f46-4318-4b00-9050-f62c339e27e5.png">

How many bits does it take to send a single color value?
8bits

What happens if you send more bits than this in a packet?
send to next input.

How do you tell a WS2812 you’re done sending data?
<img width="683" alt="image" src="https://user-images.githubusercontent.com/58932929/196334797-1ab517e3-aee0-4693-b2bf-b837293dcb8d.png">
so here we can see there is a 50us time period to endure transmission stall.

How do you send data to more than one WS2812 in a chain?
Like the answers before, input data >24 will goes to next WS2812


.wrap_target
bitloop: 
 L1   out x, 1       side 0 [T3 - 1] ; Side-set still takes place when instruction stalls  
 L2  jmp !x do_zero side 1 [T1 - 1] ; Branch on the bit we shifted out. Positive pulse
do_one: 
 L3  jmp  bitloop   side 1 [T2 - 1] ; Continue driving high, for a long pulse
do_zero: 
 L4   nop            side 0 [T2 - 1] ; Or drive low, for a short pulse
.wrap

<img width="788" alt="image" src="https://user-images.githubusercontent.com/58932929/196341437-fa81d2e7-fc8a-4f75-a402-8a60b0c43aa8.png">

The presentation of part 4:


