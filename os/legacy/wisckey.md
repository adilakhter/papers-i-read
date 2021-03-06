# WiscKey: Separating Keys from Values in SSD-Conscious Storage

FAST 2016, UW

## Ref

- https://github.com/dgraph-io/badger a native Golang implementation
- http://pages.cs.wisc.edu/~ll/papers/wisckey-slides.pdf a 100 pages slide ...

## Take away

- Write (read) amplification is defined as the ratio between the amount of data written to (read from) the underlying storage device and the amount of data requested by the user
- Figure3 use a Samsung 840 EVO SSD lol (I got a 850)
- `posix_fadvise`
- `fallocate`

## TODO

- [ ] How do they measure write amplification
  - https://groups.google.com/d/msg/nosql-databases/Qy70HrMZFVU/92lPv0SrCQAJ Cassandra guy say write amplification is not that harmful (现在的SSD耐操)
    - smartctl
  - Flash Reliability in Production: The Expected and the Unexpected (FAST 2016, Google)
  - https://help.ubuntu.com/community/Smartmontools

## Abstract

- 2.5 - 111x faster than LevelDB for loading a database
- 1.6 - 14x faster for random lookups

## Introduction

- K-V is widely used, LSM is the state of the art
  - [ ] what do K-V do if I want to query by value? build external index manually?
- SSD is different than HDD
  - sequential and random is not that different
    - [ ] really?
  - larger degree of internal parallelism
  - wear out through repeated writes
    - LSM write amplification significantly reduce device lifetime
- separation key and value
  - only sort keys, keep values in a log
    - quite like what Ike mentioned for the stock one, only sort the key, and don't move the original data
  - decreased size
- challenges
  - range query
    - use internal parallelism of SSD devices
  - garbage collection of invalid values
    - online and lightweight garbage collector
  - crash recovery
    - [ ] interesting property in modern fs

## 2 Background and Motivation

### 2.1 LSM Tree

Pretty good conclusion

### 2.2 LevelDB

- log
- two sorted skiplist
  - memtable
  - immutable memtable
- 7 level on disk SSTable
  - 10MB, 100MB, 1G, 10G, 100G, 1T

Write

log -> memtable -> immutable  memtable -> L0 -> L1 ....

- log is discarded after the correspond immutable memtable is flushed to L0
- L0 key range has overlap between each other, other levels no.
  - 'all files in a particular level, except L_0, do not overlap in their key-ranges'
  - slow down write in order to compact L_0 to L_1, when there are more than 8 files in L_0

Read

- memtable
- immutable memetable
- all files in L0 (since there is overlap)
- each level

### 2.3 Write and Read Amplification

Write (read) amplification is defined as the ratio between
the amount of data written to (read from) the underlying storage device
and the amount of data requested by the user

- Write amplification over 50
- Read amplification 336
  - [ ] TODO: but I think most time, the index, bloom filter are stored in memory
    - they mentioned it, say this is the case for large database
- [ ] How do they measure write amplification

### 2.4 Fast Storage Hardware

- random write is harmful due to unique erase-write cycle and expensive garbage collection
- when random reads are issued concurrently in an SSD, the aggregate throughput can match sequential throughput for some workloads

## 3. WiscKey

- split key with value, keys in lsm tree, value in log
- use parallel random read of SSD for range query
- unique crash consistency, garbage collection to efficiently manage the value log
- optimize performance by removing the LSM-tree log without sacificing consistency

### 3.1 Design Goals

- [ ] how to build relational database on top of K-V
- support snapshots

### 3.2 Key-Value Separation

- compaction is the major performance cost
- compaction only needs to sort keys, while values can be managed seperately
  - [ ] this can also apply to xephon-k, only sort the upper level (lower granularity)
- keys are usually smaller than values

````
---------------------------------
<key, addr> | <key, addr> | ....
---------------------------------

---------------------------------
value | value | ....
----------------------------------
````

- [ ] keys can be easily cached in modern servers which have over 100-GB of memory

### 3.3 Challenges

#### 3.3.1 Parallel Range Query

- LevelDB provide an iterator-based interface
- Use pre-fetch with multiple threads

#### 3.3.2 Garbage Collection

- need a special garbage collector to reclaim free space in the vLog
  - because compaction only gc keys
- also store key in the value log
- read a chunk, and wrote the new values back to the original position and make some space (update the tail)
  - [ ] TODO: what about the data written at the old tail?
- periodically or threshold

#### 3.3.3 Crash Consistency

- trust that file sytem will recover data in order
- [ ] what about the write ahead logging?
- or it's just talking about file system crash?

### 3.4 Optimizations

#### 3.4.1 Value-Log Write Buffer

- write in large batch to reduce the overhead of system calls
- fist search buffer
- [ ] Isn't this exactly what LSM Tree do ....

#### 3.4.2 Optimizing the LSM-tree Log

- vLog has keys as well, so no need for WAL?
  - [ ] TODO: but they buffer the vLog?
  - [ ] Does LevelDB also buffer their WAL?

### 3.5 Implementation

- [ ] posix_fadvise
- fallocate
  - punching a hole in a file system can fee the physical space allocated?

## Evaluation

- two Xeon E5, 64GB RAM, 500 GB Samsung 840 EVO SSD
- use the `ALICE` tool to create failure?
