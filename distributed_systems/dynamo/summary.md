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
