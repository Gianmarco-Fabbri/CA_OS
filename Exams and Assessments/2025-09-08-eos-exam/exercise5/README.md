## Exercise 5 - Kernel Module

You are working on an embedded platform running Embedded Linux, which includes a custom memory-mapped hardware component: a **Fan Controller**. This component allows software to control the operation of a cooling fan connected to the board.

The component is mapped in memory with a control register at the address `0x00090000`.

The control register is a **32-bit** word with the following bit layout:

* *bit 0*: Enable (1 = fan on, 0 = fan off)
* *bit 1-3*: Speed level (0–7; 3-bit field). Each level corresponds to a higher PWM frequency.
* *bit 4-7*: Target temperature in steps of 5°C (from 0 = 0°C to 15 = 75°C).
* *bit 8*: Alarm enable (1 = over-temperature alarm enabled, 0 = disabled)
* *bit 9-15*: Reserved

The fan is automatically adjusted based on the speed level and the target temperature.

Defining `ioctl` commands to:

1. Enable or disable the fan
2. Set the speed level (0–7)
3. Set the target temperature (0–15)
4. Enable/disable the alarm

Provide an implementation of the ioctl function, paying attention to the user/kernel mode memory translation.

HELP 1: You can access the full Linux man pages. [Here](https://www.man7.org/linux/man-pages/dir_all_alphabetic.html), you have full documentation of all system calls, C functions, and Linux commands in alphabetical order.

HELP 2: You have access to a summary of the system calls studied during the course by clicking [here](https://www.smilies.polito.it/system-calls.pdf)

HELP3: You can access the [Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/) to develop this code.
