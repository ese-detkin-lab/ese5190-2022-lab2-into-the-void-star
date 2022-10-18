# ese5190_lab2_setup guide
University of Pennsylvania, ESE 5190, Lab 2A

    Sugata Sen
        sugatas@seas.upenn.edu
        [linkedin](https://www.linkedin.com/in/sugata-sen/)
    My system: ASUS Zephyrus M16, 11th Gen Intel(R) Core(TM) i9-11900H, Windows 10 64 bit

## The SDK Setup steps : 

To setup the sdk and get going with the hello world serial output code, I followed the RP2040 ["Getting Started guide"](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)

The main steps for building on MS windows systems, is covered in detail in Section 9.2 of the datasheet/guide, and I experienced them as follows :
  
1.  Installed the [**ARM GNU Toolchain**](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/downloads) :
	Here one must look out for the file ending as: -none-eabi.exe.
	![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/65d9e0a39b0d2cb9b73e1e9957a2e2b74b89735a/arm.png)
        Note : Tick the box to register the path to the Arm compiler as an environment variable 

2. Installed [**Cmake**](https://cmake.org/download/#latest) ( i have linked to the latest release for convenience )
	![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/65d9e0a39b0d2cb9b73e1e9957a2e2b74b89735a/cmake.png)
    Note : Add CMake to the system PATH for all users. 

3. Installed [**Build Tools for Visual Studio 2022**](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022)
        
	![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/65d9e0a39b0d2cb9b73e1e9957a2e2b74b89735a/vs.png)
	
	Note : Need the C++ build tools only, add path.
        
4. (Re)installed latest version of Python [**3.10.x**](https://www.python.org/downloads/release/python-3108/) 
    
    ![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/65d9e0a39b0d2cb9b73e1e9957a2e2b74b89735a/python.png)
    Note: Tick "Add python to path", disable the MAX_PATH length limit.
        
5. Installed [**Git 64-bit Setup**](https://git-scm.com/download/win) 

    ![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/65d9e0a39b0d2cb9b73e1e9957a2e2b74b89735a/git.png)
    
	Note: Use preferred editor(Notepad for me), allow Git to be used from 3rd-party software, "Checkout as -is, commit as-is", "Use Windows default console window"
	"Enable experimental support for pseudo consoles", rest as default.
    

## Getting the SDK

Here I used the Developer Command Prompt for VS 2022.

In this part I made a new directory first of the form:

	mkdir picoo
	cd picoo

Then cloned the pico-examples and pico-sdk repositories using the commands :

	git clone -b master https://github.com/raspberrypi/pico-sdk.git
	cd pico-sdk
	git submodule update --init
	cd ..
	git clone -b master https://github.com/raspberrypi/pico-examples.git

## **Building from Command Line, for serial hello world**
     
I used Developer Command Prompt for VS 2022 again and set its path to the SDK as:

	C:\picoo> setx PICO_SDK_PATH "..\..\pico-sdk"
	
Now I must close current Command Prompt, and open a new Developer command prompt, so the environment variable is correctly set.
The code for making the build for all the example codes, by first creating a "pico-examples", and "build" folder:
	
	C:\picoo> cd pico-examples
	C:\picoo\pico-examples> mkdir build
	C:\picoo\pico-examples> cd build
	C:\picoo\pico-examples\build> cmake -G "NMake Makefiles" ..
	C:\picoo\pico-examples\build> nmake


This will start the build process.
![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/65d9e0a39b0d2cb9b73e1e9957a2e2b74b89735a/building.png)

This building process will produce the **elf,bin** and **uf2** targets.  
simply by dragging the uf2 file to our RP2040 board we can flash new code to it. 

NOTE : Here I faced an error when building, saying files "not found", when trying to use VS 2022 but was resolved when I repeated the set path, and opened VS 2022 as administrator.


## **Flashing board and serial output observations**  
    
I connected the RP2040 Raspberry Pi Pico to the computer via USB and held down the **BOOT** button to force it into the USB Mass Storage mode.   
Now it is possible to drag and drop the binary "hello_usb.uf2", we generated in last step.

Note: anytime we want to re-flash the board, we can hold **BOOT**, and click the **RST** button once.

Using PUTTY as setup from lab 1, I found the COM port the board was using, by going to DEVICE MANAGER, and found my new laptop to have no PORTS( COM & LPT),
This was solved by using the menu Action>Add Legacy Hardware>Select from a list>PORTS( COM & LPT)>Communications Port

Now COM4 appears to be active, and setting a baud rate of 115200, we can see serial terminal open up showing :

![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/65d9e0a39b0d2cb9b73e1e9957a2e2b74b89735a/output.png)  
