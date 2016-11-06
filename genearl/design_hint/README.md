# Hints for Computer System Design

- [Hints for Computer System Design](https://www.microsoft.com/en-us/research/publication/hints-for-computer-system-design/)

e... 27 pages long

## Requirement for the 200 class

Address the following questions about the paper (the first 6 are fairly standard questions). Put your response to each of these questions under: Confidential remarks for the program committee of the reviewer form (see Submission instructions below).

Provide a brief summary of the paper.
What are its strong points and main contributions?
What are its weak points?
Are the approaches technically sounds?
Comment on the experimental methodology used in the paper (if applicable).
How is the organization and presentation of the paper?
Describe an idea on how you might improve upon the work reported in this paper, or how it might inspire you to apply the findings into another application, or generalize it to a broader formulation, etc.

Summary

This paper provides some hint for system design.
Though most technology it mentioned is now outdated , the design principle can still be applied to topics like distributed system.
It mainly focus on three parts, functionality, speed and fault-tolerance.
And provide detail explanation with latest examples (at that time).
The author himself has a lot experience in building systems, so he can have a high level view of what to consider when building a system.
A common mistake by novice developer is to rush into implementation and ignore improving the specification.
Actually, as mentioned several times in this paper, most time it's a dilemma, a lot of hints in this paper contradicts with
each other, like don't hide power and keep secret from client. Sometimes it takes a long time to know how to keep the balance.
This paper is kind of like a receipt, reading it won't let you become a good chief right away, but at least you can avoid some
common mistakes.

Strong points

- KISS and many other well known design patterns.
- Well organized, figure 1 provide a summary of the whole paper
- Keep the core interface (API) stable (in the same major version)
- Use static analysis tools when possible

Weak points

- quote and words like lest shows the author's personal interest but does not make the paper more intuitive as he supposed.
- not very helpful if you really want to design/build system, it's a general guideline, not some quick start kit. However, as a survey researcher paper, it is doing its best.

Conclusion

This paper is more like a survey paper, and a lot of ideas have become standard in both industry and community, like
semantic versioning, continues integration, code lint, advanced compiler check. However I think reading this paper does
not help me a lot when designing and implementing systems. Because due to the rapid growth of technology, most developer's
no longer have enough time to do full and careful design, instead, fast iteration like agile is becoming popular.
Even for research, you can't expect people to spend years on a system, because by the time it finally release, it may already
be outdated, and the researcher may also stop due to the lack of funding.
The author's idea is somehow too ideal to apply them all in real world.
