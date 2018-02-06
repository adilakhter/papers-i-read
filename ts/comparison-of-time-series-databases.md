# Comparison of Time Series Databases

- issue https://github.com/at15/papers-i-read/issues/100

- Chapter 2 Existing benchmark for TSDB
- Chapter 3 Existing TSDB and how they are found
- Chapter 4 TSDBBench and YCSB-TS
- Chapter 5 10 TSDB
- Chapter 6 Recommended TSDB based on use case
- Chapter 7 Conclusion and future work

## Take away

- benchmark metrics, YCSB-TS query latency and space consumption
  - we can also add host metrics, disk write amplification etc.

## Abstract

- 75 TSDB, 42 open source
- compared 10 TSDB with 19 criteria
- TSDBBench https://github.com/TSDBBench
- YCSB-TS https://github.com/TSDBBench/YCSB-TS

## Introduction

- sensor data
- **TSDB is not accurate**
- 42 open source 32 commercial, 75 in total (paper is written in 2016)
- inner and outer
  - inner, calculation support in TSDB and its own storage
  - outer, cluster, HA
- queries and storage
- long term support
- development (community?)

> Scientific comparisons or benchmark-results of TSDBs are rarely found or,
if existing, made for a specific purpose (e.g., showing that a new TSDB is better
than a few others)

- nine different queries
  - insert INS
  - update UPDATE
  - read READ, read smallest unit (i.e. a single point)
  - scanning SCAN
    - [x] read by time range
  - counting CNT (in time range)
  - min and max MIN and MAX (in time range)
- data model, metric, tag, ts, value etc.
- tag is used to group

## 2. Background and Related Work

### 2.1 Preliminary Findings

- pg, MongoDB, OpenTSDB, [aerospike](https://github.com/aerospike/aerospike-server)
- 'Scalability and Robustness of Time-Series Databases for Cloud-Native Monitoring of Industrial Processes'
  - compared OpenTSDB, KairosDB, Databus from linkedin https://github.com/linkedin/databus
  - KairosDB is the best (e ...)
- 'The Next Generation Operational Data Historian for IoT Based on Informix' IBM China
  - SQL and TS (timescale :))
  - footnote said the benchmark IoT-x will be opensourced, but where ?...
- 'In Search of Agile Time Series Database' (read it before!)
  - https://www.gitbook.com/book/taowen/tsdb/details
  - https://github.com/taowen 作者现在在滴滴 (zhihu上也老看见....)
  - old RRDtool, Graphite
  - fast kv (?) OpenTSDB, KairosDB (column family is more precious)
  - SIMD VectorWise, Alenka

### 2.2 Benchmarks

- preloaded data and a set of queries (preloaded data is not hard requirement)
- STAC-M3, commercial, 2 DB
- FinTime https://cs.nyu.edu/shasha/fintime.html, code and result link broken
- YCSB
- TPC
- Benchw 11 years ...
- APB-1 ... 1998 ... (amazing the website is still there) http://www.olapcouncil.org/research/bmarkly.htm
  - two of the members are bough by Oracle (Hyperion and Sun) http://www.olapcouncil.org/member/meminfoly.htm

### 2.3 Data

- mainly generate data, can use existing dataset (but there are not many, i.e. too small UCR (this is for machine learning?))

## 3. Time Series Databases

### 3.1 Definition, Search, and Grouping

- ts, value, tags (optional)
- metric (series) contains multiple points
- range query (on time)

Search

- google 'time series database', `tsdb`
- acm digital library
- ieee xplore
- wikipedia

Group

- require NoSQL
- no requirement
- RDBMS
- Propritary


### 3.2 Group 1: TSDBs with a requirement on NoSQL DBMS

(most of them should be cassandra ...)

- Blueflood (C*)
- KairosDB
- NewTS
- OpenTSDB
- Rhombus https://github.com/Pardot/Rhombus (dead, latest update 2014)

### 3.3 Group 2: TSDBs with no Requirement on any DBMS

- Druid, meta storage + distributed fs
  - real-time + historical node
- InfluxDB
- MonetDB

### 3.4 Group 3: RDBMS

- can't use ts as primary key due to tag
  - add auto incr pk
- MySQL, PostgreSQL

### 3.5 Group 4: Proprietary

- Acunu (bought by apple)
- Aerospike (it is open source now https://github.com/aerospike/aerospike-server)
- Axibase (guess it is using HBase)
- Cityzen Data (?)
- DataStax Enterprise
- Databus (use Oracle)

### 3.6 Feature Comparison of TSDBs

- HA, LB
- built in function
- granularity
  - roll up? (down sampling)
- interfaces
- support and license
- Druid, InfluxDB, MonetDB are Recommended for different requirements

## 4. Concept of a Time Series Database Benchmark

### 4.1 Metrics

YCSB-TS

- query latency
- space consumption
  - [ ] NOTE: we can also consider latency, host cpu usage, write amplification etc.

Latency

- error query are ignored
  - [ ] NOTE: they should be considered, i.e. timeout
- min, max, avg, 95th percentage, 99th percentage in microseconds
  - 95th percentage is the latency below or equal 95th percent of the latencies of all queries in a set of queries are

Space consumption

- hard to measure
  - internal cache
  - data is only transfered to other nodes after certain amount of time
- use df

Good metrics 6 characteristics

- 6 characteristics of a good performance metric: linearity, reliability, repeatability, easiness of measurement, consistency, and independence

### 4.2 Scenarios

- [ ] TODO: P49/P157 .... 
