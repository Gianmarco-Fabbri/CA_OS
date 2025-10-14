## Exercise 4 - Memory Management

A virtual memory system uses paging with a two-level page table. The logical address space is 128MB and addresses are byte-addressable. Each logical address is split into 3 parts:  
- `p1`: 9 bits (first-level page table index)  
- `p2`: 10 bits (second-level page table index)  
- `d`: 13 bits (page offset)

The system has a TLB with a **measured hit ratio of 97%**. RAM access time is **250 ns**. Each entry in the page table occupies 4 bytes. No additional structures (e.g., hash tables) are used for faster page lookup.

Given the following informations:

1. Explain what it is meant for "hit ratio".
2. What is the size of a page in this system?
3. How many pages are there in the virtual address space?
4. How many entries are needed in each level of the page table?
5. Calculate the size (in Bytes) of the full page table for a process using 100MB of virtual address space (assume it fully uses those 100MB).
6. Determine the **external fragmentation** and **internal fragmentation** (worst case and average case) and the fragmentation of a process P1 of size 71 MB.
7. Compute the Effective Access Time (EAT) considering the hit ratio and memory access cost.
