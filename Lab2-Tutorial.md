Name: Meiyi Yu
PennID: 81304595

This is a detail guide to set up the programming environment for RP2040

## 1. Tools to install first:
#### install Homebrew
```
$  /bin/bash -c "$(curl -fsSL
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```
（ referrence: https://github.com/homebrew/install#uninstall-homebrew ）

#### install toolchain
```
$ brew install cmake
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```

## 2. Set up Pico
If the computer already have pico setted up, jump directly to step 3.

The pico-examples repository (https://github.com/raspberrypi/pico-examples) provides a set of example applications
that are written using the pico-sdk (https://github.com/raspberrypi/pico-sdk). 

#### Create a pico directory:
```
$ cd ~/
$ mkdir pico
$ cd pico
```
#### Clone pico examples and SDK to the directory:
```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
```
Pay attention to the output message about tinyusb module. If error message popped out about tinyusb, you need to troubleshoot it, otherwise the usb connection would be affected.

#### Updating the SDK:
```
$ cd pico-sdk
$ git pull
$ git submodule update
```

## 3. Load and run code on RP2040
### Build the code
We need a 'build' directory to build the code, inside of the pico-examples
```
$ cd pico-examples
$ mkdir build
$ cd build
```
prepare the build repo:
```
$ export PICO_SDK_PATH=../../pico-sdk
$ cmake ..
```
You will see:
```
Using PICO_SDK_PATH from environment ('../../pico-sdk')
PICO_SDK_PATH is /home/pi/pico/pico-sdk
...
...
-- Build files have been written to: /home/pi/pico/pico-examples/build
```
Now you have the build directory all set.

if you already has the directory, just cd into it.
```
$ cd build
```
Find the program you want to load under the build repo, taking hello_world as example:
```
$ cd hello_wolrd
$ make -j4
```
The make -j4 will build the files, it will create two separate examples programs in the hello_world/serial/ and hello_world/usb/ directories
You will see:
```
Scanning dependencies of target ELF2UF2Build
[ 0%] Creating directories for 'ELF2UF2Build'
  .
  .
[ 33%] Linking CXX executable hello_usb.elf
[ 33%] Built target hello_usb
  .
  .
[100%] Linking CXX executable hello_serial.elf
[100%] Built target hello_serial
```
The important files among them are:
• serial/hello_serial.elf, which is used by the debugger
• serial/hello_serial.uf2, which can be dragged onto the RP2040 USB Mass Storage Device (UART serial binary)
• usb/hello_usb.elf, which is used by the debugger
• usb/hello_usb.uf2, which can be dragged onto the RP2040 USB Mass Storage Device (USB serial binary)
Where hello_serial directs stdio to UART0 on pins GP0 and GP1, and hello_usb directs stdio to USB CDC serial.

### Plug in the device 
Now we can plug in the device. If we want to program it under USB mode using hello_usb.uf2, the device should be plugged in under RPI-RP2 mode. To do this:
(reference: https://learn.adafruit.com/adafruit-qt-py-2040/circuitpython)

<img src="https://user-images.githubusercontent.com/84453030/194796162-8852026f-2ab3-4162-b41d-a462956adac9.png" width="600" >

###### Method 1: 
Plug in the device not holding any button, then hold down the BOOT/BOOTSEL button (highlighted in red above), and while continuing to hold it (don't let go!), press and release the reset button (highlighted in blue above). Continue to hold the BOOT/BOOTSEL button until the RPI-RP2 drive appears!
###### Method 2: 
When plugging in, press and hold the BOOTSEL button (highlighted in red above),keep holding it while plugging it into USB, and wait for the drive to appear before releasing the button.

Now, go to the RP1-RP2 folder, drag the hello_usb.uf2 into it. Then the RP1-RP2 will disappear, and it seems nothing happened, but don't fret! Everything is going on, it's just we don't have a place to see it yet.

### See output in serial console
#### Install minicom
This don't need to be down inside the build repo.

```
$ brew install minicom
```
#### Open minicom and connect device
```
minicom -b 115200 -o -D /dev/tty.usbmodem*
```

Now the minicom should pop out and you'll see hello world printed!















