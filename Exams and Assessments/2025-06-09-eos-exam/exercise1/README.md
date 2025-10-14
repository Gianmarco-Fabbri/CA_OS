# Exercise 1 - FreeRTOS tasks

Create a FreeRTOS project based on the template available here: [HERE](hhttps://baltig.polito.it/teaching-material/02npsov-operating-systems-for-embedded-systems/embedded-os-exercises/FreeRTOSsampleapp).

```
├── App
│   ├── FreeRTOSConfig.h
│   ├── Makefile
│   ├── main.c
│   ├── mps2_m3.ld
│   ├── startup.c
│   ├── uart.c
│   └── uart.h
└── README.md
```
The application must run one periodic task. The task has a period of 500 msec. It generates a random number *n* between 1 and 600 and performs busy waiting for *n* ms. 

Every time the task is scheduled in a period, the system must use a timer to detect if the task exceeds its deadline (the period). If this happens, a message must be printed on the screen. 

**Place the solution in this folder in a subfolder named solution.**

**When you submit your exam, only the App folder must be included in the ZIP.**

Refer to the FreeRTOS documentation here: [https://www.freertos.org/Documentation/00-Overview](https://www.freertos.org/Documentation/00-Overview)
