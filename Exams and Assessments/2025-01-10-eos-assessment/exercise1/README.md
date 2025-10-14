# Exercise 1 — Linux kernel module

An embedded platform running embedded Linux is equipped with a custom memory-mapped hardware component consisting of a matrix of 16x16 LEDs that can be used to display digits.

The component is mapped in memory through the following registers:

* `0x00080000` — control register. This register is used to control and configure the component. It is a 32bit word where bits have the following meanings:
	* bit 0: enable bit (1: enabled, 0: disabled)
	* bit 1-2: color bits. It allows to configure the color of the LEDs (00: white, 01:yellow, 10: green, 11:red)
	* bit 3: blinking bit (1: blinking, 1: not-blinking)
	* bit 5-8: blinking rate (it enables to set the blinking rate among 16 possible levels)
	* bit 9-12: intensity (it enables to set the LED intensity among 16 possible levels)
* `0x00080004` - `0x00080023` is a set of 32 bytes where every bit corresponds to one of the 256 LEDs

	
Write a LINUX device driver (to be tested on a standard LINUX distribution) that can display a digit and implement the following functionalities: 
- Enable/Disable the component when the driver is loaded or unloaded
- Display a digit. The user program must be able to indicate the digit as an integer number, and the kernel module transforms it into a matrix of bits to be configured in the device. You do not need to create the bit mask; declare a data structure containing the bit masks of all digits.

* You can decide how to organize your device driver based on functionalities.  
* Add short comments in your code to explain your choices. 
* Pay attention to the user/kernel mode memory management
* Low-level memory operations must be present in your code. However, to test your code, please place them in a comment and substitute them with equivalent log messages.
* The folder you deliver must be a working project ready to be tested on a Linux machine, including the related Makefile.


You are allowed to consult the Linux Kernel Module Programming Guide to develop this code [https://sysprog21.github.io/lkmpg/#introductio](https://sysprog21.github.io/lkmpg/#introductio)
