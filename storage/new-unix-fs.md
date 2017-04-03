# A Fast File System for Unix

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



