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
For this part, you need to download PuTTY of latest 64 bits version.

