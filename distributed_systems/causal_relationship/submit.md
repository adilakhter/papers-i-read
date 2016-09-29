This paper talks about similar issues as the Lamport one, but at start, it says
it will take real situations into consideration, messages may not be FIFO, there
will be crashes. Then he introduced the concept of causality, which is quite similar to
Lamport's one. Although later in this paper, the author said 'Lamport's terminology is misleading's.
But it does make some assumptions like Lamport, like events are assume to be atomic.
A good news to the readers is that it tells the application about this concept and
later talks about it is not a trivial problem, maybe just too much considering the length
of the paper.

In section 2, the author introduced casual history and vector time. The latter is mentioned
in previous courses as vector clock. It is not simple counter like Lamport clocks, which makes
it more informative. Lamport clock is only consistent but not characterized, these two terms are
mentioned by Prof. Alvaro in previous classes.

However, more information comes at a cost of message size, which may make it hard to work in
real system. So there are two ways, more storage or more computation. This method is to store
old vectors and only send diff. However the diff is incomplete so you can not compare messages
directly before you restore them. The computation one is cost to much and can slow down the
whole system. The author suggests to use it for off-line analysis, which kind of reminds me of
map-reduce and stream processing. The author is more practical than Lamport indeed. I hate him
for having such a long paper, but at least I don't feel like I am in the middle of nowhere.

Next, since vector clocks come at a price, the author search for a lower price, however concurrent
region does not reduce the price. Concurrent region try to solve the order problem from another
perspective but the underlying are same. And the author got the conclusion that this is a non trivial problem,
yeah, I totally agree with you after reading 10+ pages of things do work well. Now I am expecting to
see the one that works well.

And suddenly it comes to Global Predicates, telling me different observer can have different result.
I got the feeling of reading Lamports paper as I was expecting another thing like vector time and concurrent region.
So I head for the bus and go home. That's the end (I will update when I finish the rest)
