# The Zebra Striped Network File System

1994 UCB

## Take away

- A striped network file system is one that distributes file data over more than one file server in the same way that a RAID distributes data over multiple disks
- whereas LFS uses the logging approach at the interface between a file server and its disks, Zebra uses the logging approach at the inerface between a client and its servers

## TODO

- [ ] it seems distributed file system today use redundant copy instead of parity
- [ ] does this have RAID over RAID problem?

## Vocabulary

- tandem 串联

## Compare

- Swift, Bridge
  - stripe data within individual files, only large files benefits from the striping
- NFS
  - For small files, a factor of 3 over NFS
- Sprite
  - For small files, 20%, but mainly due to open and close dominate

## Abstract

- increase throughput by striping file data across multiple servers
- forms all the new data from each client into a single stream
- stripe using an approach similar to log-structured file system
- write parity information in each stripe in the style of RAID disk arrays
- 4-5 times for large files
- 20%-3x for small files

## 1. Introduction

- Zebra is a network file system that uses multiple file servers in tandem
- store parity information in each stripe, allows it to continue operation while any one server in unavailable
- much greater throughput is needed
  - large media, HD video
  - parallel applications
- achieve very high performance using collections of inexpensive computers and disks
- COMPARE: only large file benefits from striping
- borrow from Log structured file system, form new data into a sequential log and stripes across the storage servers, so even small file can benefits.

## 2. Striping in Zebra

- RAID
  - store parity instead redundant copy
- LFS
  - batch small write
- logging

### 2.1 RAID

Problems

- parity mechanism makes small writes expensive
- all the disks are attached to a single machine, so its memory and I/O system are likely to be a performance bottleneck
  - multiple paths must exist between the source or sink of data and the disks so that different paths can be used to reach different disks
  - which turns into a distributed system

### 2.2 Per-File Striping in a Network File System

> A striped network file system is one that distributes file data over more than one file server in the same way that a RAID distributes data over multiple disks

- stripe: a collection of file data that spans the servers
- stripe fragment: portion of a stripe stored on a single server

How to stripe

- per-file striping (naive!)
  - small files are difficult to handle efficiently
  - parity management during updates
    - atomic update of new parity and data
- per-client striping

### 2.3 Log-Structured File Systems and Per-Client Striping

> whereas LFS uses the logging approach at the interface between a file server and its disks, Zebra uses the logging approach at the inerface between a client and its servers

Each client

- organizes its new file data into an append-only log
- compute parity for its own log

Advantages

- servers are used efficiently regardless of file sizes
- parity mechanism is simplified
- parity never needs to be updated because file data are never overwritten in place

A central file manager, separate data and meta (HDFS ... did GFS cite this paper?) but **BigTable** did

Stripe cleaner

## 3. Zebra Components

- clients: machines run application programs
- storage servers: store file data
- file manager: file and directory structure of the file system
- stripe cleaner: reclaim unused space on storage servers

### 3.1 Client

- query file manager to get the location of the data
- log only contains data (blocks and delta)

### 3.2 Storage Servers

- 512 KB fragments

Operations

- store
- append to existing
- retrieve
- delete
- identify

Stripes are immutable once they are complete

### 3.3 File Manager

> the file manager stores all of the information in the file system except for file data

> For each Zebra file there is one file in the file manager’s file system, and the “data” in this file are an array
of block pointers that indicate where the blocks of data for the Zebra file are stored.

- use client naming cache to improve performance
- single point failure, section 6

### 3.4 Stripe Cleaner

- user-level process

## 4. System Operation

- block, C, R, U, D

### 4.1 Communication via Deltas

Deltas

- update deltas
- cleaner deltas
- reject deltas: file manager to resolve race between cleaner and file update

Delta contains

- file identifier
- file version
- block number
- old block pointer
- new block pointer

### 4.2 Writing Files

Write dirty data to server when

- reach threshold age
- cache fills with diry data
- application issues `fsync`
- file manager request for consistency

Communication

- transfer fragments to all of the storage servers concurrently
- to file manager and cleaner to improve performance

**fsync** harms performance pretty much

### 4.3 Reading Files

- fetch block pointer from file manager
- read data from storage server

cache block pointer

### 4.4 Client Cache Consistency

- the Sprite way: **flushing or disabling caches when files are opened**
- *stripe status file*
- clean empty stripe first
- cost-benefit analysis
- special system call to copy data out from stripe to be cleaned
- overhead is not measured under real workload

### 4.6 Conflicts Between Cleaning and File Access

Optimistic way, copy the block and issue cleaner delta, avoid synchronization in the common case where there is no conflict

TBD: Table 1 showing all the possible situation and how they handle them

### 4.7 Adding a Storage Server


## 5. Restoring Consistency After Crashes

- restore consistency after crash

Three new consistency problems

- stripe internally inconsistent
- inconsistent with meta stored in file manager
- cleaner & storage server

Solution

- logging
  - operations in order
- checkpoints
  - internally consistent

### 5.1 Internal Stripe Consistency

- client crashes
- storage server crashes
  - in complete write, discard when up
  - don't contain fragments for new stripes written while it was down
    - query other servers
    - not implemented

### 5.2 Stripes vs Metadata

bla bla bla

### 5.3 Stripes vs Cleaner state

lab lab lab

## 6. Availability

- HA

### 6.3 File Manager Crashes

- store meta on Zebra
- not implemented

## 7. Prototype Status and Performance

- benchmark

## 8. Related Work

- per-file striping
- redundant copy
