# Plutus: Scalable secure file sharing on untrusted storage

TODO: there will be a merge conflict

## TODO

- [ ] generate new version, does this have anything to do with block chain
- [ ] is it possible to distinguish different writers

## Ref

- A simple RSA example https://www.cs.virginia.edu/~kam6zx/rsa/a-worked-example/
- FAST2003 Slide http://shiftleft.com/mirrors/www.hpl.hp.com/research/ssp/papers/FAST2003-plutus-slides.pdf

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
- [OLD] trust the storage server to control all users' access to this data as well as return the data intact
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

### 2.1 Untrusted servers and availability

- use replica

### 2.2 Trusted client machine

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
  - so you can don't encrypt them and allow people to browse
  - or you just don't want to people see anything
- [ ] TODO: file-lockbox keys are symmetric keys and are given to readers and writers alike
  - [ ] so we have do distribute the symmetric key
- [ ] TODO: a cryptographic hash of the file contents is signed and verified by a public-private key pair
  - [ ] so the checksum in encrypted using private-pub key pair

### 3.3 Read-write differentiation

- the file-sign keys are handed to writers only, while readers get the file-verify keys
- [ ] TODO: so reader got the pub key, writer got the private key? then how the creator revoke it?
- [ ] TODO: reader's can branch a file and share it with others? multi version?
- writers get (d, N), while readers get (e, N)

### 3.4 Lazy revocation

- there is no significant loss in security if revoked readers can still read unchanged files
- meta data still needs to be immediately changed to prevent further writes by revoked writers
- [ ] filegroups
  - readers and writers can generate all the previous keys of a fragmented filegroup from the current key

### 3.5 Key rotation

- [ ] TODO: don't quite get it ....

Problem 1: Increase in the number of keys in the system following each revocation

- relating the keys of the involved filegroups

Problem 2: hard to determine which file should be moved to when it is re-encrypted

- set up the keys so that files are always (re)encrypted with the key of the latest filegroup
- since keys are related users need to just remeber the lastest keys and derive previous ones when necessary

Two aspects of rotating the keys of a filegroup

- a) rotating file-lockbox keys
- b) rotating file-sign and file-verify keys

Requires

- a) only the owner should be able to generate the next version of the key from the current version
- b) an authorized reader should be able to generate all previous versions of the key from the currrent version.
Then readers maintain access to the files not yet re-encrypted, and readers may discard previous versions of the key.

- each key has
  - a version number
  - associated owner
- each file has
  - owner information
  - version number of the encryption key embedded in the inode

### 3.5.1 Rotating file-lockbox keys

- generate the next version file-lockbox key from the current key by exponentiating the current key with the owner's private key
- *w* file-lockbox key user currently have
  - w = v, ok
  - w < v, user hase been rovked?
  - w > v, need to generate old key using owner's public key
    - [ ] TODO: so the reader key is owner's public key?
- Lamport's password scheme ..... all right Lamport again

### 3.5.2 Rotating file-sign and file-verify keys

- use file-lock box key generated above as a seed
- owner generate **private key as file-sign key**
- writer get the lastest file-sign key
- if the writers have no read access, then they never get the seed
  - [ ] TODO: is the write append only? otherwise the writer can re-write the whole file, which makes it the reader
- change modulus after every revocation is to thwart a subtle collusion attack involving a reader and revoked writer

### 3.6 Server-verified writes

- a file owner stores a hash of a write token stored on the server to validate a writer

## 4. Security analysis

- skip

## 5. Protocols

... bla bla bla
