# RPC

For CMPS232 Fall16

- [Ceph: A scalable, High-Performance Distributed File System](https://www.usenix.org/legacy/event/osdi06/tech/full_papers/weil/weil.pdf)

Related to

## Short summary

see [summary.md](summary.md)

Strong points

- Ceph is suitable for the need of HPC community
- Using the default local file system like ext3 limit the performance of a distributed file system. (But I wonder if this is the real bottleneck)
- CRUSH use random to distributed data, which is easy and efficient.

Weak points

- Little detail about the monitors, how are they distributed, in another rack/dc or evenly into every rack? what consensus protocol?
- Ceph does not compare itself with other file distributed systems,
and benchmark by third party shows it has performance issue, compared with HDFS and GlusterFS [2] [3]
- The roadmap of Ceph seems pretty vague [4], latest issues are on 2015
- Maybe they can add abnormal behavior of client into failure detection. Like the client open a file but died before close it. When
there are a lot of clients, they will fail as the servers, which is addressed in the replicated state machine paper.


Questions

- 'Grid-based file systems' is mentioned in related work, what's the relationship between grid computing and distributed systems?
- 'HPC' is mentioned several times, however a lot of distributed applications like to say the scale and run well on cheap hardware.
In China they call it get rid of IOE (IBM, Oracle, EMC). I am curious that if there are many people tailoring distributed systems for high end hardwares?
- During replication, why send an `ack` to client before `commit`, since only when `commit` is sent all data are wrote to disk in all replicate OSDs.
(Kind of like buffer in local file systems? only flush data in cache to disk until it reaches the amount or you close the file?)
- Is it possible to use things like FPGA for distributed file systems to reduce the cost from using a full operating systems.
Also small OS like alpine [5] is widely used in containers.

## Supplemental

- user space https://en.wikipedia.org/wiki/User_space
- POSIX https://en.wikipedia.org/wiki/POSIX
- grid computing https://en.wikipedia.org/wiki/Grid_computing

## Ref

- [1] http://docs.ceph.com/docs/master/architecture/
- [2] Testing of several distributed file-systems (HDFS, Ceph and GlusterFS) https://indico.cern.ch/event/214784/contributions/1512447/attachments/340854/475673/storage_donvito_chep_2013.pdf
- [3] http://iopscience.iop.org/article/10.1088/1742-6596/513/4/042014/pdf
- [4] http://tracker.ceph.com/projects/ceph/roadmap
- [5] Alpine Linux is a security-oriented, lightweight Linux distribution based on musl libc and busybox https://www.alpinelinux.org/
