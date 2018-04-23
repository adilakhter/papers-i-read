# Chapter 8: Scheduling: The Multi-Level Feedback Queue

## Take away

## TODO

## Crux

- How to schedule without perfect knowledge

## Intro

tip: learn from history is good, but sometimes it's worse than no knowledge at all if not used properly

## 8.1 MLFQ: Basic Rules

- queues with different priority, job in high priority run first, job in same queue round robin
  - Rule 1: If Pr(A) > Pr(B), A run
  - Rule 2: If Pr(A) = Pr(B), A & B RR (round robin)
- how to set priorities?
  - altered based on observed behavior

## 8.2 Attempt #1: How To Change Priority

- Rule 3: when a job enters, placed at highest priority
- Rule 4a: if a job uses up an entire time slice while running, its priority is reduced
  - [x] Is it the shortest job first style? reduce turnaround time?
- Rule 4b: if a job gives up the CPU before the time slice is up, it stays at the same priority level

Problems

- starvation, too many interactive job makes the long running job never have a chance to run after they came to the low PR queue.
- smart user can write program to **game the scheduler**, i.e. issue a useless I/O request right before the end of time slice
- **a program may change its behavior** over time

## 8.3 Attempt #2: The Priority Boost

- Rule 5: After some time period S, move all the jobs in the system to the topmost queue
  - it solved both starvation and change of program behavior
  - the value of `S` is called voo-doo constants by John Ousterhout (the author of log structured file system)

## 8.4 Attempt #4: Better Accounting

- Rule 4: Once a job uses up its time allotment at a given level (regardless of how many times it has given up the CPU), its priority is reduced (i.e. it moves down one queue)

## 8.5 Tuning MLFQ And Other Issues

tip: avoid voo-doo constant, at least leave a configuration file for tunning

- Solaris use 60 queues, slice length from 20 milliseconds to 100, boost every 1s
- FreeBDS uses formula
- i.e. `nice` command

## 8.6 Summary

- multiple level of queues
- use feedback to determine the priority of a given job
- used as base for BSE, Windows NT

## References

- The Design of the Unix Operating System
- Inside Windows NT
- John Ousterhout's Home Page
  - the co-authors met in his class ... 剩下就都是狗粮了

## Homework

- `mlfq.py` simulator