# Plutus

TODO: there will be a merge conflict

## Abstract

- secure file sharing without placing much trust on the file server
- highly scalable key management
- filegroups
- read/write
- user revocation
- on top of OpenAFS
  - OpenAFS is still releasing new versions

## Introduction

- data security is important
- [OLD] trust the storage server to controll all users' access to this data as well as return the data intact
  - single user
  - just password

Strong security even with an untrusted server

- all data is stored encrypted
- all key distribution is handled in a decentralized manner

Features

- Detect and prevent unauthorized data modifications
- Differentiate between read and write access to files
- Change users' access privileges

Reason for client side

- avoid compromise? of physical device
- distribute key in user's own way
- most compute are at end system

**Pre-compute the encryption only when data is updated**

## 2. Threat model

- owner
- reader
- writer
- server

### 2.1 Untrusted servers and availiability

- use replica

### 2.2 Trussted client machine

- users must trust their local machine
  - is an open problem

### 2.3 Lazy revocation

- revoked can still read old data, but can not read the new data

### 2.4 Key distribution 

- let user handle them


### 2.5 Traffic analysis and rollback

- don't care

## 3. Design

### 3.1 Filegroups and lockboxes

- group files into filegroups
- directory hierarchy 
- file-lockbox keys (see 3.3)
- also complicate revocation

### 3.2 Keys

- [ ] 3DES ?
- [ ] Box ???
- use Merkle hash tree like Dynamo
- entries of directories are encrypted individually

### 3.3 Read-write differentiation

- the file-sign keys are handed to writers only, while readers get the file-verify keys
- [ ] TODO: so reader got the pub key, writer got the private key? then how the creator revoke it?
- [ ] TODO: reader's can branch a file and share it with others? multi version?

### 3.4 Lazy revocation

- there is no significant loss in security if revoked readers can still read unchanged files

