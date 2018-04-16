# Corfu: A distributed shared log

## Ref

- https://github.com/CorfuDB/CorfuDB (I think I starred it because I saw it form @gaocegege)
- https://blog.acolyer.org/2017/05/02/corfu-a-distributed-shared-log/

## TODO

- [ ] why flash device, since it use a log manner, HDD might be more cost-efficient?
  - [ ] what about NVM
- [ ] maximum append throughput is not a function of any single node's I/O bandwidth

## Take away

- a global shared log for total order
- use sequencer for performance, use ? for correctness, separation of concern
- disaggregation data center

## Review on Review

- `seal` operation use epoch, how to avoid time(clock) skew
- 'networked-attached flash with a custom FPGA implementation (server functionality and network protocols entirely in hardware)'
- `seal and snapshot`, using Paxos like to reach agreement on a new client proposed configuration
- use `fill` to put junk value, so the guy with token but didn't use would get error and request new token
  - [ ] ever recycle this?
- use chain replication

## Abstract

- cluster of flash
- provide strong consistency for upper layer application like DB
- single instance 200K appends/sec
- network connected flash devices, eliminating storage servers

## 1. Introduction

- flash is an ideal medium for implementing a scalable shared log, supporting fast,
contention-free random reads to the body of the log and fast sequential writes to its tail.
- cluster of small flash devices are more cost efficient
- each position in the shared log is mapped to a set of flash pages on different flash units
- this map is maintained - consistently and compactly - at the clients
- read/write directly to physical page
  - [ ] chain replication?
- sequencer node give token to avoid contention when append
- client centric
  - throughput (limit by sequencer generating tokens instead of bandwidth of single device)
  - reduce complexity, cost
    - a FPGA prototype
- reconfiguration when device failed
  - pattern after Vertical Paxos
- hole
  - hole-filling
- application
  - KV
  - SMR (state machine replication)
- 400K 4KB reads per second, nearly 200K 4KB append per second over the network

## 2. Motivation

- log is good for flash, for different reason with HDD
  - erase multiple pages
  - wearable
- Hyder, original motivation
  - never implemented
  - diverged
- consensus engine
- partitioned system
  - limited by primary
  - communicate across partition for global ordering?
- spread across server to increase life-span of single SSD

## 3. Design and Implementation

### 3.4 Replication in CORFU

- use chaining protocol a client driven variant of Chain Replication to achieve the safety-under-contention and durability properties

## 6. Related Work

- **our 32-drive X25-V cluster cost $3K**
- partition data across time rather than space
  - [ ] compared with Paxos? they mentioned in 3.4
- Hyder
  - C use sequencer to avoid single point
  - C use mapping instead of striping
