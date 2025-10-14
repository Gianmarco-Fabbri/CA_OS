# Exercise 4 - Kernel Module

An embedded platform running embedded Linux is equipped with a custom memory-mapped hardware component consisting of a matrix of 16x16 LEDs that can be used to display digits.

The component is mapped in memory through a control register at address `0x00080000`.

This register is used to control and configure the component. It is a 32-bit word where bits have the following meanings:

* bit 0: enable bit (1: enabled, 0: disabled)
* bit 1-2: colour bits. It allows to configure the colour of the LEDs (00: white, 01: yellow, 10: green, 11: red)
* bit 3: blinking bit (1: blinking, 0: not blinking)
* bit 5-8: blinking rate (it enables setting the blinking rate among 16 possible levels)
* bit 9-12: intensity (it enables setting the LED intensity among 16 possible levels)

We want to manage this device with a kernel module and use the `ioctl` function to configure the device.

Provide an implementation of the skeleton of the kernel module and a full implementation of the ioctl function, paying attention to the user/kernel mode memory translation.

HELP1: You can access the Linux Kernel Module Programming Guide to develop this code [https://sysprog21.github.io/lkmpg/](https://sysprog21.github.io/lkmpg/)

