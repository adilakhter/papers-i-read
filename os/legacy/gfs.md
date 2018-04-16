# The Google File System

2003 Google

## Take away

- not that simple as I used to think (naive!)

## TODO

- 'co-designing the applications and the file system API benefits the overall system
by increasing our flexibility'
  - it's actually couple the system and application, by sacrificing flexibility to gain easier design and better performance
- [ ] how is the 64 bit chunk handler generated

## Abstract

- fault tolerance
- inexpensive commodity hardware

## 1. Introduction

Observation

- component failures are the norm rather than the exception
- files are huge by traditional standards
- most files are mutated by appending new data rather than overwriting existing data
- co-designing the applications and the file system API benefits the overall system
by increasing our flexibility
  - relax consistency model
  - atomic append

## 2. Design Overview

### 2.1 Assumptions

- system is built from components that fails often, need detect, tolerate, recover
- most are large files, don't optimize for the small amount of small files
- large streaming & small random
- large, sequential write that append data to files
- must efficiently implement well-defined semantics for multiple clients that concurrently append to same file
- high sustained bandwidth is more important than low latency

### 2.2 Interface

- snapshot: create a copy of file/directory at low cost
- record append: multiple clients can append data to the same file concurrently while guaranteeing the atomicity of each individual client's append

### 2.3 Architecture

- single master
  - all meta data
  - *HeartBeat* messages
- multiple chunkservers
  - no client file data cache, rely on underlying file system

Chunk

- 64 bit unique chunk handle created by master when chunk is created
- 3 replicas by default

### 2.4 Single Master

... didn't mention how to solve single point failure?

### 2.5 Chunk Size

- 64 MB
- reduce client master interaction
- keep TCP connection
- reduce size of meta data

Disadvantage

- hot spot in a batch-queue system

### 2.6 Metadata

- file and chunk namspace
  - memory & replicated operation log
- mapping from file to chunks
  - memory & replicated operation log
- locations of each chunk's replicas
  - poll from chunkservers when start up

#### 2.6.1 In-Memory Data Structures

- 65 bytes for each 64 MB chunk

#### 2.6.2 Chunk Locations

- pull when startup
- monitor via HeartBeat

#### 2.6.3 Operation Log

- defines the order of concurrent operations in logical time line
- replicate to multiple servers
- flush in batch
- checkpoint  
  - compact b tree that can be mapped into memory
  - incomplete checkpoint is ignored by recovery code

### 2.7 Consistency Model

#### 2.7.1 Guarantees by GFS

- file namespace mutations are atomic (i.e. file creation)
- data mutations may be writes or record appends
- detect data corruption by checksumming

#### 2.7.2 Implications for Applications

- append rather than overwrite

## 3 System Interactions

### 3.1 Leases and Mutation Order

- master pick a primary chunkserver
- primary pick a serial order for all mutations to the chunk
- primary can ask for extension
- even if the master loses communication with a primary, it can safely grant a new lease to another replica after the old lease expires

### 3.2 Data Flow

- data is pushed linearly along a carefully picked chain of chunkservers in a pipelined fashion
- push to the closest chunkserver
- distance can be accurately estimated from IP addresses

### 3.3 Atomic Record Appends

- [ ] TBD

## 4. Master Operation

- all namespace operations
- manage chunk replicas
- make placement decisions
- balance load
- reclaim unused storage

### 4.1 Namespace Management and Locking

- each master operation acquires a set of locks before it runs

### 4.2 Replica Placement

Policy

- maximize data reliability and availability
- maximize network bandwidth utilization

### 4.3 Creation, Re-replication, Rebalancing

- creation
- re-replication
- rebalancing

.... bla bla bla

### 4.4 Garbage Collection

- if you delete something, it is still on disk until cleaned out

#### 4.4.1 Mechanism

- log the delete
- rename to hidden name that includes the deletion timestamp

#### 4.4.2 Discussion

...

#### 4.5 Stale Replica Detection

- chunk version number

## 5. Fault tolerance and diagnosis

### 5.1 HA

#### 5.1.1 Fast Recovery

#### 5.1.2 Chunk Replication

#### 5.1.3 Master Replication

- Shadow-master
- use DNS

### 5.2 Data Integrity

- checksumming
  - 64 KB blocks, 32 bit checksum

### 5.3 Diagnostic Tools

- logs
- RPC requests and replies

## 6. Measurements

### 6.1 Micro-benchmarks

- 19 machines, 2GB RAM, 80GB disk

### 6.2 Real World Clusters

## 7. Experiences

- linux kernel

## 8. Related Work

- AFS
- use only redundancy, cost most disk space compared with RAID
- use centralized server to simplify the design
- don't aim POSIX, compared with Lustre
- close to NASD architecture
