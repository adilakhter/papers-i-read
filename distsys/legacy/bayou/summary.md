# Summary: Managing Update Conflicts in Bayou, a Weakly Connected Replicated Storage System

## Abstract

Design for mobile computing environment.

- move towards eventual consistency
- conflict detection: dependency checks

## Introduction

- Bayou design requires only occasional, pair-wise communication between computers.
- [ ] A weak connectivity networking model can be accommodated only with weakly consistent, replicated data.
- clients can read and write to any replica without the need for explicit coordination with other replicas.
- application must be aware that they may read weakly consistent data and also that their write operations may conflict with those of other users and applications.
- letting applications exploit domain-specific knowledge to achieve automatic conflict resolution at the granularity of individual update operations without compromising security or eventual consistency
- client can read data at all times, including data whose conflicts have not been fully resolved.

## Bayou Applications

- [ ] it's quite interesting to have single chapter to talk about application of the product.
- [ ] but I think both of those applications are not that ... meaningful ...

## Bayou's Basic System Model
