# A Fast File System for Unix

1984

## Take away

- 'Problems with the file system performance have been delt with extensively in the literature' nice sentence for introduction

## Abstract

- cluster data that is sequentially accessed
- provide two block sizes for large and samll files
- 10x faster
- improved programmers' interface
  - [ ] advisory locks on files
  - [ ] name space across file systems ? single machine?
  - [ ] long file names ? why there is 255 restriction
  - [ ] provisions for control resource usage


## Introduction

Old system

- use 512B blocks
- buffer by kernel, appear synchronous
- no constraints other than disk space
- 2% of max disk bandwidth

## Old File System

- disk drive -> one or more partitions
- each partition one file system
- files
  - directories contain pointers to files that may themselves be directories
- previous improvements shows **increasing the block size was a good method for improving throughput**
- **the free list become entirely random**, which reduce performance a lot

## New File System

- files as large as 2^32 bytes with only two levels of indirection
- minimun block size 4096 bytes
- block size is recorded in the super block
- divides a disk partition into one or more areas called cylinder groups
  - book keeping information, reduant superblock
  - **use varying offeset** to reduce the damage caused by physical damage

### 3.1 Optimizing storage utilization

- the main problem with larger blocks is that most UNIX file systems are composed of many small files
- [ ] allowing the division of a single file system block into one or more fragments
  - fragments are addressable, normally 2, 4 or 8 fragments
  - specified when create file system
- [ ] what is the difference of fragments and small blocks? mixed block size? fragments == smaller blocks?
- using 4096/1024 the waste ratio is close to 1024 (byte)
- **FS can't be completely full**, only the admin can allocate new block

### 3.2 File sytem parameterization

- add paramters to know underlying hardware better, processor, disk etc.-
  - spin rate
  - [ ] should be applied to SSD as well, even though there is no more spin

### 3.3 Layout policies

- global policies
- local optimal

Two way to improve file system performance

- increase the locality of reference to minimize seek latency
- improve the layout of data to make larger transfers possible

Layout policy: Inode

- place all the inodes of files in a directory in the same cylinder group
- A new directory is placed in a cylinder group that has a greater than average number of free inodes, and the smallest number of directories already in it

Layout policy: Data blocks

- place all data blocks for a file in the same cylinder group, preferably at rotationally
optimal positions in the same cylinder.
- Quadratic hash is used because of its speed in finding unused slots in nearly full hash tables

## 4. Performance

skip

## 5. File system functional enhancements

Since the new file system already required all existing file systems to be dumped and restored,
these functional enhancements were introduced at this time.


### 5.1 Long file name

- [ ] The maximum length of a file name in a directory is currently 255 characters.

### 5.2 File locking

- old file system use another file as lock
  - need to be manually removed
- Hard locks
- Advisory locks (chosen)
  - only effective when all program use adviosry locks
  - shared lock
  - exclusive lock (only one at a time)


> when a process wishes to apply a shared lock, read some information and determine whether an update is required, then apply an exclusive lock and update the file.
- [ ] TODO: kind of like passimistic locking?
- no dead lock detection

### 5.3 Symbolic links

软链接

A symbolic link is implemented as a file that contains a pathname.

### 5.4 Rename

- [ ] atomic of renaming process?

### 5.5 Quotas

- soft limit (got warning)
- hard limit (terminate the program)
