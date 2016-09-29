# Anti-RPC

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
- `Difference between local and remote need be represented in all level, from system to application` This may not apply, novice programmers are using frameworks
that hide all the detail, just need to focus on business logic. Or maybe they are not qualified as engineer in the author's standard.
- Does not have conclusion, end with `Middle of ground`

Questions

- The author mentioned 'major changes in implementation language is required in order to make local computing follow the model of distributed computing' in section 7 (taking the difference seriously). Is this the reason why language like Erlang, frameworks like Akka arise? Will those new languages and
frameworks be the ultimate solution or just another iteration like mentioned in section 3 (Deja Vu All Over Again)?

- sec.7 The author said `Distributed objects are different from local objects, and keeping that difference visible will keep the programmer from forgetting the difference and making mistakes` However, nowadays language, frameworks and Sass are trying to make reading manual and implementing business logic the major task for most programmers. Don't know if this is a good thing or not, if in the future machine can understand manual and glue code together like human, the CS department will have few applicants.

- TBD

## Supplemental

- Indeterminacy: not sure

## Ref
