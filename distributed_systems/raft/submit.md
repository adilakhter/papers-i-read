# Submit: Raft

Raft is easier to understand and thus more popular. The paper itself is more like a specification, which
makes engineers easy to follow.

And it's a good idea to actually implement the raft consensus protocol,
reading the code and write the code can help each other, MIT6.824 lab is highly recommended.
Though do remember you are trying to implement the protocol not practice programming skills, otherwise you would waste a lot of time on choosing language, using fancy syntax (that few people can understand), rewrite
existing libraries (like I am doing). And can't meet the deadline. 

When implementing raft, it's good to draw a state machine graph and carefully read Figure2, and have to read
the paper several times, it's easy understand but have a lot of details that can't remember after one time read. And one thing good about follow the MIT6.824 lab is it's step by step, first election, then log replication, finally persistent. The best thing is they have test case. If you look at some popular raft implementations they have all the scenarios mentioned in the paper in their test.

And don't look at existing implementations too soon, some have dirty tricks (like using goto), some have things that they think(maybe the have tried) would boost performance. It's easy to get lost.

When looking at existing implementations, clone the repository and choose a good local editor that have `jump to definition`, `find in path`. Even using the same language, different implementations have their
own style and tricks. (I like dirty tricks)

Ref

- https://pdos.csail.mit.edu/6.824/labs/lab-raft.html
