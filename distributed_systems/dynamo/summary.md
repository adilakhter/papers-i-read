# Dynamo

## Abstract

In amazon's scale, small and large components fails continuously and
the way persistent state is managed in the face of these failures drives
the reliability and scalability of the software systems.

- highly available K-V
- sacrifices consistency under certain failure scenarios
- extensive use of object versioning
- extensive use of application-assisted conflict resolution
- provide a novel interface for developer to use (AWS?)

## 1. Introduction

- amazon has many servers located in different data centers
- stable service -> reliability
- growth -> scalable

> reliability and scalability of a system is dependent on how its application state is managed.

Amazon use decentralized service oriented architecture consisting of hundreds of services.

Treat failure handling as the normal case without impacting availability or performance.

In order to have HA, amazon have

- S3 (Simple Storage Service)
- Dynamo

Dynamo is used to

- manage the state of services
- provide primary-key only interface which suits some scenarios better than RDBMS

Dynamo uses a synthesis of

- [ ] data partition and replication using consistent hashing
- [ ] consistency is facilitated by object versioning.
- [ ] consistency among replicas during updates is managed by a quorum-like technique and a decentralized replica synchronization protocols
- [ ] gossip based distributed failure detection and membership protocol

Dynamo can

- add or remove node without requiring any manual partitioning or redistribution

Main Contribution

- the evaluation of how different techniques can be combined to provide a single high-available system.
- an eventually-consistent storage system can be used in production with demanding applications.
- an insight into the tuning of these technologies to meet the requirement of production systems with very strict performance demands.

**The structure of the sections**

- background
- related work
- systems design
- implementation
- experiences and insights from production
- conclusion

## 2. Background

services

- stateless (ie: aggregate)
- stateful (relies on persistent store)

why NOT RDBMS

- they chose consistency over availability
- overkill functionalities for querying by primary-key

### 2.1 System Assumptions and Requirements

Query Model:

- identify by unique key
- simple blob less than 1MB

ACID Properties: ACID (Atomicity, Consistency, Isolation, Durability)

- providing ACID means poor availability
> Experience at Amazon has shown that data stores that provide ACID guarantees tend to
have poor availability. This has been widely acknowledged by both the industry and academia [5].

- weaker C -> HA
- does NOT provide isolation guarantees and permits only single key updates

Efficiency:

- high SLA (99.9)
- tradeoffs are in performance, cost efficiency, availability, and durability guarantees.

- no security issues
- scale up to hundreds of storage hosts.

### 2.2 Service Level Agreements (SLA)

Client and Server agree on several system related characteristics.

- client's expected request rate distribution for a particular API.
- expected service latency under those conditions

To form a performance oriented SLA, describe it using

- average
- median
- expected variance

But, to ensure all customer have good experience, they use 99.9 percentile, not average.

**Give services control over their system properties, let services make their own tradeoffs**

### 2.3 Design Considerations

strong consistency and high availability cannot be achieved simultaneously.

use optimistic replication  -> conflicting changes that must be detected and resolved.
- [ ] how to detect
- when to resolve
- who resolves them

When to resolve

- traditional DB prefers write, reject if can't reach most replicas at given time
- for customer performance, 'always writable', resolve conflicts on read.

Who resolves

- data store -> last write wins
- application -> resolve based on business logic

Other key principles

- incremental scalability
- symmetry, simplifies the process of provisioning and maintenance
- decentralization, p2p
- heterogeneity, ie: work distribution must be proportional to the capabilities of the individual servers.
