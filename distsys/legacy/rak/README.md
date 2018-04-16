# Using Reasoning About Knowledge to analyze distributed systems

Type: survey

For CMPS232 Fall16

- [Using Reasoning about knowledge to analyze distributed systems](https://www.cs.cornell.edu/home/halpern/papers/UsingRAK.pdf)

Related

- TBD

## Short summary

see [summary.md](summary.md)

Strong points

- definition of notation is very clear
- 'time is meaningless in asynchronous systems' (so real asynchronous systems never exists in reality?)
- implicit knowledge -> deduce from existing knowledge (Other papers (I have read) seems didn't talk about this explicitly)
- recursive everyone knows: f(n) = everyone knows f(n-1), f(1) = everyone knows fact A.

Weak points

- No need to talk about its wide application since most part focus on distributed systems only
- Is it really necessary to put so much logic stuff in this paper
- the PDF file is in poor quality (But it's strange Mendeley can still highlight, PDF is really an amazing format)
- need more graph when it comes to a lot of notation

Questions

- Kind of confused about Sec2. 'agents know only true facts' <- belief 'Although you may have false beliefs, you cannot know something that is false.'
- Sec 6. Page Number 59 'By limiting the number of faults, the adversary can increase the nonfaulty processors uncertainty' why increase? Isn't the goal of the protocol to let everyone agree on something that they are uncertain before running the protocol.
- Sec 6. Page Number 60 'now it is easy to get rid of the tests for knowledge' why they want to get rid of it. (actually I don't know where they define the tests for knowledge)

Miscellaneous

- https://www.mendeley.com/ is awesome for notation and store(sync) papers. And it's FREE. (no more Adobe)

## Supplemental

- ascribe: attribute something to (a cause) 归因于
- proposition: a statement or assertion that expresses a judgment or opinion. 提议
- Propositional logic: https://en.wikipedia.org/wiki/Propositional_calculus
- equivalence relation, binary operation that is reflexive, symmetric, transitive
- P = NP  it asks whether every problem whose solution can be quickly verified by a computer can also be quickly solved by a computer.

## Ref
