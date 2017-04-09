# Chapter 1: Introduction

## Take away

- SSBM benchmark (simplified of TPC-H)
- Virtual ID, use fixed column width and offset (kind of like RRD)

## TODO

## Content

> these column-based systems enable queries to read just the attributes they need, rather than having to read entire rows from disk and discard unneeded attributes once they are in memory.

- Column Store with Explicit Ids
- [x] Column Store with virtual ids, use fixed column width and offset


Tradeoffs

-'if a query needs to access only a single record, a column store will have to
seek serveral times to read just this single record'
- with more records accessed, transfer time begin to dominate seek time,
column perform better than row

Column-store Architectures

- Virtual ID
  - use offset + fixed width
- Block-oriented + Vectorized processing
  - cache-line sized blocks of tuples between operators
  - operating multiple values at a time
  - **vectorized CPU instructions**
  - https://github.com/arrayfire/arrayfire works for both CPU and GPU
- Late materialization
  - [ ] compared with Cassandra, which is early materialization?
- Column-specific compression
- Direct operation on compressed data
- [ ] Efficient join implementation
- [ ] Redundant representation of individual columns in different sort orders
  - C-Store calls groups of columns sorted on a particular attribute projections.
  - Virtual IDs are on a per-projection basis.
- [ ] Database cracking and adaptive indexing
- Efficient loading architecture
  - C-Store uncompressed, write optimized buffer (WOS)

**SSBM benchmark**
