# Secure Untrusted Data Repository (SUNDR)

## Abstract

- SUNDR is a NFS designed to store data securely on untrusted servers
- achieve *fork consistency*
- comparably with NFS ....

## Introduction

- [OLD] High fence
  - hard to use
  - people behind the fence are not trustworthy
- i.e
  - sourceforge CVS
  - Debian development cluster compromised in 2003
  - Apache
  - Gnome

Client can detect any unauthorized attempts to change files

- using public keys

## Setting

- Super user generate pub/private
  - give pub to server
- User has signature key

manage the file system != manage the server

## The SUNDR protocol

formally specify fork consistency, and proven SUNDR protocol

The strongest notion of integrity possible without on-line trusted parties


## 8. Related work

- first system to provide well-defined consistency semantics for an untrusted server
- [OLD] BFS use replication
  - S* does not
- read only P2P
- use version vectors
  - [ ] vector clock?
