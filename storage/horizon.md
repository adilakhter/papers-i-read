# Horizon: Efficient deadline-driven disk I/O management for distributed storage system

## Ref

- http://sbesc.lisha.ufsc.br/sbesc2011/dl60 P57

## TODO

- http://docs.aws.amazon.com/AWSEC2/latest/UserGuide/ebs-io-characteristics.html
- ~~Amazon EBS~~ https://www.youtube.com/watch?v=2wKgha8CZ_w
  - use RAID0, for speed not for redundancy
- reminds of two level scheduling like Mesos

## Abstract

- decentralized management.
- Horizon: A disk scheduler that meets deadlines while providing efficient request re-ordering and keeping efficient disk queues.
- by locally managing disk resources, our system can deliver global throughput and latency targets while efficiently utilizing system resources.

## Introduction

- cloud, share pool of resource
- different workload has different requirement, i.e. database, multimedia
- client treat it as a single store, and don't care if the data is physically located on different machines
- call for a **decentralized solution that makes no assumptions of data layouts and data paths in the system**
  - [OLD] centralized resource management
  - [OLD] black box, use worst assumption
  - multi layer
  - does not require making disk reservations
  - client specify performance target in terms of throughput and latency
  - translate throughput and latency to deadlines
  - assign deadlines at entry point based on workload requirements

Horizon

- real-time disk scheduling algorithm
- [OLD]
  - periodic based can't handle burst
  - inefficient disk queues with only one or two requests
- EDF (Earliest Deadline First)
  - allow efficient re-ordering
- meet 92-99% ddls
- immediately adapts to changes in workload

## 5. Related Work

- [OLD] A storage system is treated as a black box, which leads either to under-utilizing storage resources or inability to support latencies

## 6. Conclusions

- multiple clients sharing a fully distributed storage system
- multi layered approach provides performance target for clients
  - data span multiple disks across multiple nodes
  - does not assume any data layout
- upper layer assign deadline
- low lever Horizon disk scheduler meets deadlines
- global performance target
- locally managing individual disk resources
- Horizon
  - meet 90% deadlines
  - [ ] using disk resources very efficiently by managing disk I/O in terms of disk time
  - both throughput intensive and low-latency bursty workload well
