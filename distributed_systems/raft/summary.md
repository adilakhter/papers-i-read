# Summary: Soft

## Abstract

Raft works as good as Paxos and is easier to Understand

## 1. Introduction

Paxos has dominated this area for too long and tortured many people.

Raft focus on understandability, so

- decomposition: leader election, log replication, and safety
- state space reduction

Novel features

- Strong leader, ie: log only from leaders to other servers
- Leader election, randomize timer to elect leader
- Membership changes, joint consensus

## 2. Replicated state machines

> Consensus algorithms typically arise in the context of replicated state machines

Example: GFS, HDFS, RAMCloud, Chubby, ZooKeeper

Implementation: replicated log

- a log contains series of commands on each server
- **each log contains same commands in the same order**
  - [x] how to make sure the order? that's what the consensus algorithm goes

Consensus Module

- receives commands from clients and add them to its log
- communicate with consensus modules on other servers to ensure that every log eventually contains the same requests in the same order, even if some server fails
- once commands are properly replicated, each server's state machine processes them in log order, and the output is returned to clients

Properties for a practical system

- safety under all non-Byzantine conditions
- available as long as majority servers are operational
- do not depend on timing to ensure the consistency of the logs
- a command can complete as soon as majority of the cluster has responded to a single round of remote procedure calls

## 3. What's wrong with Paxos

- extremely difficult to understand
- does not provide a good foundation for building practical implementations.

> each implementation begins with Paxos, discovers the difficulties in implementing it, and then
develops a significantly different architecture

## 4. Design for understandability

same as intro, decomposition and reduction of states

## 5. The Raft consensus algorithm

That's where the real part starts P3-P10 (Including some rules in P4)

- leader election
- log replication
- safety

### 5.1 Raft Basics

Server state

- leader
- follower
- candidate

one leader + followers

Time is divided into terms of arbitrary length

term = election + normal | election + election (no leader selected, end this term and go to the next term)

Terms act as logical clock in raft. Each server stores a current term number, which increases monotonically over time
- [ ] overtime? because message? or there is a timer in each server that increase the term number every 30s

RPCs

- RequestVote RPC
- AppendEntries RPC

### 5.2 Leader election

Heartbeat mechanism to trigger election

- starts as follower
- remains follower as long as it receive valid RPC from leader
- if election timeout, begins an election

Election

- increments its current term
- change to candidate state
- votes for itself
- issues RequestVote RPC in parallel

Stop candidate state when

- it wins the election
- another server wins
- a period of time goes by with no winner

Win

- receive votes from a majority of the servers **for the same term**
- each server vote at most once, on a **first come first served** basis
  - [ ] first message receive? or other sort of total order
  - [ ] section 5.4 addition
- send heartbeats to establish its authority

Use randomized election timeout to ensure that split votes are rare and that they are resolved quickly.

### 5.3 Log replication

- Each client requests contains a command to be executed by the replicated state machines.
- The leader appends the command to its log as a new entry,
- then issues AppendEntries RPCs in parallel to each of the other servers to replicate the entry.
- entry has been safely replicated
- apply entries to its state machine
- return execution to the client

Log Entry

- a state machine command
- the term number
- log index (position in the log)
