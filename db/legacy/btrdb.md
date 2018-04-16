# BTrDB: Optimizing Storage System Design for Timeseries Processing

(NOTE: this is not for CMPS232 reading assignment, so it has a loose format)

- telemetry timeseries data comes at high rate and can't be handled by existing solutions.
  -  microsynchophasors, or uPMUs.
  - [ ] how high
  - [ ] the max capacity of existing tsdb

current system limitation

- **order-of-arrival and duplication constraints, as detailed in Section 2**

- KairosDB significantly outperforms OpenTSDB
  - only achieves 403,500 inserted values per second on a 36 node cluster
  - [ ] this is folklore we can prove with Xephon-B

**Existing benchmarks**

> Rabl et. al [24] performed an extensive benchmark comparing Project Voldemort [23], Redis [26], HBase [3], Cassandra [2], MySQL [21] and VoltDB [31][29].

[24] Solving big data chal-lenges for enterprise application performance man-agement. http://vldb.org/pvldb/vol5/p1724_tilmannrabl_vldb2012.pdf they use
YCSB to simulate APM (Application performance monitor data) **We can argue that their measurement is not enough**

e... the rest ref [23] [26] [3] [2] [21] [31] are just the website for those db ..... (I thought they were separated benchmarks)

**compare with Gorilla**
- low precision
- **out of order insertion**
- lacks accelerated aggregates?
> Gorilla database [22] takes a similar approach to BTrDB - simplifying the data model to improve performance. Unfortunately, it has second-precision timestamps, does not permit out-of-order insertion and lacks accelerated aggregates.

**aggregate**

- on the fly OpenTSDB, Druid
- pre computed aggregates InfluxDB, RespawnDB
  - [ ] Respawn: A Distributed Multi-Resolution Time-Series Datastore https://users.ece.cmu.edu/~agr/resources/publications/respawn-rtss-13.pdf

> While many time series databases support aggregate queries, the computation requires on-the-fly iteration of the base data (e.g. OpenTSDB, Druid) - untenable at 50 billion samples per year per uPMU. Alternatively, some timeseries databases offer precomputed aggregates (e.g, InfluxDB, RespawnDB [4]

**'they are unable to guarantee the consistency of the aggregates when data arrives out of order or is modified'**

> - high throughput
  - fixed response time analytics irrespective of the underlying data size
  - [ ] **eventual consistency** in a graph of independent analytics despite out of order or duplicate data

>  On four large EC2 nodes it achieves over 119M queried values per second (>10GbE line rate) and over 53M inserted values per second of 8 byte time and 8 byte value pairs, while computing statistical aggregates.

- compression ratio of 2.9x

## Time Series data abstraction

- 'a consistent, write-once, ordered sequence of time-value pairs.'
- **'each stream is identified by UUID'**
  - [ ] stream
  - [ ] who generates the UUID
  - [ ] use bloom filter to avoid duplication?
- 'many good solutions exist for querying metadata to obtain a collection of streams.'
  - [ ] what are those solutions
  - [ ] gorilla also mentioned this since it also just focus on store timestamp and value

> In BTrDB, each insertion of a collection of values creates a new version, leaving the old version unmodified. This allows new analyses to be performed on old versions of the data

- [ ] multi version? feels kind of like KairosDB or Cassandra

- InsertValue(UUID, [(time, value)]) create a stream
 - [ ] what is the def of stream?
 - [ ] 'each insert of a collection of values creates a new version, leaving the old version unmodified'
- GetRange(UUID, StartTime, EndTime, Version) -> (Version, [(time, value)])
-  GetLatestVersion(UUID) -> Version
- [ ] Use external tools like pandas http://pandas.pydata.org/ to `resample` and `align` data
- **analysis and visual** GetStatisticalRange(UUID, StartTime, EndTime, Version, Resolution) -> (Version, [(Time, Min, Mean, Max, Count)]) 'retrieve statistical records between two times at a given temporal resolution.'
  - [ ] what does resolution mean here
  - [ ] why each record covers 2^resolution nanoseconds
- GetNearestValue(UUID, Time, Version, Direction) -> (Version, (Time,Value)) locates
  - [ ] why just one point instead of a range?
- raw data stream -> distillation processes
- ComputeDiff(UUID, FromVersion, ToVersion, Resolution) -> [(StartTime, EndTime)]
- DeleteRange(UUID, StartTime, EndTime)
- Flush(UUID)

## Time partitioned tree

time-partitioning copy-on-write version-annotated k-ary tree https://en.wikipedia.org/wiki/K-ary_tree
 A binary tree is the special case where k=2.

where does the term COW tree comes out? .... copy on write? ...

**The process of building the system**

- simple, performance, HA
- follow SEDA: An Architecture for Well-Conditioned, Scalable Internet Services

still I quite not understand the use of version of stream 
