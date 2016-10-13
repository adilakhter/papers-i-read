# Raft

Type: novel

For CMPS232 Fall16

- [In Search of an Understandable Consensus Algorithm](https://ramcloud.stanford.edu/wiki/download/attachments/11370504/raft.pdf)

Related

- TBD

## Short summary

see [summary.md](summary.md)

Strong points

- Paxos is not simple
- Single direction of log flow make it easier to understand
- Random is understandable and practical

Weak points

- Should have figure for state machine
- Figure 2 lacks a lot of definition of behaviors which you need to find in the paper (Could have more since this an extended version) (I am just lazy)

<!-- TODO: - [ ] 5.4.3 the way it prove seems to be wrong? how can you prove is applies to all by just providing a contradiction for it does not applies to all. it just means it applies to some or maybe just even one. -->

Questions

<!-- - the log index is for each term or one index for all terms (== a log) -->
<!-- - so log just keep growing? never delete old log? space and integer is not enough...? -->
- How does the leader know all the followers and identify them? Have a initial configuration (common knowledge) when everyone starts and use ip/mac address?
- Raft's state machine looks like the one in TCP, is it useful to borrow things like congestion control
- What language feature is required if you want to implement Raft? ie: Multithread. Will there be racing
problem in one node, if so, how to solve it?
- sec 5.4.3 'We assume that the Leader Completeness Property does not hold, then we prove a contradiction'
Then we have the conclusion that Leader Completeness Property hold for all?
<!-- - what is counting replicas? it does not explain it? or its just literal meaning? ... yeah, count the replicas -->

Miscellaneous

- https://thesquareplanet.com/blog/students-guide-to-raft/
- https://thesquareplanet.com/blog/instructors-guide-to-raft/

## Supplemental

- Volatile: 易变的，易挥发的
- consecutive: following continuously
- idempotent: 幂等

## Ref

- http://thesecretlivesofdata.com/raft/ from @czheo
