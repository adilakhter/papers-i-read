# Submit: Using Reasoning about knowledge to analyze distributed systems

philosophers .... the class before our class is about philosophy ....

This paper is a survey paper, the structure is similar to the causal relationship one.
Though it has some funny examples, like the 'coordinated attack', it's still quite abstract,
making it much closer to the FLP paper. In fact, the definition in section 6 is almost the same
as the FLP one. (However the world `consensus` seems never appear in this paper, it has a reference
form Fischer The consensus problem in unreliable distributed systems though).

Although this paper says it can also be applied to topics outside of distributed systems, most content
still focus on distributed systems, and I doubt if people study logic or philosophy will read this
paper. Maybe the author wants this paper applies to more fields instead of restricting to computer science.
But I think this increase the difficulty for people to understand it, still it's much better than what Lamport did(will do) in Paxos.

It has considered more failure than the FLP one, crash, omission, byzantine (actually it's the first time I
saw the definition of byzantine failure). Because it is trying to figure out a protocol that works instead
of prove impossibility. However it does not talk much about byzantine (or maybe I missed them).

A key concept in this paper is Knowledge. Around the concept of Knowledge, the author talk about a lot of problems we are already familiar with, like mutual exclusion (Lamport Time and Clocks), vector clocks (marked as history in section 2), consensus (marked as common knowledge), run, configuration (FLP). Also there are some new ideas, like implicit knowledge, based on all the local state, processes(processors) can use induction to get more knowledge, which leads to the problem of computation in section 7, which seems none of the existing approach is efficient unless P = NP. (This reminds me of a joke, Jeff Dean proved that P=NP when he solved all NP problems in polynomial time on a whiteboard.)

In general, this survey is very pleasant to read (due to the fact it's between FLP and Paxos).
