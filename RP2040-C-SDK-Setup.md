# RP2040-C-SDK-Setup Guide for Mac with Apple Silicon
This setup guide is tested on MacOS 12.6, MacBook Air M1, 2020

Here are the specific steps:
1. Since computer may not have HomeBrew as default, install it at first.
Pay attention: we should use HomeBrew in x86 version.

```
$ /bin/bash -c $ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```
2. Install Cmake

```
brew install cmake
```
3. Install the toolchain depends on Homebrew
```
$ brew install cmake 
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```

4. Get SDK and examples from the pico-examples repository.
To clone the repositories, start by creating a pico directory to keep all pico related checkouts in:
```
$ cd ~/ 
$ mkdir pico
$ cd pico
```
Then clone the pico-sdk and pico-examples git repositories:
```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
```
Then update the SDK:
```
$ cd pico-sdk
$ git pull
$ git submodule update
```
5. Install Visual Studio Code 2022 from its website

6. Build "Hello World"

Change directory into the hello_world directory inside the pico-examples/build tree, and run make:
```
$ cd hello_world
$ make -j4
```
This will build two separate examples programs in the hello_world/serial/ and hello_world/usb/ directories.

Connect the Raspberry Pi Pico to your Raspberry Pi using a micro-USB cable, making sure that you hold down the BOOTSEL button to force it into USB Mass Storage Mode.

Drag-and-drop hello_usb.uf2 onto the Mass Storage Device.
RP2040 will reboot, unmounting itself as a Mass Storage Device, and start to run the flashed code.
However, although the "Hello World" example is now running, we cannot yet see the text. We need to connect our host computer to the appropriate stdio interface on the Raspberry Pi Pico to see the output.
We also need to check our usb port:
```
ls /dev/tty.*
```
Mine is:
```
/dev/tty.usbmodem1101
```
We should install minicom to see the text. At this time, we should use our x86 Homebrew to install minicom:
```
% arch -x86_64 brew install minimum
% minimum -b 115200 -o -D /dev/tty.usbmodem1101
```
After that we should see "Hello world!" printed in terminal, line by line.
At this time, we are all done!
