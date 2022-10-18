
University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Zeyu Gu
        zeyugu@seas.upenn.edu
    Tested on: Lenovo XiaoXinPro 16ACH 2021, Windows 11 21H2

1. Question 3.2

        https://github.com/zgu74/ese5190-2022-lab2-into-the-void-star/blob/06dd4db49171bd94e975d259e525ef896740e4ad/lab%202_3.2.pdf


        
2. Modeling Decisions
        Color: 0000 0100 1010 1101 0101 0101 0100 1101
       
        Modeling response: 
                What basic circuitry does a WS2812 LED need to operate?

                Intelligent digital port data latch, signal reshaping amplification drive circuit, precision internal oscillator, 12V voltage programmable constant
                current control.
                
                How do you send a single 1 or 0 bit to the WS2812?

                Wide positive pulse for 1, narrow positive pulse for 0, very long negative pulse for latch enable.
                
                How do you tell a WS2812 you’re done sending data?

                A long negative pulse latches the pixel data into the LEDs (RESET).



3. Refllect

        What were some strengths/weaknesses of working with paper?

        Working with paper really makes you focus to understand what is happening from a conceptual level. However, this ends up
        taking a lot of time.
        
        What were some strengths/weaknesses of working with spreadsheets?

        Excel can organize a great amount of registers in a clean format. However, it's not convenient to draw.
        

        I think the data sheet of 2040 and the data sheet of C SDK are very good sources to understand the data transmission mode and working principle of each       
        register.


