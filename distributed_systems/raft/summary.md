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

The leader decides when it is safe to apply a log entry to the state machines.
It includes the highest index it knows to be committed in AppendEntries RPCs (include heartbeats)
Once a follower learns that a log entry is committed, it applies the entry to its local state machine (in log order).

Raft maintains the following properties

- If two entries in different logs have the same index and term, then they store the same command.
  - a leader create at most one entry with a given log index in a given term and log entries never change their position in the log.
  - [ ] so when followers receive the AppendEntries RPC, they place the entry in current term based on the index in the RPC message? (which help avoid disorder of message arrival?)
- If two entries in different logs have the same index and term, then the logs are identical in all preceding entries.
  - consistent check by AppendEntries. Includes the index and term of the entry in its log that immediately precedes the new entries
  - if the follower does not find an entry in its log with the same index and term, then it refuses the new entries
  - [x] what does the leader do when the follower refuses?
    - in leader forcing duplicate, decrease the next index until the follower accept

Log inconsistency

- leader crashes
  - follower have less
  - follower have extra
  - both
- missing and extraneous entries in a log may span multiple terms

Leader forcing followers' log to duplicate its own. -> overwrite conflict
- [ ] section 5.4 restriction show this is safe
- leader maintains a **nextIndex** for each follower
  - [ ] how does the leader know all the followers?
- leader first come to power, initialize all nextIndex values to the index just after the last one in its log
- after a rejection, the leader decrements nextIndex

A leader never overwrites or deletes entries in its own log

### 5.4 Safety

Restriction on which server may be elected leader ensures that the leader for any given term contains all of the entries committed in previous terms.
(Leader Completeness Property)

#### 5.4.1 Election restriction

In any leader-based consensus algorithm, the leader must eventually store all of the committed log entries;
Raft uses the voting process to prevent a candidate from wining an election unless its log contains all committed entries.
RequestVote RPC includes information about the candidate's log, and the voter denies its vote if its own log is more up-to-date than that of the candidate

compare both index and term

#### 5.4.2 Committing entries from previous terms

If a leader crashes before committing an entry, future leaders will attempt to finish replicating the entry.
However, a leader cannot immediately conclude that and entry from a previous term is committed once it is stored on a majority of servers.

- [ ] To eliminate that problem, Raft never commits log entries from previous terms by counting replicas.
- [ ] what is counting replicas??

#### 5.4.3 Safety argument

- [ ] Assume that the Leader Completeness does not hold, then prove a contradiction
? what ... how can this prove ? isn't it just prove a example of hold, it does not means it holds for all?...

- [ ] skipped the proof ...

Raft requires servers to apply entries in log index order

### 5.5 Followers and candidate crashes

Raft RPCs are idempotent

### 5.6 Timing and availability

- Safety must not depend on timing
- Availability must inevitably depend on timing

Leader election is the aspect of Raft where timing is most critical

broadcastTime << electionTimeout << MTBF (mean time between failure)

broadcastTime depends on persistent information to stable storage, range from 0.5ms to 20ms
electionTimeout is defined, range from 10ms to 500ms

MTBFs several months or more
