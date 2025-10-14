# Exercise 4 — Linux kernel module

You are a developer tasked with creating a **character device driver** for a simple I/O device. The device driver must implement the **open**, **close**, **read**, and **write** system calls.

The implementation of these system calls should be **dummy functions** that simply print a message to the **kernel log**.

A key characteristic of this I/O device is that it **requires mutual exclusion** when used. Therefore, the character device must ensure that once a process **acquires** the I/O module, it **blocks any other process** from using the device until the original process **releases it**.


You are allowed to consult the Linux Kernel Module Programming Guide to develop this code [https://sysprog21.github.io/lkmpg/#introductio](https://sysprog21.github.io/lkmpg/#introductio)
