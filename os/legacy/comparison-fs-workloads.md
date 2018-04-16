# A Comparison of File System Workloads

UCB & UW, 2000, 15 Pages

## Take away

- elucidate: make (something) clear; explain
- mmap is used a lot
- large file system cache may not help much

## Abstract

How modern workloads affect the ability of fs to provide high performance to users

- trace from various sources
- *memory-map* is used more than read
- bimodal distribution pattern
  - written repeatedly without being read
  - exclusively read
- new metric for measuring life time for those that are never deleted
  - [ ] How could that be?
- all workloads show lifetime locality

## 1. Introduction

Different community have different workload

- Unix, Windows NT
- Client, Server
- Instructional, Research, Production

Difference with Sprite Study (Measurements of a Distributed File System)

- Focus on IO instead of cache and virtual memory

Machines

- HP-UX instructional laboratory (INS)
- HP-UX research (RES)
- HP-UX web server (WEB)
- Windows NT personal

Result

- diminishing benefits for large cache size
- memory-mapping become popular file access method
- individual files tend to have bimodal access patterns, they are either read-mostly or write-mostly.

## 2. Related Work

- most concentrate on static data, examining metadata at one or several frozen instants in time
- Dynamic traces are more detail but required modification of Kernel
  - record file system events pass over a network
- Problem of modifying kernel
  - not all kernel have public source
  - user have to accept the altered kernel
  - overhead of fine-grained traces

Previous

- BSD study
- Sprite study
- NT (Voge99)

Novel

- effect of memory-mapping files on the file cache

## 3. Trace Collection

### 3.1 Environment

### 3.2 Trace Collection Methodology

#### 3.2.1 HP-UX Collection Methodology

- auditing subsystem originally designed for security purpose
- problem is file path is not complete
  - record process working directory
  - cache all the cd

#### 3.2.2 Windows NT Collection Methodology

- file system filter driver
- fast path (dispatch)

## 4. Results

### 4.1 Histogram of Key Calls

### 4.2 Data Lifetime

#### 4.2.1 Create-based Method

#### 4.2.2 Block Lifetime

#### 4.2.3 Lifetime Locality

### 4.3 Effect of Write Delay

### 4.4 Cache Efficacy

efficacy: the ability to produce a desired or intended result.

#### 4.4.1 Effect of Cache Size

#### 4.4.2 Read and Write Traffic

#### 4.4.3 Effect of Memory Mapping

### 4.5 File Size

### 4.6 File Access Patterns

#### 4.6.1 Run Patterns

#### 4.6.2 Read and Write Patterns

## 5. Conclusions

- WEB has far more read than write
- average block lifetime, and even the distribution of block lifetimes, varies significantly across workloads.
  - NT lives longer
- small cache biu!, large cache, may not
- all modern workloads use memory-mapping to a large extent
- larger file size
- file access patterns are bimodal in that most files tend to be mostly-read or mostly-written.
