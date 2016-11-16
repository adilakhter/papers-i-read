# RPC

For CMPS232 Fall16

- [Sinfonia: a new paradigm for building scalable distributed systems](http://read-new.seas.harvard.edu/~kohler/class/cs239-w08/aguilera07sinfonia.pdf)



## TODO

## Short summary

see [summary.md](summary.md)

Strong points

- data locality is important. Ceph also mentioned it.
- 'The key to achieving scalability is to decouple operations executed by different hosts as much as possible' as mentioned in previous paper by people from industries
- the minitranscation idea seems great

Weak points

- Sinfonia is kind of like RPC, which tries to hide the detail from developer, but it also want tries to give developer more freedom (no specific data structure). Some ideas from Jim Waldo's 'A Note on Distributed Computing' (against RPC) can also be applied to Sinfonia, it tried to remove the differences that should not be kept away from developers
- Sinfonia seems have made too many assumptions, a lot failure are not that rare as it suggests
- Use primary-copy for replication and mark state machine replication as TODO
- Frameworks like Akka seems to allow even lesser code to built what is mentioned in the paper.


Questions

- What's the difference between Sinfonia and RAMCloud? It seems RAMCloud has data structure well defined [1].
- Is Sinfonia actually used by any company in production system? How do companies keep a very huge RAM, like put all the index in the RAM. (Facebook seems to put search index for HBase in RAM)

Ref

- [1] 'Powerful data model' https://ramcloud.atlassian.net/wiki

Miscellaneous

- Found something similar to easychair on github https://github.com/kohler/hotcrp

## Supplemental

- TBD

## Ref
