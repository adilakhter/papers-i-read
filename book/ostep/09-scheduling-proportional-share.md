# Chapter 09: Scheduling: Proportional Share

## Take away

## TODO

## Crux

- How to share the CPU proportionally

## 9.1 Basic Concept: Tickets Represent Your Share

tip: use randomness, avoid corner cases, lightweight, fast

- use ticket to represent share
  - i.e. A 0-74, B 75-99, scheduler generate random number from 0-99, and pick the process whose ticket range cover the result

## 9.2 Ticket Mechanisms

- ticket currency, user can allocate tickets among his own jobs, and it is converted to global tickets
- ticket transfer
  - [ ] TODO: a client server example, can ticket be passed through the wire? ...
- ticket inflation, temporarily raise or lower the number of tickets it owns

## 9.3 Implementation

- pick a random number
- walk process list

## 9.4 An Example

## 9.5 How To Assign Tickets

- open solution

## 9.6 Why Not Deterministic

- i.e. stride scheduling
- no global state

## 9.7 Summary

- not widely adopted as MLFQ
- used in VM etc.

## References

- Why Numbering Should Start At Zero
  - from Dijkstra
- Lottery and Stride Scheduling: Flexible Proportional-Share Resource Management
  - the award wining Ph.D dissertation

## Homework

- `lottery.py`