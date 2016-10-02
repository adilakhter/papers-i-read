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

> Dynamo is designed to be an eventually consistent data store; that is all updates reach all replicas eventually

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

## 3. Related work

(this part is kind of an overview of existing solutions to similar topics?)

### 3.1 Peer to Peer Systems

First generation: unstructured P2P network, file sharing system like Freenet and Gnutella.
Second generation: structured P2P network,
> a global consistent protocol to ensure that any node can efficiently route a search query to some peer that has the desired data. Systems like `Pastry` and `Chord` (the next paper we are going to read) use routing to ensure that queries can be answered within a bounded number of hops

- [Chord](http://web.mit.edu/6.033/2001/wwwdocs/handouts/dp2-chord.html)

Oceanstore https://oceanstore.cs.berkeley.edu/

- resolve conflict by processing a series of updates, choosing a total order among them, and then apply them atomically in that order.

PAST provides a simple abstraction layer on top of Pastry

### 3.2 Distributed File Systems and Databases

- Ficus and Coda sacrifices consistency for HA
- GFS use a single master server for hosting entire metadata
- Bayou is a distributed relational database system that provides eventual data consistency

Bayou, Coda and Ficus allow disconnected operations and are resilient to issues such as network partitions and outages.

Dynamo works similar

Antiquity

- secure log to preserve data integrity
- use Byzantine fault tolerance protocols to ensure data consistency

### 3.3 Discussion

Dynamo's target (which is different from systems mentioned above)

- always writeable, no updates are rejected due to failures or concurrent writes.
- all nodes are assume to be trusted.
- applications using dynamo does not require hierarchical namespaces or complex relational schema.
- SLA -> a zero-hop DHT

## 4. System Architecture

in addition to the actual data persistence components, the system needs to have

- load balancing
- membership
- failure detection
- failure recovery
- replica synchronization
- overload handling
- state transfer
- concurrency
- job scheduling
- request marshalling
- request routing
- system monitoring and alarming
- configuration management

and due to the length the paper will focus on

- partitioning
- replication
- versioning
- membership
- failure handling
- scaling

summary of technologies used in Dynamo and their advantages

| Problems   |     Technique     |  Advantage |
|----------|:-------------:|------:|
| Partitioning |  Consistent Hashing | Incremental Scalability |
| HA w |   Vector clocks with reconciliation during reads   |   Version size is decoupled from update rates |
| Handling temporary failures | Sloppy Quorum and hinted handoff | Provides high availability and durability guarantee when some of the replicas are not available |
|Recovering from permanent failures| <!--  TODO: what is Merklet trees--> Anti-entropy using Merklet trees| Synchronizes divergent replicas in the background |
|Membership and failure detection| Gossip-based membership protocol and failure detection| Preserves symmetry and avoids having a centralized registry for storing membership and node liveness information|
