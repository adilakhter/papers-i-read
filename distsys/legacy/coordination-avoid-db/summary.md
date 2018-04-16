# Summary: Coordination Avoidance in Database Systems

## Introduction

> tradition database use serializable isolation provides concurrent operations (transactions) with the illusion of executing in some serial order [15] 
> In this paper we address the central question inherent in this trade-off: when is coordination strictly necessary to maintain application-levle consistency

## Conflicts and Coordination

Example: employee + department table, have unique ID

Serializability: some transactions can not be executed concurrently

Cost: 

- increased latency
- decreased throughput
- unavailability

Benchmark to show that coordination has great cost indeed

## System Model

....

benchmark using TPC-C, bla bla bla
