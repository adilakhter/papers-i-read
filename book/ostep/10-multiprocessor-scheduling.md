# Chapter 10: Multiprocessor Scheduling (Advanced)

## Crux

- How to schedule jobs on multiple CPUs
- How to deal with load imbalance

## 10.1 Background: Multiprocessor Architecture

- cache has both temporal locality and spatial locality
- need to have cache coherency
  - i.e. bus snooping

## 10.2 Don't Forget Synchronization

## 10.3 One Final Issue: Cache Affinity

## 10.4 Single-Queue Scheduling (SQMS)

Pros

- easy

Cons

- requires lock, lack scalability
- cache affinity

## 10.5 Multi-Queue Scheduling

Pros

- increased number of queues reduce lock contention
- better cache affinity

Cons

- imbalance
  - solution: migration, i.e. work stealing

## 10.6 Linux Multiprocessor Schedulers

No common solution

- O(1)
  - use multiple queues
  - priority based
- CFS Completely Fair Scheduler
  - use multiple queues
  - deterministic proportional share
- BFS https://en.wikipedia.org/wiki/Brain_Fuck_Scheduler
  - use single queue

## 10.7 Summary

## References

- The Performance of Spin Lock Alternatives for Shared-Memory Multiprocessors, 1990
- An Analysis of Linux Scalability to Many Cores Abstract, 2010
- Towards Transparent CPU Scheduling, 2011
  - Ph.D students of the authors