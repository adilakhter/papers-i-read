# Dynamo: Amazon's Highly Available Key-value Store

For CMPS232 Fall16

- [Dynamo: Amazon's Highly Avaliable Key-value Store](http://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf)

Related to TBD

## Short summary

see [summary.md](summary.md)

Strong points

- what we CAN do by combing technologies and having tradeoffs to make a production distributed system.
- The introduction shows the structure of each section.
- 99.9 percentile for customer experience, engineers' relentless focus. (btw: Does their relentless focus result in higher salary or longer vacation)
- 'Give services control over their system properties, let services make their own tradeoffs', like Waldo's paper, engineers need to know what they are doing, don't try to unify everything.

Weak points

- The first paragraph in introduction is verbose. 'to support continuous growth the platform needs to be highly scalable', 'to support continuous growth, the platform needs to be highly scalable'
- Client application need a lot design. ie: 'require design applications that explicitly acknowledge the possibility of multiple versions of the same data (in order not to lose any updates)'
- Wrong reference, sec 4.4 'Dynamo use vector clocks [12] in order to capture causality between different versions of the same object', but [12]
is Lamport's Time Clock .. 1978.
- For problem that could happen but never surfaced in production they don't
do further investigation, ie: vector clocks truncation scheme may lead to
inefficiencies in sec 4.4

Questions

- what is `application state` mentioned in introduction
- what is consisting hashing
- what is ... see the supplemental part, idk all of them
- sec 2. Each service that uses Dynamo runs its own Dynamo instances.
- sec 2.3 P2 how to detect replica conflicts, the paper only mentioned about how to resolve?
- Oceanstore (https://oceanstore.cs.berkeley.edu/) is mentioned, from its website it seems it is a prototype and not used in production?
- **what is the P2P network talked in the paper different from P2P software we use like BitTorrent, Emule**
- Antiquity and its `Byzantine fault tolerance protocols` is mentioned, how does it do that?
- 4.2 consistent hashing, it says 'heterogeneity' in 2.3 Design Discussion but does consistent hashing distribute load by server capabilities? (in P210, P2 use a variant of consistent hashing)
- is the variant of consistent hashing the `Token Ring`?
- ~~[x] where did they mention coordinator nodes?~~
- can K-V storage like Dynamo be extended to store complex or even relational data. I saw https://github.com/pingcap/tidb (a distributed NewSQL database compatible with MySQL protocol) built on top of https://github.com/pingcap/tikv (Distributed transactional key value database powered by Rust and Raft)

## Supplemental

- synthesis: combination
- [ ] consistent hashing
- [ ] object versioning
- [ ] quorum-like
- [ ] gossip based ?
- expected variance https://www.dartmouth.edu/~chance/teaching_aids/books_articles/probability_book/Chapter6.pdf
- provisioning https://en.wikipedia.org/wiki/Provisioning
- heterogeneity, difference, 多相性
- quorum systems https://en.wikipedia.org/wiki/Quorum_(distributed_computing)
  > The fundamental idea is that a transaction is executed if the majority of sites vote to execute it

## Ref

- [Chord: A Scalable Peer-to-peer Lookup Service for Internet Applications](https://pdos.csail.mit.edu/papers/chord:sigcomm01/chord_sigcomm.pdf)
- [Pastry: Scalable, decentralized object location and routing for large-scale peer-to-peer systems](http://research.microsoft.com/en-us/um/people/antr/PAST/pastry.pdf)
