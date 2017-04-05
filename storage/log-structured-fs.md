# Log Structured File System

1992 Mendel Rosenblum and John K. Ousterhout UCB  

## Take away

## Abstract

- write all modifications to disk sequentially in a log-like structure
- the log is the only on disk structure
- contains index, can be read back from log efficiently
- divide log into *segments*
- *segment cleaner* compress live information from heavily fragmented segments
- Sprite LFS (prototype) use 70% disk bandwidth while Unix use 5-10%
  - [ ] is this compared with the old or the new unix fs? I think should be the new one, they mentioned it in 2.3

## 1. Introduction

- increasing memory size will make most read request hit cache (memory, not CPU cache)
- disk traffic dominate by write
- log contains index
  - [ ] so separated log for index?
- recovery only need most recent portion of the log
- clean policy: generation based, 'segregates older, more slowly changing data from younger rapidly changing data and treats them differently during cleaning'
  - [ ] like Java GC?
- 'Unix systems use only 5%-10% of a disk's raw bandwidth for writing new data; the rest of the time is spent seeking'
  - [ ] spin drive can only do read or write at one time I guess, what about SSD?

## 2. Design for file systems of the 1990's

'File system design is governed by two general forces'

- Technology (Hardware?)
- Workloads (Use scenario?)


### 2.1 Technology

- processor
- memory
- disk
  - transfer bandwidth
  - access time

Processor and Memory are growing exponential rate while disk grow is slow

- crash is infrequent
- [ ] use NVM (nonvolatile RAM), it exists at 1990?

### 2.2 Workloads

- office and engineering
  - random access to small files
- HPC
  - large file sequentially, leave it to hardware, but LSFS also works well

### 2.3 Problems with Existing File Systems

- spread information around the disk in a way that causes too many small accesses
  - **Unix FFS** physically separates different files
  - spent too much time seeking
  - [ ] inode is a bad idea? so LSFS does not have inode?
- write synchronously
  - meta data write is synchronous
  - NFS introduced additional synchronous behavior
  - simplified crash recovery but reduced write performance

Use Unix FFS as counter example, which also represent many other existing file systems

## 3. Log structured file systems

Key idea: buffer

> improve write performance by buffering a sequence of file system changes in the file cache and then writing all the changes to disk sequentially in a single disk write operation

Two issues

- how to retrieve information from the log
- how to manage free space

### 3.1 File Location and Reading

- no sequentially scan though it sounds like due to the term `log`
- outputs **index structures in the log** to permit random-access retrievals
  - [ ] how to do that
- still use inode as Unix FFS
  - **same speed for read once the inode has been found**

Unix FFS

- fixed location for inode

LSFS

- write inode to the log
- **inode map**
  - [ ] size of the map, fixed or variable
  - [ ] where to keep the map, what happens if system crashes
  - divided into blocks and written to log
  - fixed checkpoint region on each disk identifies the location of all the inode map blocks
  - cache active blocks in main memory

A comparison in Figure 1

### 3.2 Free Space Management: Segments

### 3.3 Segment Cleaning Mechanism

### 3.4 Segement Cleaning Policies

### 3.5 Simulation Results

### 3.6 Segment Usage Table

## 4. Crash Recovery

### 4.1 Checkpoints

### 4.2 Roll-Forward

## 5. Experience with the Sprite LFS

### 5.1 Micro-Benchmarks

### 5.2 Cleaning Overheads

### 5.3 Crash Recovery

### 5.4 Other Overheads in Sprite LFS

## 6. Related Work

## 7. Conclusion
