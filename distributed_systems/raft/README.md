# Raft

Type: novel

For CMPS232 Fall16

- [In Search of an Understandable Consensus Algorithm](https://ramcloud.stanford.edu/wiki/download/attachments/11370504/raft.pdf)

Related

- TBD

## Short summary

see [summary.md](summary.md)

Strong points

- TBD
- TBD
- TBD

Weak points

- TBD
- TBD
- [ ] 5.4.3 the way it prove seems to be wrong? how can you prove is applies to all by just providing a contradiction for it does not applies to all.
it just means it applies to some or maybe just even one.

Questions

- the log index is for each term or one index for all terms (== a log)
- so log just keep growing? never delete old log? space and integer is not enough...?
- how does the leader know all the followers ? how does it identify them? ip? mac address?
- what is counting replicas? it does not explain it? or its just literal meaning?

Miscellaneous

- TBD
- TBD
- TBD

## Supplemental

- Volatile: 易变的，易挥发的
- consecutive: following continuously
- idempotent: 幂等

## Ref

- http://thesecretlivesofdata.com/raft/ from @czheo
