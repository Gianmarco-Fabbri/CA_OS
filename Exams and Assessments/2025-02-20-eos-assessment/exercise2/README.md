# Exercise 2 - Scheduling


A real-time system consists of three periodic tasks and two aperiodic tasks. The system employs **Rate Monotonic Scheduling (RMS)** for the periodic tasks and uses a **Polling Server** with a fixed budget to handle the aperiodic tasks.

## Task Set

The following periodic tasks are given:

| Task | Period (ms) | Execution Time (ms) |
|------|-------------|---------------------|
| T1   | 20          | 5                   |
| T2   | 50          | 10                  |
| T3   | 100         | 20                  |

A Polling Server is introduced with:

* Period T_s = 40 ms
* Execution Budget C_s = 8 ms

The system must also handle two aperiodic tasks:

| Task | Arrival time (ms) | Execution Time (ms) |
|------|-------------|---------------------|
| A1   | 30          | 6                   |
| A2   | 90          | 10                  |


## Questions

Schedule the periodic and aperiodic tasks using Rate Monotonic Scheduling and the Polling Server. Show how the server executes within its allocated budget and when it can serve the aperiodic tasks.

Determine the response times of the aperiodic tasks   under the polling server mechanism.

If the Polling Server budget is increased to 
10 ms, how would this impact the response times of the aperiodic tasks? Would the system remain schedulable?
