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

TODO: now comes to their design
