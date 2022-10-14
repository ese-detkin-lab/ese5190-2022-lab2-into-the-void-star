# Guide for setting up C SDK and running hello_usb.c example for RP2040 on 2018 Macbook Pro (13-inch, i5) macOS Monterey (version 12.6)

# Step 1) Installing the Toolchain
Used the instructions in the guide https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf in section 9.1.1 for installing the toolchain
Install homebrew and toolchain
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
<img width="567" alt="image" src="https://user-images.githubusercontent.com/114189331/195954893-e6d9603f-784b-42de-8bcb-eaa9620a8d90.png">

$ brew install cmake
$ brew tap ArmMbed/homebrew-formulae 
$ brew install arm-none-eabi-gcc

# Step 2) Download visual studio code
Note - This is not required for the C SDK setup but helps if you want to modify/create your own code.
I had this program installed already but you can install it from https://code.visualstudio.com/download

# Step 3) Pico setup
The guide gives us steps how to run the pico examples mentioned at this repository https://github.com/raspberrypi/pico-examples
After installing the toolchain follow step 3 in the guide

$ cd ~/
$ mkdir pico 
$ cd pico

$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git

$ cd pico-examples 
$ mkdir build
$ cd build

$ export PICO_SDK_PATH=../../pico-sdk
$ cmake ..

This will create a build directory inside pico-examples with the necessary cmake files

go to directrory hello_world (this is where usb -> hello_usb.c code is)

$ cd hello_world
$ make -j4

This will create a bunch of files in usb and serial folders (.elf, .uf2 files etc)
.uf2 file is the one that can be drag and dropped on the USB mountable RP2040

# Step 4) Flashing onto QTPY RP2040
This step is important because we need to put the board into storage mode. To do this we can connect the board through a usb port.
Hold down the boot button and press reset button.
You can now see the board as RPI/RP2 device.
Drag and drop the .uf2 file on the RPI/RP2 board. The board will unmount(eject) itself and start running the code.

# Step 5) See the output on serial console
I used screen as the serial console so I will put instructions to connect to that.
First find your device name by using the following command

$ ls /dev/tty.*

For example my board looks like this
<img width="523" alt="image" src="https://user-images.githubusercontent.com/114189331/195956250-6ecacb9c-ffa3-4ceb-86fb-7fd8d1c0d05d.png">

then use the following command to connect to the serial console at 115200 baud rate
$ screen /dev/tty.usbmodem144101 115200

<img width="540" alt="image" src="https://user-images.githubusercontent.com/114189331/195956569-592572c8-0349-4675-bb84-c338db43a8e0.png">




