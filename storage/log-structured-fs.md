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
  - [ ] is this compared with the old or the new unix fs?

## 1. Introduction

## 2. Design for file systems of the 1990's

### 2.1 Technology

### 2.2 Workloads

### 2.3 Problems with Existing

## 3. Log structured file systems

### 3.1 File Location and Reading

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
