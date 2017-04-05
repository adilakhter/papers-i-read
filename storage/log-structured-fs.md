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
  - [x] like Java GC? Yeah, mentioned in related work
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

- threading (find the wholes and put into them)
  - severely fragmented
- copy living data out of log to leave large free extents for writing
  - cost for long lived files

Combine threading and copying

- divided into large fixed-size extents called segments
- any given segment is always written sequentially from its beginning to its end
  - [ ] isn't linkedin's new object store stack log above the log of file system
- all live data must be copied out of a segment before the segment can be rewritte
- log is threaded on a segment-by-segment basis
- segment size is chosen large enough that the transfer time to read or write whole segment is much greater than the cost a seek to the beginning of the segment
- **512KB/1MB**
- Unix FFS block size is **4096/512B** (which is much smaller than a segment)

### 3.3 Segment Cleaning Mechanism

The process of copying live data out of a segment is called segment cleaning

- read a number of segments into memory
- identify the live data
  - [ ] TODO: how do you mark some on disk data as delete? are there any in place update?
- write the live data back to smaller number of clean segments

segment summary block

- identify which blocks of each segment are live
- identify the file to which each block belongs and the position of the block within the file
- file number
- block number
- **multiple summary blocks** when more than one log write is needed to fill the segment
- also used for **crash recovery**

Live

- keep version number in the inode map entry for each file, incremented when file deleted or truncated to length zero
- uid = ver + inode number
- summary block record uid for each block, if the uid does not match inode map's, discard the block without examing the
file's inode
  - [ ] TODO: each blocks also contains information about the inode pointing to them? double linked?
- no free block list or bitmap, easy for recovery
  - [ ] TODO: it seems they exists in Unix FFS?

### 3.4 Segment Cleaning Policies

Issues

- When should segment cleaner be executed
- How many segments should it clean at a time
- **Which segment should be cleaned**
  - not the most fragmented
- **How should the live blocks be grouped when they are written out**

write cost: the average amount of time the disk is busy per byte of new data written

- 1.0 perfect
- 10, 1/10 is used for writing, others for seeking, rotational latency, or cleaning

u: utilization of the segments, 0 <= u <= 1,

write cost = 2 / ( 1 - u )

- performance can be improved by reducing the overall utilization of the disk space
- Unix FFS is not sensitive to disk utilization

key: **bimodal segment distribution** where most of the segments are nearly full, a few are empty of nearly empty

### 3.5 Simulation Results

Pattern is harsher than reality

- random access pattern
- locality

Two pseudo random access pattern

- Uniform
- Hot and Cold (90% and 10%)

Simulation

- hot and cold segments must be treated differently by the cleaner
  - **free space in a cold segment is more valuable than in hot segement**
  - once a cold segment has been cleaned it will take a long time before it reaccumulates the unused free space
  - the older the data in segment the longer it is likely to remain unchanged

New Policy: cost-benefit

benefit / cost = free space generated * age of data / cost = (1 - u) * age / (1 + u)

- [ ] TODO: most of the segments cleaned are hot

### 3.6 Segment Usage Table

- number of live bytes in the segment
- the most recent modified time of any block in the segment
- [ ] where does it resides
- [ ] merge it with inode table

## 4. Crash Recovery

traditional Unix file systems without logs must scan all of the metadata structure on disk to restore consistency

- [ ] How do you know where the end of the log is?

### 4.1 Checkpoints

A checkpoint is a position in the log at which all of the file system structure are consistent and complete

- all modified information to the log
- fixed *checkpoint region*
- **two checkpoint regions** in order to handle a crash during a checkpoint operation
- 30s checkpoint interval
- can also use checkpoint by size

### 4.2 Roll-Forward

- try to recover as much as possible, don't discard all non checkpoint data right way
- use information in segment summary blocks to recover recently written file data
- restore consistency between directory entries and inodes
  - outputs a special record in the log for each directory change *directory operation log*
  - appears in the log before the corresponding directory block or inode
  - additional synchronization to prevent directory modifications when checkpoints are being written

## 5. Experience with the Sprite LFS

roll-forward is not deployed in production system, simply discard what has been wrote

### 5.1 Micro-Benchmarks

**the benchmarks are synthetic so they do not represent realistic workloads, but they illustrate the strengths and weaknesses of the two file systems**

This first is optimistic because no cleaning is included

### 5.2 Cleaning Overheads

- over a period of several months on a production system
- production is substantially better than predicted by simulation
  - real world has more locality
  - hot and cold is not that evenly distributed, some code file never got visited

### 5.3 Crash Recovery

### 5.4 Other Overheads in Sprite LFS

## 6. Related Work

- generation based segment cleaning approach like garbage collection in programming languages
- database do not use the log as the final repository for data

## 7. Conclusion
