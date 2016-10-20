# Managing Update Conflicts in Bayou, a Weakly Connected Replicated Storage System

Type: ?

For CMPS232 Fall16

- [Managing Update Conflicts in Bayou, a Weakly Connected Replicated Storage System](http://zoo.cs.yale.edu/classes/cs422/2013/bib/terry95managing.pdf)

Related


## Short summary

see [summary.md](summary.md)

Strong points

- 'clients can read and write to any replica without the need for explicit coordination with other replicas'
- the attitude towards conflict is quite like Dynamo (conflict is application specific). And also like the man who observe the replicated output devices in the state machine replication paper. Someone have to deal with
the conflict.
- the design of the database graph is pretty clear

Weak points

- Bayou does not fits for real time applications. While for now, we use mobile device a lot for things like instant messages. (So how do they guarantee the (a least one) delivery?)

Questions

- What was mobile devices like when author wrote the paper?
- Does online collaborative editing applications use something like Bayou? ie: http://etherpad.org/, google doc etc.
- Program development is mentioned as a application for Bayou. Is Git somehow similar to Bayou?
- Does Bayou have some direct applications after they published the paper? I feel it's still very
academic after so many description on its application, using Bayou is overkill for the applications they described.

Miscellaneous

- TBD
- TBD
- TBD

## Supplemental

- TBD
- TBD
- TBD

## Ref

- http://www.aqualab.cs.northwestern.edu/classes/EECS345/eecs-345-w10/lectures/Bayou.pdf
