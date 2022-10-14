University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A


        Name: Sen Luo
        email: luosen@seas.upenn.edu
        Tested on: Razer Blade 15 (15-inch, 2020), Windows 10 21H2

# Introduction

This guide introduces how getting started with Raspberry Pi Pico and how to set up their MS Windows computer. The content is based on the instruction manual https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf. Before we start setting up, we need to install these softwares which are shown below. 

- [Ubuntu](https://ubuntu.com/download/desktop)
- [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)					
- [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
- [CMake](https://cmake.org/download/)
- [Build Tools for Visual Studio 2022](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022)
- [Python 3.10](https://www.python.org/downloads/windows/)
- [Git](https://git-scm.com/download/win)

# Prelab
## Introduction
For this part, you need to install a terminal, a serial console, and a test editor, so that you can replace your Adafruit “Mu” editor with a more powerful text editor and serial console you can use for the rest of the course. 

## Terminal 
For this part, we choose to download Ubuntu and use it as terminal for the rest of the course. 
1. You can simply find Ubuntu in Microsoft Store and download the latest version. 
2. Create a new ".txt" file on your computer
3. Using the terminal to navigate to the folder containing your file, then list the contents of the folder by using "ls".
4. Print the contents of your text file to your terminal window (in UNIX terminals and PowerShell you can use the “cat” command for this; in cmd.exe you can use “type”). 

## Text Editor
For this part, you need to install gVIM(outside the terminal window) as a power for text editor which can help you edit files from the terminal. Or, you can use the built-in Vim by input command "vimtutor". 

## Serial Console
For this part, you need to download PuTTY of latest 64 bits version. The Adafruit tutoeial for Windows is atached here, https://learn.adafruit.com/welcome-to-circuitpython/advanced-serial-console-on-windows. 
1. After you install the PuTTY, you need to find out the channel you are using. Open the device manger, the plug RP2040 board into a USB port. The device manager list will refresh and a new item will appear under Ports(COM&LPT). You will find a different (COM#) after this item in the list. 
2. Under Connection type: choose the botton next to Serial.
3. In the box under Serial line, enter the serial port you found that your board is using.
4. In the box under speed, enter 115200.
5. Once your settings are entered, click "Open" at the bottom of window. Now you are ready to see the results of your code.

# Lab2A: SDK setup
In this part, you will set up your laptop for RP2040 development using the official C/C++SDK, and compile & run example code on your board. The following will be primary reference materials for this part. https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf

## 1. Installing the Toolchain
To build you will need to install these extra tools.
- [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
- [CMake](https://cmake.org/download/)
- [Build Tools for Visual Studio 2022](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022)
- [Python 3.10](https://www.python.org/downloads/windows/)
- [Git](https://git-scm.com/download/win)

### Installing Arm GNU Toolchain
For Arm GNU Toolchain, you should download the file ended with "-eabi.exe".
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/GNU%20Toolchain.png)
Then make sure you click the box "Add path to environment variable" to register the path to the Arm compiler as an environment variable in the Windows shell when prompted to do so.

### Installing CMake
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/Cmake.png)
During the installation add CMake to the system PATH for all users when prompted by the installer.

### Installing Build Tools for Visual Studio 2022
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/VScode.png)
Although the client language in picture is Chinese, it is easy to set up for Visual Studio Installer. Firstly, you only need to install the C++ build tools only. Secondly, you must install the full "Windows 10 SDK" package as the SDK will need to build the pioasm and elf2uf2 tools locally. 

### Installing Python 3.10
During the installation, ensure that it’s installed 'for all users' and add Python 3.10 to the system PATH when prompted by
the installer. You should additionally disable the MAX_PATH length limit when prompted at the end of the Python installation.
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/python3.10.png)

### Installing Git
When installing Git you should ensure that you change the default editor away from vim. 
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/git1.png)

Ensure you tick the checkbox to allow Git to be used from 3rd-party software and, unless you have a strong reason otherwise, when installing Git you should also check the box "Checkout as is, commit as-is", select "Use Windows' default console window", and "Enable experimental support for pseudo consoles" during the installation process.
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/git2.png)
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/git3.png)
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/git4.png)
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/git5.png)

## 2. Getting the SDK and examples on your pc.

### Set up the path and download SDK
Firstly we need to open the "Developer Command Prompt for VS 2022" window from the Windows Menu. Then we download the "pico-sdk" and "pico-examples" from github and make files for them by using following code,

```
	$ C:\Users\pico\Downloads> git clone -b master https://github.com/raspberrypi/pico-sdk.git
	$ C:\Users\pico\Downloads> cd pico-sdk
	$ C:\Users\pico\Downloads\pico-sdk> git submodule update --init
	$ C:\Users\pico\Downloads\pico-sdk> cd ..
	$ C:\Users\pico\Downloads> git clone -b master https://github.com/raspberrypi/pico-examples.git
```


Then set the path to the SDK as follows, 

'C:\Users\pico\Downloads> setx PICO_SDK_PATH "..\..\pico-sdk'

