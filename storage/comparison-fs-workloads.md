# A Comparison of File System Workloads

UCB & UW, 2000, 15 Pages

## Take away

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

## 2. Related Work

## 3. Trace Collection

### 3.1 Environment

### 3.2 Trace Collection Methodology

#### 3.2.1 HP-UX Collection Methodology

#### 3.2.2 Windows NT Collection Methodology

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



