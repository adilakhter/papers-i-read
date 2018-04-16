# Building Consistent Transactions with Inconsistent Replication

Type: ?

For CMPS232 Fall16

- [Building Consistent Transactions with Inconsistent Replication]()

Related


## Short summary

see [summary.md](summary.md)

TAPIR the Transactional Application Protocol for Inconsistent Replication.

Strong points

- 'existing transactional storage systems waste work and performance by integrating a distributed transaction protocol and a replication protocol that both enforce strong consistency'
- 'We give a brief sketch of correctness.' Talk is cheap, show me the code, code is cheap, show me the proof.
- code is available here https://github.com/UWSysLab/tapir (But it seems people only make their work public after their paper got accepted by conference)

Weak points

- 'IR supports only fail-stop failures, not Byzantine faults or actively malicious servers' what about other failure model like omission failure?


Questions

- what's the difference between VR and Paxos (I found a paper https://www.cs.cornell.edu/fbs/publications/viveLaDifference.pdf)
- Has anyone tried use things like Jepsen on TAPIR (I finally realized why it is call Jepsen since
  call me maybe is by Carly Rae Jepsen)
- why everyone seems to be building K-V store these days? Because it can be extended to most more complex data models?
- The benchmark they mentioned http://docs.spring.io/spring-data/data-keyvalue/examples/retwisj/current/ use Redis with key like 'user:springrod:uid' does it means every K-V store can be used like a column base database with some
effort?

Miscellaneous

- TAPIR use YCSB for benchmark https://github.com/UWSysLab/tapir/tree/master/ycsb-t
- The original retwisj is here by the Redis author https://github.com/antirez/retwis
- about VR protocol https://blog.acolyer.org/2015/03/06/viewstamped-replication-revisited/

## Supplemental

- TBD
- TBD

## Ref

- https://github.com/UWSysLab/tapir
