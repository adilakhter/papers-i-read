# Valmar: High-Bandwidth Real-Time Streaming Data Management

## Abstract

- large stream data
- filter and keep the interesting part
- nearly full disk bandwidth

## Introduction

- router 5GB/s
- Large Hadron Collider (LHC) 300MB/s
- Long Wavelength Array (LWA) 3/75GB/s
  - 100 PB/year

Massive amounts continuously written but rarely read

- no database is capable of keeping up with a never ending stream of IP packets in ...
- general purpose filesystem, can't handle small individual elements, generalized search

## Overview

- write once, read maybe

### A. Ring Buffer Model

- current data is preserved for a limited time only
  - capacity
  - policy
- current data can be marked for preservation
- round robin (oldest data are overwrite first)
- new data has priority at all times

### B. Disk Performance and Data Chunking

- Data Element: a single piece of data that should be treated as an indivisible unit
- Data Chunk: a unit that the storage system interacts with
- **MB level size chunk, bigger the better**

### C. Indexing and Searching

- use fixed location if known size
- store in large chunk as data
- evict like data, when no reference, gone

### D. Prototype System

- user space
- access disk drives as raw devices
- the only process that access certain disk
