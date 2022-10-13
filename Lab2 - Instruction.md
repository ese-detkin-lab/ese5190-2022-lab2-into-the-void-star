Zhuoling Li
MacBook Pro (13-inch, 2018, Four Thunderbolt 3 Ports) 2.3 GHz Quad-Core Intel Core i5
MacOS Monterey Version 12.6

# 1. Tools to install first:
#### install homebrew
$  /bin/bash -c "$(curl -fsSL
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
（ referrence: https://github.com/homebrew/install#uninstall-homebrew ）
#### install toolchain
```
$ brew install cmake
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```
And you will see

