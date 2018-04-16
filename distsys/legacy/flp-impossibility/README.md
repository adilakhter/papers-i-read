# Impossibility of Distributed Consensus with One Faulty Process

Michael J. Fischer, Nancy A. Lynch, Michael S. Paterson -> FLP

For CMPS232 Fall16

- [Impossibility of Distributed Consensus with One Faulty Process](https://groups.csail.mit.edu/tds/papers/Lynch/jacm85.pdf)

Related

- TBD

## Short summary

see [summary.md](summary.md)

Strong points

- 'No completely asynchronous consensus protocol can tolerate even a single unannounced process death'
- 'These results do not show that such problems cannot be “solved” in practice'
- can't detect death without the help of synchronized clock using time out mechanism

Weak points

- structure is confusing
- How the author comes up with those lemmas that lead to contradiction. The thinking process should be reverse of the proving process.
  But based on the preceding chapters, it's hard to find clue.

Questions

- Intro. 'Apply to even a *very weak form* of the consensus problem.', means a wider range of consensus problems, are there many variant of consensus problem?
- Sec 2. Consensus Protocols, what is transition functions exactly? who perform them, what is their internal logic?
- The message systems feels like lamport's solution for the mutal exclusion problem. So is it just the form that feels alike?

## Supplemental

- stipulating : demand or specify (a requirement), typically as part of a bargain or agreement.
- automata
  - [CS154 - Automata and Complexity Theory](http://web.stanford.edu/~rrwill/cs154-2016/)
- indefinitely : for an unlimited or unspecified period of time.
- tenet in the folklore : 民间宗旨
- comprise: form
- prescribe: ~~define, limit~~ state authoritatively or as a rule that (an action or procedure) should be carried out.
- deterministically: 决定的，宿命的
- subject only to: 只受xxx的限制
- commutative: In mathematics, a binary operation is commutative if changing the order of the operands does not change the result.
- disjoint: (of two or more sets) having no elements in common.
- admissible: acceptable or valid
- bivalent: 二价
- univalent: 一价
- multi-set: {a, a, b} and {a, b} are different multi-set but same set https://en.wikipedia.org/wiki/Multiset

## Ref

- http://the-paper-trail.org/blog/a-brief-tour-of-flp-impossibility/
