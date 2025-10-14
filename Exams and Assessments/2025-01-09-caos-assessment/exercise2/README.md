# Exercise 2 — Memory Management

A computer system has a virtual memory with 64 KB (65,536 bytes) of addressable space and a page size of 4 KB (4,096 bytes). The physical memory can hold 4 pages at a time. The Second Chance algorithm is used as the page replacement policy.

Given the following sequence of virtual memory addresses:

* breafly describe the behaviour of the second chance algorithm
* calculate the corresponding page numbers 
* simulate the behaviour of the Second Chance algorithm step by step
* compute the total number of pages faults

Address reference sequence (in decimal):
1050, 8195, 16384, 24576, 8192, 12345, 8195, 16400, 24576, 12350, 8192, 12345, 24575

Initial Conditions:

* The memory starts empty.
* The reference bits for all pages are initially set to 0.
* The pointer starts at the first frame (Frame 0).

**N.B. If you write your solution on paper make sure it is readable.**