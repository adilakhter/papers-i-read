# Concurrency Control Performance Modeling: Alternatives and Implications

http://dl.acm.org/citation.cfm?id=32220

## TODO

- [ ] Optimistic locking in MySQL http://stackoverflow.com/questions/17431338/optimistic-locking-in-mysql
- [ ] Optimistic vs Pessimistic http://stackoverflow.com/questions/129329/optimistic-vs-pessimistic-locking
  - You compare if the data in db is still same
- [ ] serializability, linearlizability, ?
  - [ ] http://cseweb.ucsd.edu/classes/wi17/cse291-d/applications/ln/lecture8.html
- reminds me of jepsen

## Abstract

- we didn't provide new one, we summarize the existing ones
- benchmarks sometimes have seems contradictory result

## Introduction

Three basic algorithms

- locking
- timestamps
  - basic timestamp ordering
  - mutltiversion timestamp ordering
- optimistic concurrency control
  - commit time validation
- [x] didn't talk about mvcc? or it belongs to timestamps? Y

A lot of performance study but the result have been very contradictory

Correctness, serializability, log

**Begin by establishing a performance evaluation framework**

- users
- physical resources
- critical examine the common assumption of infinite resources
- fake restart assumption
- write-lock acquisition

## Concurrency control strategies

- Transaction is a sequence of actions {a1, a2, ..., an}, ai is either read or write
- conflict, ww, wr, rw

Blocking

i.e. Dynamic two phase locking

- set read lock
- upgrade to write lock
- if denied, blocked
- if deadlock is discovered, the youngest transaction in the deadlock cycle is chosen
as victim and restarted

Immediate Restart

- if denied, abort and restart

Optimistic

- allowed to execute unhindered and are validated only after they have reached their commit points.
- restarted at commit point if it finds that any object that it read has been written by another
transaction that commited during its lifetime

Conflict Detection

- as occur
  - Blocking
  - Immediate Restart
- until commit
  - Optimistic

Conflict Resolution

- restart only when necessary (deadlock)
  - Blocking
- always restart
  - Immediate Restart
  - Optimistic

## Performance Model

- database system
  - hardware
  - schedulers
- user
  - arrival prcoess of users
- transaction
  - reference behavior
  - processing requirement

Closed queuing model for single site database system

- ready queue
- cc queue (concurrency control)
- object queue
- block queue

Think path provide delay

- [ ] TODO: so they built a simulator?

Resources

- CPU
- IO

## General Experiment information

### Performance Metrics

- primary: transaction throughput rate
- minor: response time
- blocking ratio
- restart ratio
- total and useful disk utilization

### Parameter Settings

- **allow interesting performance effects to be observed without requiring impossibly long simulation times**

## Resource related assumption

## Transaction behavior assumption

## Conclusion and Implications

When physical resource are limited

- use blocking instead of restart is a better choice

When low resource utilization is ok (infinite resource)

- optimistic is faster

contradictory results are just seems, in fact, not, are **all correct within the limits of their assumption**


the level of multiprogramming in database systems should be carefully controlled.

> Although the hardware costs will continue to fall dramatically and machine speeds will
increase equally dramatically, we must assume that our aspirations will rise even more.
Because of this, we are not about to face either a cycle or memory surplus. For the near-term future, the dominant effect will not be machine cost or speed alone, but rather a continuing attempt to increase the return from a finite resource-that is, a particular computer at our disposal.
