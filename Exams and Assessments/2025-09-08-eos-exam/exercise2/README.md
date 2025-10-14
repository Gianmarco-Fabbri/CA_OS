# Exercise 2: Scheduling:

## 2.1 preemptive and non-preemptive
Explain briefly the difference between preemptive and non-preemptive scheduling.

## 2.2 Priority Based with Round-Robin 

Suppose that the following set of processes, with the length of the CPU burst time given in
milliseconds (ms), are being scheduled using a preemptive, priority-based scheduler with a round-robin scheduling algorithm for processes at the same priority. Each process has a numerical priority (a higher number indicates a higher priority).

| Process  | Priority | Burst     | Arrival  |
|----------|----------|-----------|----------|
| P1       | 3        | 15        | 5        |
| P2       | 2        | 5         | 7        |
| P3       | 3        | 15        | 9        |
| P4       | 4        | 10        | 14       |

In addition to the processes listed, the system has an IDLE task, which consumes no CPU resources and has priority 0.

The length of a time quantum is 5 ms. If a process is preempted, it is placed at the end of the queue of its priority.

1. Show the scheduling order of the processes using a Gantt chart.
2. What is the turnaround time for each process?
3. What is the waiting time for each process?
4. Considering the waiting times, what is the main problem of this scheduling algorithm?