# vCorfu: A cloud-scale object store on a shared log

Mike Freedman (the guy talked about timescale is one of the author of vCorfu and Replex)

## Ref

- https://github.com/CorfuDB/CorfuDB (I think I starred it because I saw it form @gaocegege)
- https://blog.acolyer.org/2017/05/03/vcorfu-a-cloud-scale-object-store-on-a-shared-log/
- Replex: A scalable, highly available multi-index data store https://blog.acolyer.org/2016/10/27/replex-a-scalable-highly-available-multi-index-data-store/

## TODO

- zlog https://github.com/noahdesu/zlog
  - based on CORFU protocol
- [ ] database view
- [ ] read-your-writes, linearizbility
  - [ ] https://github.com/aphyr/distsys-class
  - Chapter 7 of Distributed Systems: Principles and Paradigms 2/E
  - http://lass.cs.umass.edu/~shenoy/courses/spring05/lectures/Lec15.pdf

## Take away

- like skip list?

## Review on Review

- based on corfu
- it out performs Cassandra while providing strong consistency
  - but not ScyllaDB
- [ ] **matrialized stream**
- > the locality advantages of materialization enable vCorfu to scale to thousands of client
- 'vCorfu can tolerate failures so long as a log replica and stream replica do not fail simultaneously'
- composable state machine replication (CSMR)
- runtime
- provides read-your-writes consistency and strict serializability together with the opacity guarantee that even non-committed transactions are prevented from seeing inconsistent states

## Abstract

- strong consistent cloud scale object store built over a shared log
- CMSR (composable state machine replication)
- outperform strong consistency
- read own writes
- efficient transactions
- global snapshots at cloud scale

## Introduction

- we want no tradeoff between performance and scalability
- NoSQL system can't do many things that RDBMS can do, multiple items atomically
- [OLD] drawback of log
  - need play back
- materialization, divide a single log into virtual logs called materialized streams
  - [OLD] support fully random reads, not just sequential
- composable state machine replication

## 7. Related work

- **whereas vCorfu starts with a global shared log as a source of serialization and virtualizes it,
other transactional distributed data platforms do precisely the opposite: They partition data into shards,
and build distributed transactions over them**
- [OLD] suffer from recursive update problem
  - pointers to vCorfu objects refer to the latest version of the object, no pointer updates are required
