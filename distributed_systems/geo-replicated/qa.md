# Questions from Easychair

Only selected some I think is useful (answer without extra notation is from Prof. Alvaro)

> The only weak point I can see is that there is no evaluation in reliability. The fault tolerant capacity looks good in the paper, but if add the evaluation of the failure model could be better.

yes, I see what you mean. what do you think would be a good large-scale evaluation to demonstrate the fault tolerance of eiger? this is not a rheorical question: I am curious myself.

> What I wished this paper would include was a case study or use case to better understand Eiger.

I couldn't agree more. the programming model that they present is a bit arcane. it resembles DB transactions, but is significantly weaker because it disallows R/W transactions (for example, it would appear that you can't even implement a compare-and-swap using eiger).

so it would seem that the authors need to argue that their approach is not only low latency, but that it is *useful* for some large class of applications. a good case study would have gone a long way here.

> Is causal consistency the strongest form of consistency that is achievable in low-latency systems?

GREAT question.

this question cuts to the heart of the matter. colloquially, yes! if you dig around in the contemporary distributed systems literature, there are many informal arguments that causal is the strongest form consistency that provides availability under arbitrary partitions.

I have never read a formal proof, but here would be a good place to look:

[P. Mahajan, L. Alvisi, and M. Dahlin. Consistency, availability, and
convergence. Technical Report TR-11-22, Univ. Texas at Austin, Dept.
Comp. Sci., 2011.](http://www.cs.utexas.edu/users/dahlin/papers/cac-tr.pdf)
