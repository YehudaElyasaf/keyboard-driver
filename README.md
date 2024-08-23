[![License: MIT](https://img.shields.io/badge/license-MIT-C06524)](https://github.com/YehudaElyasaf/keyboard-driver/blob/master/LICENSE)

# Keyboard Driver
USB keyboard driver for Linux.

## Install driver
```
git clone https://github.com/YehudaElyasaf/keyboard-driver/
cd keyboard-driver
make
sudo insmod keyboard_driver.ko
```

## Remove driver
```
sudo rmmod keyboard_driver
```
