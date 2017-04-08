# Measurements of a Distributed File System

UCB, 1991, 15 Pages

## Take away

## Abstract

Analyzed user-level file system access patterns and caching behavior of the Sprite distributed file system

- throughput increased?
- main memory file cache
 - client cache consistency is needed

## 1. Introduction

- BSD Study: Trace driven analysis of the Unix file system
  - only a few seconds for files in office and engineering
  - file accesses tends to be sequential
  - use simulation to predict main memory file cache can substantially reduce disk I/O

Do the study again because

- hardware changes, people got their own machine
- network-oriented OS and FS, i.e. NFS, Sprite


40 work stations

- 4 file
- 35 disk less client

Most match previous BSD study except

- large file got larger

Sprite

- guarantee consistency of data cached on different clients
  - write sharing is infrequent, the cost is not much
- **sprite allow migrating processes onto idle machines**
  - [ ] That's pretty interesting, how does it keep the program context

## 2. The System Under Study

Sprite

- network file system
- **process migration**
  - `pmake`
- perfect cache consistency

## 3. Collection the Data

collect data
- tracing
- kernel counters
  - open
  - close

coordinating the traces from many machines is hard
- most of the information is already stored in Sprite file servers
- add extra request from client to server for logging

8 x 24

## 4. BSD Study Revisited

- user activity
  - how much the file system is used
- access patterns
  - sequentiality
  - dynamic file sizes
  - open times
- file lifetimes

Overall is much similar than 6 years ago, but

- overall activity levels are substantially higher
  - burst caused by process migration
- largest file in use are much bigger than before

### 4.1 User Activity

### 4.2 File Access Patterns

### 4.3 File Lifetimes

## 5. File Cache Measurements

### 5.1 File Cache Sizes

### 5.2 The Impact of Caching on File Traffic

### 5.3 The Impact of Paging Traffic

### 5.4 Cache Block Replacement and Writeback

### 5.5 The Importance of Cache Consistency

### 5.6 Algorithms for Concurrent Write-Sharing

skipped all of them

## 6. Summary

- file throughput has increased by a factor of 20 overall and has become much more bursty.
- typical large files used today are more than an order of magnitude larger than typical large files used in 1985.
- increases in cache size have led to increases in have been much read hit ratios, but the improvements smaller than we expected.
- the overheads for implementing consistency are very low, only occurs for about one percent of file since write-sharing accesses.
- process migration increases the burstiness of file traffic by an order of magnitude.
