# File System Design for an NFS File Server Appliance

1994 NetApp, Inc.

## Take away

- an appliance is a device designed to perform a particular function, i.e. router
- it is much easier to develop high quality, high performance system software for an appliance than for a general purpose operating system
- NFS is a protocol, originally developed by Sun
- two separate logs, when one log gets full, switches to the other log and starts writing a consistency point to store the changes from the first log safely on disk

## TODO


## Abstract

NetApp, Inc. developed 'a dedicated server whose sole function is to provide NFS file service'

WAFL (Write Anywhere File Layout)

- Snapshots
- copy-on-write
- no need for consistency checking after unclean shutdown thanks to Snapshots

## 1. Introduction

- an appliance is a device designed to perform a particular function
- NFS access patterns are different from local access patterns

Primary requirements

- fast
- large (10GB+)
- high performance with RAID
- restart quickly (even under unclean shutdown due to power failure or system crash)

Solution

- Use NVRAM to reduce NFS response time
- Use WAFL to minimize RAID write performance penalty

## 2. Introduction To Snapshots

- [ ] read-only copies of the entire file system
- up to 20 Snapshots on-line
  - [ ] what the relationship between snapshots, delta?
- copy on write

User access

hidden folder `.snapshot`

Snapshot Administration

- by human
- auto, four times a day, nightly every midnight

## 3. WAFL Implementation

### 3.1 Overview

- similar to Unix FFS and Episode FS
- inode
- 4KB blocks with no fragments
- [ ] all the block pointers in a WAFL inode refer to blocks at same level
  - very small, data store in inode
  - smaller than 64 KB, inode point to data block
  - smaller than 64 MB, indirect blocks
  - larger, doubly indirect blocks

### 3.2 Meta-Data Lives in Files

**Don't store meta-data at fixed locations on disk** (except the root inode)

- inode file
- block-map file, identify free blocks
- inode-map file, identify free inodes

> The WAFL file system is a tree of blocks with the root inode, which describes the inode file, at the top, and meta-data files and regular files underneath

### 3.3 Tree of Blocks

the root inode must be in fixed location on disk

### 3.4 Snapshots

Create snapshot by duplicating the root node, when new data is written, active file system block point to the new block

**Compare with Episode**

- creates a clone by **copying the entire inode file and all the indirect blocks**
- fast, create Snapshots every few seconds to allow quick recovery after unclean system shutdowns

Need to have new block all the way up to the root (pretty like the NB+ tree and BTrDB)

Batch (many hundreds of) NFS write request

### 3.5 File System Consistency and Non-Volatile RAM

- a special Snapshot called a *consistency point* every few seconds
  - not accessible like normal Snapshots
- when WAFL restarts, it simply reverts to the most recent consistency point
- use NVRAM to keep a log of NFS requests it has processed since the last consistency point
- divides the NVRAM into two separate logs, when one log gets full, WAFL switches to the other log and starts writing a consistency point to store the changes from the first log safely on disk
- log the operation, not cache the result?

### 3.6 Write Allocation

Maximize the flexibility of its write allocation policies (**Compare with Unix FFS**)

- can write any file system block (except the one containing the root inode) to any location on disk
- can write blocks to disk in any order
- allocate disk space for many operations at once in a single write episode

Optimizing write allocation in short (they often conflict)

- writing to multiple blocks in the same stripe
- writing blocks to location that are near each other on disk
- placing sequential blocks in a file on a single disk in the RAID array

## 4. Snapshot Data Structures And Algorithms

### 4.1 The Block-Map File

- can't use bitmap because many snapshots can reference a block at the same time
- it seems they use 1 byte from Figure 5

### 4.2 Creating a Snapshot

Avoid locking & self consistent

- mark all the dirty data in cache as "IN_SNAPSHOT"
  - must not be modified
  - must not be flushed to disk

To avoid locking, must flush "IN_SNAPSHOT" ASAP

- Allocate disk space for all files with IN_SNAPSHOT blocks
- Update the block-map file
- Write all IN_SNAPSHOT disk buffers in cache to their newly-allocated locations on disk
- Duplicate the root inode to create an inode that represents the new Snapshot, and turn the root inode's IN_SNAPSHOT bit off

Deleting a Snapshot

- zeros the root inode representing the Snapshot
- clears the bit representing the Snapshot in each block-map entry

## 5. Performance

- difficult to compare WAFL's performance to other file systems directly

SPEC SFS a.k.a LADDIS

- measuring a server's response time at various throughput levels

Argue xxx -> not fair to compare

## 6. Conclusion

Production for over a year .w.

- it is much easier to develop high quality, high performance system software for an appliance than for a general purpose operating system
