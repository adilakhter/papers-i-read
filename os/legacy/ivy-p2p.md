# Ivy: A Read/Write Peer-to-Peer File System

2002, MIT

## TODO

- scan all the logs, can this scale?
- how do dropbox, onedrive solve user modifiying file offline

## Abstract

- Provide integrity without fully trust the storage and other users
- consists solely of a set of logs, one log per participant
- store logs in DHT
- find data by consulting all logs
- perform modification by appending only to its own log
- users can choose which other logs to trust
- 2-3 times slower than NFS on a wide-area network

## Introduction

Challenges

- multiple distributed write makes consistent meta difficult
- unreliable participants make locking a bad approach
- not trust others, ignore or un-do modification by others
- partition
  - allow operation when partitioned
  - repair after partition heal

Solution

- store log in DHT with crypto
- scan all the logs to lookup file data and meta-data
- NFS semantics when fully connected
  - uses a local NFS loop-back server
  - performance is influenced by generating digital signatures on data stored in DHash

Contribution

- read & write p2p
  - previously, read-only / single writer
- integrity based on untrusted components
- DHT for more sophisticated systems
