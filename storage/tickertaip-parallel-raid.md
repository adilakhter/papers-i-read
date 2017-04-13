# The TickerTAIP Parallel RAID Architecture

HP Lab 1994

## TODO

- [ ] disk controller
- [ ] disk string??
- [ ] why XOR can be used for RAID parity
- [ ] is file system still aware of the underlying sector, cylinder group when RAID is used?

## Term

- Disk array

> A disk array is a structure that connects several disks together to extend the cost,
power, and space advantages of small disks to higher-capacity configurations. By providing partial
redundancy such as parity, availability can be increased as well.

- RAID parity http://www.pcmag.com/encyclopedia/term/60364/raid-parity

> Parity computations are used in RAID drive arrays for fault tolerance by calculating the data in two drives and storing the results on a third. The parity is computed by XOR'ing a bit from drive 1 with a bit from drive 2 and storing the result on drive 3. After a failed drive is replaced, the RAID controller rebuilds the lost data from the other two drives.

## Abstract

Traditional disk arrays have a centralized architecture, **single controller**

- single point of failure
- limit max number of disks

Distribute the controller functions across several loosely coupled processors

- a family of distributed algorithms for calculating RAID parity
  - [ ] what are distributed algo and RAID parity
- request atomicity
- sequencing
- recovery
- disk-level request-scheduling algorithm inside the array

RAID (Redundant Arrays of Inexpensive Disks) 0, 1, 3, 5

![traditional RAID architecture](images/traditional_RAID.png)

SCSI (Small Computer System Interface)

Existing

- primary backup
  - expensive (backup is only used when primary fails)
- disjoint set of disks
  - [ ] limit the performance available from the array (but why?)

New Architecture

- a cooperating set of array controllers nodes
  - fault tolerance
  - performance scalability
  - smooth incremental growth
  - flexibility

Experiments 

- working prototype
- event based simulation

## The TICKERTAIP Architecture

- Originator: host interface
- Worker: connect to disk

assume **parity calcution is a driving factor in determing the performance of a RAID array**

- several originator node connect to different host
- a single host can be connected to multiple originators for higher performance and greator failure resilience

processors are cost-effective engines for calculation parity

- processors are cost-effective engines for calculation parity
- memory bandwidth, rather than processor cycles, is the determining cost factor in providing this functionality
- the cheap commodity microprocessors it uses for the control functions can also be used as the parity calculation engines

## Related Work

- make extensive use of well-known DB techniques such as two-phase commit, partial write ordering
- RADD (Distributed Disks) is for wide area network, while this paper is for everything in one cabin

## Design Issues 

RAID 5 as example

- normal mode read
  - skip parity blocks
- normal mode write
  - how to calculate new parity
    - full stripe 
    - small stripe
    - large stripe
- where to calculate new parity
  - every node has processor, can put it in non originator nodes
  - at originator
  - solely-parity (use more messages, ignored)
  - at-parity

### Single Failures - Request Atomicity


  

