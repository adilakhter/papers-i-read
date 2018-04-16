# Dapper

https://github.com/at15/papers-i-read/issues/68

## TLDR

- write to local disk, the pulled to central repo
- sampling in both runtime library and collection
- index service, machine, timestamp, only 26% smaller than original data
- gui

## Abstract

- sampling, restrict to a small set of common libraries
- low overhead, application level transparency, ubiquitous deployment on a very large scale system

## 1. Introduction

- example: web search using many services
- requirements:
  - ubiquitous deployment
  - continuous monitoring
- design goals:
  - low overhead
  - application level transparency
    - restrict to threading, control flow, RPC
  - scalability
    - adaptive sampling

## 2. Distributed Tracing in Dapper

- need a initiator
- use annotation based

## 2.1 Trace trees and spans

- span: basic unit of work
  - span name: human readable name
  - span id
  - parent id
    - span without a parent id are known as root span
  - can contain information from multiple hosts
    - client send
    - server receive
    - server send
    - client receive
- edge: casual relationship between a span
- trace id: shared by all span associated with a specific trace
  - [ ] TODO: create on root span and pass along?
- [x] is the payload pass along and got stored when it reached the last endpoint? and how can a service know it is the end?
  - [x] what if some service crashed in the middle
  - see 2.5 Trace collection

## 2.2 Instrumentation points

- thread
- control flow lib?
- RPC

## 2.3 Annotations

- allow define timestamped annotations through a simple API
- additional key value pairs

## 2.4 Sampling

- recording only a fraction of all traces

## 2.5 Trace collection

- write to local log file
- pulled from all hosts by daemon
- write to Bigtable
  - A trace is a single row, Bigtable support for sparse table layout is useful since individual traces can have an arbitrary number of spans
- collection time
  - median latency less than 15 seconds
  - max can be many hours

### 2.5.1 Out-of-band trace collection

in band: trace data is send back within RPC response header

- can affect application network dynamics, many spans, even larger than RPC payload itself
- assume all RPCs are perfectly nested, but many system return result to caller before all of their own backends have returned a final result

## 2.6 Security and privacy consideration

- can be used to audit system

## 3 Dapper Deployment Status

### 3.1 Dapper runtime library

- 1000 loc C++
- 800 loc Jav

## 4 Managing Tracing Overhead

### 4.1 Trace generation overhead

- creating and destroying spans and annotations
  - root span 204 ns, non-root 176, spent on generate global unique id
  - annotation is negligible if it is not sampled
    - [ ] how to decide which trace is sampled
- logging to local disk (most)

### 4.4 Adaptive sampling

- at first, a uniform sampling probability for all processes
  - does not work for low traffic
- adaptive ... in progress (2010 ...)

### 4.6 Additional sampling during collection

- 1 TB sampled trace data per day
- hash trace id to 0 < z < 1, if z is less than sampling coefficient, keep the span and write to bigtable

## 5 General-Purpose Dapper Tools

### 5.1 The Dapper Depot API

- by trace id
- bulk access
- indexed access
  - index is **expensive** only 26% smaller than original data
  - a composite index in order of service name, host machine and timestamp

### 5.2 The Dappter user interface

- tree
- time line chart

## 7 Other lessons learned

- coalescing effects, group sample together may lost important info
- tracing batch workloads, off-line analytical MapReduce etc.
- finding a root cause, some request a slow because of previous requests, not just itself
- kernel level information
