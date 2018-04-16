# Using Lightweight Modeling To Understand Chord

For CMPS232 Fall16

- [Using Lightweight Modeling To Understand Chord](http://www.sigcomm.org/sites/default/files/ccr/papers/2012/April/2185376-2185383.pdf)

Related

- [Chord: A Scalable Peer-to-peer Lookup Service for Internet Applications](../chord)

## Short summary

see [summary.md](summary.md)

Strong points

- The implementation problem is a big problem, I recall Prof. Alvaro retweet someone said Lamport said most (or all) implementation of Paxos has misunderstood one line. (And Lamport forgot this in his inbox XD) (Prof. Alvaro got too many tweet, can't find the url ....) I guess there are many implementations running happily in production without knowing which paper has the closet specification, engineering is charming. 
- A lot of counterexamples. (Though I doubt they have much to do with Alloy, the lightweight modeling tool)
- Good advertising `For complex protocols such as Chord, there is every reasons to us the lightweight modeling as a design and documentation tool`

Weak points

- P55 typo `The models written for this paper all allow members to read the state of other members` `all allow` -> `allow all`
- ?w or s Using Alloy, the can be detailed specification and thus it's possible to have multiple version and implementation of chord without digging into the source code.
- `Experience shows, however, that analysis of small systems detects most problems.` But a problem in a small system may never happen in a big system.
Like in a small system, 3 replica may all fail, but in a large system with 100 replica, even 99 replica fails, there is still one working and thus masking
the problem. Just like in the amazon Dynamo paper, they mentioned they never met the problem they suppose they would have in theory when operating the production system. Maybe this is why a lot of counterexample in this paper didn't effect the experiment results in previous papers, like the [TON] one we read.

Questions

- Is Chord itself fault tolerant?
- Is it possible to have a chord instance on each host, so the communication is reduced (no I guess... different application needs their own chord?)
- sec3. 'an application could replicate data by storing it under two distinct chord keys derived from the data's application-level identifier' ... (I understood it after typing the question ....)
- Distributed index ... how to search by keyword when encrypted ... seems to have wrong understaning about it/
- scc 4.3 in the finger table the i^th entry in the tabl at node *n* contains the identity of the first node, *s* that succeeds *n* by at least 2^{i-1} on the identifier circle, ie, s = successor(n + 2^{i-1}), where 1 <= i <= m. What to do when n + 2^{i-1} > 2^m, successor(n + 2^{i-1}) = successor(n + 2^{i-1} - 2^m)?
does that mean there are conflict hash result or it is just the notation.
- Did the author come up with all the counterexamples after modeling Chord using Alloy, or he came up with counterexamples first, then glue Alloy and the conclusion together? Because in math, when disapprove something, we find a special case that break the statement then say `Let c_1 = 1, c_2 = 3, ... prove f(n) < c_2g(n) does not hold`, and sometimes we (at least me) get the special case by guessing.

## Supplemental

- invariant: never changing
- TBD
- TBD

## Ref

- http://alloy.mit.edu/alloy/index.html
