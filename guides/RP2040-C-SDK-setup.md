## SDK Install and Setup

#### To install the SDK and get examples from GitHub
- Open Ubuntu
- Navigate to default folder, create a new directory and navigate into it
  ```
  $ cd ~/ 
  $ mkdir pico_as 
  $ cd pico_as
  ```
- Clone pico SDK from GitHub repository\
  `$ git clone -b master https://github.com/raspberrypi/pico-sdk.git --recurse-submodules` \
  *--recurse-submodules automatically initialise and update each submodule in the repository, including nested submodules if any of the submodules in the repository have submodules themselves (if you don't do it it now, after cloning navigate into folder and use<br/>`$ git submodule update --init` )
- Clone pico examples from GitHub repository\
  `$ git clone -b master https://github.com/raspberrypi/pico-examples.git`
- Remember to update SDK when a new version is released
  ```
  $ cd pico-sdk
  $ git pull 
  $ git submodule update
  ```

#### To install Toolchain
- Need CMake to build projects; install CMake and GNU Embedded Toolchain for Arm\
  `$ sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential`

#### Build 'Hello, World!' program
- Navigate to the examples folder, create the build folder and navigate into it
  ```
  $ cd pico-examples
  $ mkdir build 
  $ cd build
  ```
- Set PICO_SDK_PATH and prepare cmake build directory
  ```
  $ export PICO_SDK_PATH=../../pico-sdk
  $ cmake ..
  ```  
  *We use .. to generate build system for the source directory
- Navigate to hello_world example \
  `$ cd hello_world/`
- *make* to run the Makefile\
  `$ make -j4` \
  *-j4 for running four (could also decide depending on the number of cores and threads in your device) make jobs in parallel
- Check for the generated files in the serial and usb folders
  ```
  $ ls serial/
  $ ls usb/
  ```
- Upload code; since we are using WSL and not Linux itself, we will not use the common command line inctructions to flash the code. Instead we will fetch the relevant file from Windows Explorer. Since we need to check the output of the hello_usb.c program, we will navigate to the usb folder and launch the explorer
  ```
  $ cd usb/
  $ explorer.exe `wslpath -w "$PWD"`
  ```
- Connect QT PY by pressing down the BOOT button and inserting into USB port and then releasing the BOOT button; the RPI-RP2 folder appears. Switch to the other Explorer window, copy hello_usb.uf2 and paste in RPI-RP2 folder; the RPI-RP2 folder will disappear.
- Check for a new COM port in ports in Device Manager; for me it is connected to COM11.
- To inspect serial communication, either of the following two
  - Serial monitor in ubuntu
     ```
     $ ls /dev/tty.*
     $ screen /dev/tty.usbmodem14201
     ```
  OR
  - Open Putty and make sure the inputs are as follows
     - Connection type: Serial
     - Connect your RP2040 to the PC.
     - Serial Line should be same as the COM port as the one in Device Manager (for me it is COM11)
     - Speed: 115200
     - Click Open: should open the Serial Console
- **Voila!** Output on the console.
![image](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/img/Lab2_Console Output_p1dot3.png)

*Bit-banging is a process where one emulates an unavailable peripheral using direct port manipulation commands on GPIO pins. One important thing to note with bit-banged designs is that it they are simplest and most robust in circumstances where either the devices being communicated with are waiting on the bit-banging controller to generate all their timing, or where the controller will be allowed to wait, without distraction, for an event to arrive, and where it will be able to do everything it needs to do with that event before any other event arrives that it needs to act upon. They are much less robust in circumstances where a device will need to be able to react to external stimuli within a relatively short time frame, but cannot device 100% of its energy to watching for such stimuli.
REF: https://electronics.stackexchange.com/questions/44670/what-is-bit-banging *
