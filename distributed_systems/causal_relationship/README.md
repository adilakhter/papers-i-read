# Time, Clocks, and the Ordering of Events in a Distributed System

For CMPS232 Fall16

## TODO

- [ ] read the paper
- [ ] write the summary

## Usage

- Ayi run build
- Ayi run bib
- Ayi run build

## Short summary

see [summary.md](summary.md)

Strong points

- better time space diagram and notation
- attach vector in message instead of a single timestamp, more information and compressed(just cardinality not all the events)
- P8 Lamport's happens before terminology is somewhat misleading (This is not the first paper that pointing this out I suppose)
- It mentions application and consider real situations. ie: the computation for reducing vector is too high so it's better to be used
in off-line analysis.

Weak points

- the paper is too long
- Is this a kind of summary paper? Or it's important to say a lot of related work that does not work well to strength the difficulty of the problem. (before telling the one that works better). Feel kind of lost when you try to find where is the work of the author.
- the introduction and abstract does not help you understand the whole structure and the relation of each section, though most sections have close relationship with its nearby sections.

Questions

- what is atomic, does it have anything to do with the `atomic transaction` in database  
- it mentioned CSP, isn't something in functional programming (I don't know much of either field)
- P7 Definition 3.1 mentioned consistent and characterize, I am sure Prof. Alvaro mentioned these in first or second class but I can't remember the context.
- P10 FIFO channel is needed if we only send the diff of previous sent message. How to maintain a FIFO queue in a distributed system, is
adding local id a practicable approach?
- P16 is the vector clocks size problem solved now? It was an open problem at that time.

## Supplemental

- iff -> if and only if
- [ ] supremum in P5, what does it means
- isomorphic 同形的
- denote 象征 表示
-

## Ref
