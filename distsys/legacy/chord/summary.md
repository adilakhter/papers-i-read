# Chord: A Scalable Peer-to-peer Lookup Service for Internet Applications

Locate node that has stuff the client is looking for. Efficient and (fault tolerant.)?  

## 1. Introduction

> A scalable protocol for lookup in a dynamic peer-to-peer system with frequent node arrivals and departures.

Chord only need to know O(logN) other nodes. It supports node joining and leaving (failure)

## 2. Related Work

- DNS -> need special server like root server
- Freenet -> Chord takes predictable time and have definite result.
- Globe -> Chord does not have hierarchy
- Plaxton & used in OceanStore -> Chord is less complicated and handles Concurrent joins and failures
- CAN use DHT -> Chrod lookup takes less time and is more robust
- Grid -> similar

Usage

- avoid single point failure

more in sec 3

## 3. System Model

Addressed issues

- Load balance : hash split load evenly
- Decentralization
- Scalability: O(logN)
- Availability: joins and left
- Flexible naming: (this is really not something special....)

Usage

- as a library
- lookup(key)
- notify application of the changes in the set of keys that the node is responsible for.

Applications

- Cooperative Mirroring : kind of like file sharing
- Time-Shared Storage : still kind of like P2P file sharing software
- Distributed Indexes:
  - [ ] how to search when encrypted
- Large-Scale Combinatorial Search:

## 4 The basic Chord Protocol

TODO: list all the basic definitions

- consistent hashing (4.2): assign each node and key an m bit identifier, using function like SHA-1
- successor: Key k is assigned to the first node whose identifier is **equal** or **follows** (the identifier of) k in the identifier space. This node is called the successor node of key k, denoted by *successor(k)*. If the identifier are represented as a circle of numbers from 0 to 2^m - 1, the *successor(k)* is the first nod clockwise from k.  

### 4.3 Scalable Key Location

- m number of bits in key/node identifiers
- *finger table* each node, n, maintains a routing table with (at most) m entries
- *i^th finger of node n*, *n.finger[i].node* the i^th entry in the table at node n contains the identity of the first node, s,
that succeeds n by at least 2^{i-1} on the identifier circle. s = successor(n + 2^{i-1})

TODO: still quite not Understand this scheme ...

It has detail example and graph, but still idk, go ahead and come back to this part later.

- [ ] all the interval combine cover the whole circle?
- first finger of n is its immediate successor on the circle, for convenience we of refer to it as successor rather than the first finger. 

## 5. Concurrent Operations and Failures

.... finished the reading with confusion about all the core parts .... need to read again
on sec4,5 and write the summary at the same time. then go for the next paper.
