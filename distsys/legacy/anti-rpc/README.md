# A Note on Distributed Computing (anti-rpc)

For CMPS232 Fall16

- [A Note on distributed computing](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.41.7628)

Related to [RPC](../rpc)

## Short summary

see [summary.md](summary.md)

Strong points

- unify local and remote for the sake of easier programming in distributed systems is doomed to fail.
- latency is the most obvious problem but not the key problem, partial failure and concurrency are.
- there exists systems site between local machine and distributed system.
- use real world product like NFS as an example for the unifying interface part.

Weak points

- `New language and models mainly focusing on protocols and neglect problems like partial failure and concurrency.` This is not the case for now.
- Does not have conclusion, end with `Middle of ground`

Questions

- The author mentioned 'major changes in implementation language is required in order to make local computing follow the model of distributed computing' in section 7 (taking the difference seriously). Is this the reason why language like Erlang, frameworks like Akka arise? Will those new languages and frameworks be the ultimate solution or just another iteration like mentioned in section 3 (Deja Vu All Over Again)?

- `Difference between local and remote need be represented in all level, from system to application` Could there be abstract in level higher than application and system that user don't need to care about the difference?


## Supplemental

- Indeterminacy: not sure

## Ref
