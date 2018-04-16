# ReFlex: Remote Flash == Local Flash

## Take away

- https://github.com/stanford-mast/reflex
  - https://github.com/anakli
- **https://alexpucher.com/blog/** real workload, simulators etc.
- https://github.com/spdk/spdk Storage Performance Development Kit
- avoids interrupt overhead by polling for network packet arrivals and Flash completions  
- use adaptive batching to have balance between throughput and latency (from IX)
- https://github.com/leverich/mutilate load generator for memcached


## TODO

- [ ] like RDMA (Remote Direct Memory Access)
- [ ] RAMCloud?
  - the authors are all in the platform lab
- [ ] DPDK?
  - [ ] DPDK is not Linux
- [ ] AWS EBS
- [ ] can NVMe go from PCIE direct to NIC without going through memory
- [ ] replication? let application handle it?

## Ref

- IX a protected dataplane operating system project https://github.com/ix-project/ix
- Dune: Safe user-level access to privileged cpu features
  - https://github.com/project-dune/dune

## Abstract

- a software-based system for remote Flash access
- provides nearly identical performance to accessing local Flash
- uses a dataplane kernel to closely integrate networking and storage processing to achieve low latency
- 850K IOPS per core over TCP/IP networking
- 21 us overhead

## Introduction

- NVMe Flash 1 million IOPS at sub 100 us latencies
- can't make fully use, over provision.
- higher total cost of ownership (TCO)

Requirements

- low latency
- high throughput
  - [OLD] software-only, iSCSI
- isolation
- flexibility
  - [OLD] NVMe over RDMA fabrics

Design

- use dataplane design avoid the overhead of interrupts and data copying
- a QoS scheduler that implements priorities and rate limiting

## Background and Motivation

[OLD] Challenges

- high performance at low cost
- predictable performance in the presence of interference

### 2.1 Performance Goals

- low latency
  - linux network stack
  - small data (GFS, HDFS)
- high throughput at low cost
  - 70K IOPS per core iSCSI
  - 75K IOPS libevent and libaio

### 2.2 Interference Management

- predictable performance even when multiple tenants share a device
- Hardware acceleration is not enough

## 3. ReFlex Design

- dataplane
- virutalization in NICs and NVMe Flash devices
- poll-based to avoid interrupts

### 3.1 Dataplane Execution Model

Low Latency

- each thread use a dedicated core with direct and exclusive access to a network queue pair for packet reception/transmission
- 1-4 network packet reception and flash command submission
- 5-8 flash completion and network packet transmission
- [x] without any additional interruptions or thread scheduling
  - [x] how can you let the server not schedule your thread, keep busy via polling?
  - 'avoids interrupt overhead by polling for network packet arrivals and Flash completions'
- zero-copy by passing pointers to the buffers used to DMA data from the NIC or Flash device

Throughput

- use asynchronous I/O to overlap Flash device latency (50us or more) with network processing for other requests
- use adaptive batching of requests in order to amortize overheads and improve prefetching and instruction cache efficiency, achieving good balance between high throughput and low latency

Monitor to increase / decrease number of threads

- rebalancing does not lead to packet dropping or reordering

### 3.2 QoS Scheduling and Isolation

- a tenant is a logical abstraction for accounting for and enforcing service-level objectives (SLOs)
  - LC latency critical
  - BE best effort
- depends on read/write ratio and total load across all tenants

### 3.2.1 Request Cost Model

IO cost = size / 4KB * C(type, r)

- flash devices provide substantially higher IOPS for read-only loads
- [ ] seem to operate at 4KB granularity
- fit the curve to get C
- linear model
- [ ] the graph (fig 3) does not look linear at all

### 3.2.2 Scheduling Mechanism

- Token management
  - [ ] like a token bucket?
- Scheduling algorithm
- Latency-critical tenants
- Best-effort tenants

## 4. ReFlex Implementation

- server
- client
- control plane

### 4.1 ReFlex Server

- extend IX
  - Dune: user-level CPU virtualization
  - DPDK: http://dpdk.org/
- NVMe driver
  - Intel SPDK
- Dataplane in Fig 2
  - two step, see design
- QoS scheduler
- new? System call

Multi thread?

Security model
- ACL

### 4.2 ReFlex Clients

- user level library
- block device driver for legacy application

### 4.3 ReFlex Control Plane

- local
  - register tenant
  - monitor
- global (not implemented)

## 5. Evaluation

- Arista switch
- https://github.com/leverich/mutilate
- compare with iSCSI

## 6. Discussion

- read/write interference
- hardware support for request scheduling

## 7. Related Work
