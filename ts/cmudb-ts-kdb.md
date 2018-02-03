# Time Series Database Lectures from CMU DB - Kdb+

- issue https://github.com/at15/papers-i-read/issues/80
- video https://www.youtube.com/watch?list=PLSE8ODhjZXjY0GMWN4X8FIkYNfiu8_Wl9&v=AiGdfmxEP68
- from http://db.cs.cmu.edu/seminar2017/

## Take away

- Unified columnar database & programming system
- less than 10 people
- demo 31 TB uncompressed NYSE Data, 2013/01
- commercial benchmark https://stacresearch.com/ 
- benchmark http://tech.marksblogg.com/billion-nyc-taxi-kdb.html

## Notes

Start from APL. everything is a vector?(list?)

- Kenneth E. Iverson Notation as a Tool of thought http://www.jsoftware.com/papers/tot.htm
- Then J, K, Q language
- kdb, kdb+ (2003)

**Unified columnar database & programming system**

- lambda architecture
  - streaming
  - real-time (in-memory) order by time
  - historical (on-disk) order by certain column etc.
- in-database analytics
- support for joins
  - time series join
- 500 KB binary

````
data -> events engine ------------ streaming queries
              |                 |- real-timedatabase (RDB) -> column arrays
              |                 |
            log                historical database (HDB) -> column files (mmap on demand)
````

Data Types

- Boolean, Byte, Integer, Float, Character
- Symbol, GUID
- Enumeration, Dictionary
- (Keyed) Tables
- Functions

Time Series data types

- Date, Time, Minute, Second, Month, Datetime
- Timespan (ns) Timestamp (ns)

q programming language

- functional, 200 built in functions
- array/vector (matrix?), get rid of `for` loops
- query, a superset of SQL
- interpreted

q a language for time series

- time series functions/joins
  - xbar
  - Bi-Temporal
    - aj (As-of join)
    - wj (Window join)
- Temporal Arithmetic, add day etc.

Attributes (Index)

- `s# sorted
- `p# parted, partition
- `u# unique
- `g# grouped (like traditional hash index?

Parallelism

- Vertical Scaling
  - multi-threading
  - no serialization
  - automatically distributes queries across CPU cores
- Horizontal Scaling
  - multi-processing
  - automatically distributes queries across machine
- Exploits Intel vector instruction sets
- Native Map-Reduce

Compression

- websocket compression
- in-flight compression between hosts
- on-disk compression
  - kdb+ algo
  - gzip
  - google snappy
  - lzh4c

Encryption

- SSL/TLS for in-flight data
- on disk encryption rely on OS

Interfaces

- ODBC/JDBC, C++, Java, C#, Python, R, Kafka ..
- you can run `numpy` on kdb data

Demo

- 31 TB uncompressed NYSE Data, 2013/01 -
- 1.3 trillion records
  - derived data
   - raw trade and quote data

hhh .... the demo is not in the video ...

**Benchmarks!**

- https://stacresearch.com/ a benchmark group? ... has dedicated test for TS
- mentioned a blog? compare kdb+? http://tech.marksblogg.com/billion-nyc-taxi-kdb.html (found it!) http://tech.marksblogg.com/benchmarks.html

1.1 billion taxi rides on kdb+/q & 4 Xeon Phi CPUs

Books

- q for mortals http://code.kx.com/q4m3/
- q tips

just less than 10 people, the code base is small (amazing ....
