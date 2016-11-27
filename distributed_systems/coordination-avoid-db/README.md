# Coordination Avoidance in Database Systems

For CMPS232 Fall16

- [Coordination Avoidance in Database Systems](http://www.vldb.org/pvldb/vol8/p185-bailis.pdf)

Related

TODO: CRDT and Bloom^L

## Short summary

see [summary.md](summary.md)

Strong points

- 'when is coordination strictly necessary' to maintain application level consistency
- OLTP Benchmark suite. (The most useful reference for me in this paper)
- apply to SQL. If the change can be transparent for existing tools, developers would be happy to adopt it
- 'coordination can only be avoided if all local commit decisions are globally valid'
- One of the ref `Principles of Distributed Databases Systems` seems to provide a lot of refer

Weak points

- 'we require the programmer to specify her correctness criteria'. Sometimes I think programmers can't figure correctness criteria out, the may have an outline but don't know how to write it down correctly. i.e. what he wrote is not what he actually had in mind.
- no much about the prototype they wrote, they can cut some related work and leave some space for it.
- no much information about the hardware the benchmark is running on, i.e. dedicated server or vm from cloud service providers.

Questions

- How the author get 200 servers to run test?
- 'gifts from AmazonWeb Services, Google, SAP, the Thomas and Stacey Siebel Foundation, Adobe, Apple, Inc., Bosch, C3Energy, Cisco, Cloudera, EMC, Ericsson, Facebook, GameOnTalis, Guavus, HP, Huawei, Intel, Microsoft, NetApp, Pivotal, Splunk, Virdata,VMware, and Yahoo!.' so many gifts ....

Miscellaneous

- 'The authors would like to thank Peter Alvaro'
- 'in the form of invariants' remind me of adversary argument. Now I think Molly is kind of like adversary argument. (I didn't know it when read the Molly paper)


## Supplemental


## Ref
