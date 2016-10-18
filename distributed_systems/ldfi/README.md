# Lineage-driven Fault Injection

Type: ?

For CMPS232 Fall16

- [Lineage-driven Fault Injection](https://people.eecs.berkeley.edu/~palvaro/molly.pdf)

Related


## Short summary

see [summary.md](summary.md)

Strong points

- LDFI has a working implementation Molly and has found bugs which were hard to find using existing methods.
- 'LDFI uses data lineage to reason backwards (from effects to causes) about whether a given correct outcome could have failed to occur due to some combination of faults. Rather than generating faults at random' It's pretty interesting the idea is inspired by database literature notation (Prof. Alvaro: Once and a future DBA :) I quite wonder if the database field is already merged with distributed systems field since most trending open source databases on github are distributed databases, the trend in open source community may different from academic though.
- Molly is quick while tools like Alloy can only apply to small scale due to different design.

Weak points

- It's hard to setup Molly on your own laptop, the instruction seems to be out of date.
- No release, should have some stable release so people can have a try on it without building from the source.
- Test with Travis to ensure new commit don't break old tests/build.

Questions

- LDFI is a combination of top down and bottom up, Is that why the talk is called `Middle of the Maze`? (But what about the Monkeys in Lab Coats talk ....)
- Is it possible that the bugs found by molly only happen in theory but not in real world application due to physical limitations. I mean like the use lightweight modeling
to understand Chord found a lot of counter example of Chord, but it seems people are fine with Chord for a decade until the paper published (12474 citation). Does this also applies to the protocol/systems that Molly found having bugs?
- Is there any tool to checking if model checking tools have problem, a model checker for model checker?
- Can checking tools be applied to themselves? What's the conclusion if they find themselves are wrong?

Miscellaneous

- The commit messages in Molly is not very informative, ie: https://github.com/palvaro/molly/commit/e746cab0fe435efcc6a63ae29188137cb3ad2b7d and
https://github.com/palvaro/molly/commit/48b185de5a6cb789977707df53a47a9c5263846a
- TBD
- TBD

## Supplemental

- TBD
- TBD
- TBD

## Ref

- Review from the morning paper https://blog.acolyer.org/2015/03/26/lineage-driven-fault-injection/
- Prof. Alvaro's talk about LDFI https://www.youtube.com/watch?v=ggCffvKEJmQ
