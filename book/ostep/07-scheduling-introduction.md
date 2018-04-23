# Chapter 7: Scheduling: Introduction

## Take away

- shortest job first chose turnaround time over response time
- round robin chose response time over turnaround time

## TODO

- [x] how to schedule when there are more than one physical resource, i.e. multiple CPU, multiple block device
  - see Chapter 10, Multiprocessor Scheduling (Advanced)

## Crux

- How to develop scheduling policy
  - assumptions
  - metrics
  - previous approaches

## 7.1 Workload Assumptions

Unrealistic assumptions

- each job runs for the same amount of time
- all jobs arrive at the same time
- once started, each job runs to completion
- all jobs only use the CPU (i.e. they perform no I/O)
- the run-time of each job is known

## 7.2 Scheduling Metrics

Turnaround time as single metric

T_turnaround = T_completion - T_arrival

Another is **fairness**

## 7.3 First In, First Out (FIFO)

Sometimes also called First Come, First Served (FCFS)

- convey effect, a long job comes first and many short job comes behind
  - like in the market when you want to checkout

## 7.4 Shortest Job First (SJF)

- first run the shortest, then next shortest

## 7.5 Shortest Time-to-Completion First (STCF)

- if new job has shorter time, current is stop and new job is run

## 7.6 A New Metric: Response Time

- user are using the program

T_response = T_firstrun - T_arrival

- previous scheduler would give user a long time to response

## 7.7 Round Robin (RR)

- runs a job for a **time slice** (also called scheduling quantum) and switch to the next in queue until the queue is empty
- also called **time-slicing**
- if the slice is too short, cost of context switch would be too large
- fair policy perform poor on turnaround time
  - it's a trade-off

## 7.8 Incorporating I/O

- make use of overlap

## 7.9 No More Oracle

- the assumption that the scheduler knows the length of each job is unrealistic

## 7.10 Summary

Next chapter, multi-level feedback queue, use recent past to predict future

## Homework

- `scheduler.py` simulation