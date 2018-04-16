# A Study of Practical Deduplication

## Take Away

- Each was contacted with an offer to install a file system scanner on their work computer(s in exchange for a chance to win a prize

## TODO

- [ ] modern servers are more application specific, some serve db, some serve assets, some serve video
  - which is quite different from desktop, which is normally a mix of everything

## Ref

- WIM format, use file as unit for compression

## Abstract

- 857 desktop at MS over 4 weeks
- whole file == 3 * block level (for elimination of redundancy)

## Introduction

- whole-file deduplication is simpler and eliminates file-fragmentation concerns
  - at the cost of some ohterwise reclaimable storage
- **it is not obvious that trading away sequentiality for space savings makes sense, at least in primary storage**
- 162 T data, no data center, from normal computers
- file is getting larger (as previous study)
- [OLD] file-level fragmentation is not widespread, contrary to previous work
- [OLD] measuring only fresh file system installation might be ok now
  - at least to the extent that aging produces file-level fragmentation

## 2. Methodology

- file system scanner
- 4.12 T
- **the actual value of any unique hash (i.e. hashes of content that was not duplicated) was not useful to our analyses)**
- 2GB Bloom filter of each hash observed
  - [ ] 2 Bloom filter

bla bla bla
