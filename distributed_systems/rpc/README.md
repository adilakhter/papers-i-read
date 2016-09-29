# RPC

For CMPS232 Fall16

- [Implementing Remote Procedure Calls](http://www.cs.virginia.edu/~zaher/classes/CS656/birrel.pdf)

Related to [anit-rpc](../anti-rpc)

## TODO

## Short summary

see [summary.md](summary.md)

Strong points

- make remote call like local call can reduce the burden of programmers (when you don't consider robust and scale)
- good graphs, they take a lot space, the paper is really not that long as it seems.
- If you don't care much about those implementation details, it's a clean and straight forward paper.


Weak points

- read like a product report
- The hardware is pretty old compared with what we have these days
- Too much language or platform specific features are used ie: `RPCRuntime is a standard part of the Cedar system`, `These are the basis of the Mesa`. The author is assuming readers know their stack well. However it is possible that what they use was the defacto stack at that time.
- security is their second feature, but it's in subsection with only one paragraph

Questions

- In intro->structure->binding, it mentioned naming, is this the same `naming` appeared in reading list topic? (NO)
- Does this paper give you the desire to read the opposing paper? (Yes)
- TBD

## Supplemental

- TBD

## Ref
