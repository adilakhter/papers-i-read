# Avoiding the Disk Bottleneck in the Data Domain Deduplication File System Challenges and Observations

## Take away

- `Chanllenges and Observations` as a section title
- https://en.wikipedia.org/wiki/Locality_of_reference

## Abstract

- replace tape
- high throughput
- small ram, have to access on disk index

- summary vector (Bloom filter)
- stream informed segment layout
- locality preserved caching

## Introduction

- secondary storage system use much larger capacity than primary
- low cost
- high performance
- [OLD] use tape libraries
  - managing cartidges is a manual process that is expensive and error prone
  - tape cartidge cannot be located
  - has been damaged during handling

Do deduplication at high speed in order to meet the performance requirement for secondary storage used for data protection

- Identical Segement Deduplication
  - key performance challenge: finding duplicate segments
  - 8KB segement
  - 12, 000 segments per second
  - [ ] so using identical segment deduplication covers incremental update?

Cache

- [OLD] LRU cache has low hit due to little temporal locality
  - Venti, cache only increase 16% from 5.6MB/s to 6.5MB/s

> it's a far cry from the throughput goal of deduplicating at 100 MB/sec to compete with high end tape libraries

- Summary Vector
  - Bloom filter
- Stream-Informed Segement Layout
  - store data segments and their fingerprints in the same order that they occur in a data file or stream
  - spatial locality
- Locality preserved caching
  - cache groups of segment fingerprints that are likely to be accessed together

eliminate about 99% of index lookup, over 100MB/sec for single stream write & read.
over 210 MB/sec for multi-stream write

## 2. Challenges and Observations

### 2.1 Variable vs. Fixed Length Segments

Fixed: simplicity

Variable

- essential for deduplication of the shifted content of backup images

### 2.2 Segment Size

- small
  - more segments
- A well-designed duplication storage system should have the smallest segment size possible given the throughput and capacity requirement for the product

### 2.3 Performance-Capacity Balance

100MB/s

### 2.4 Fingerprints vs. Byte Comparisons

- 160-bit SHA-1

## 3. Deduplication Storage System Architecture

skip

## 4. Acceleration Methods

### 4.1 Summary Vector

- Init
- Insert(fingerprint)
- Lookup(fingerprint)

### 4.2 Stream-Informed Segment Layout

- spatial locality
- segment duplicate locality

**make the deduplication storage system stream aware**

### 4.3 Locality Preserved Caching

- group hash values together, evict and load in group

## 5. Experimental Results

The system described in this paper has been used at over 1,000 data centers.x

## 6. Related Work

- [OLD] basic methods and compression
  - not throughput

## 7. Conclusion

- would be better with more cores
