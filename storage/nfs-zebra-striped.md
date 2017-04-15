# The Zebra Striped Network File System

1994 UCB

## Take away

## Abstract

- increase throughput by striping file data across multiple servers
- forms all the new data from each client into a single stream
- stripe using an approach similar to log-structured file system
- write parity information in each stripe in the style of RAID disk arrays
- 4-5 times for large files
- 20%-3x for small files
