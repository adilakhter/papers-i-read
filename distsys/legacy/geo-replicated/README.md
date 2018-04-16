# Stronger Semantics for Low-Latency Geo-Replicated Storage

Type: ?

For CMPS232 Fall16

- [Stronger Semantics for Low-Latency Geo-Replicated Storage](http://sns.cs.princeton.edu/docs/eiger-nsdi13.pdf)

Related


## Short summary

see [summary.md](summary.md)

Strong points

- Eiger is an open source fork of Cassandra
- 'parameterized a synthetic workload based upon Facebook’s production TAO system' Not arbitrary workload.
- 'To make our comparison to Cassandra fair, we implemented an analogous client library that handles the splitting, routing, and re-assembly for Cassandra' Fair compete.

Weak points

- The open source code has too many hard coded values and can only be used for this paper's experiment. (And it have only one commit, leaving no trace of problems they encountered during
development)
- ~~Eiger github repository has only two commit. Lol. (never update after the paper is published #research-products)~~
- The Failure part does not seems to strengthen Eiger. 'transient datacenter failure will be rare (no ill effects)'. Considering Dyn DNS got attack recently, large scale failure is also possible. (Though attacking DNS seems to have more effect on normal user rather than servers)

Questions

~~Found https://www.vicci.org/ in eiger's source code, it seems to be a global cluster that
available for researchers (at what cost)? Have anyone used it before?~~

- Two testbed are mentioned VICCI and PRObE’s Kodiak. What's the requirement for using them?
- When submitting the paper which has benchmark, is it required to provide the raw benchmark result,
if so, is there a standard for that?
- 'COPS and Eiger provide different data models and are implemented in different languages' Does
programming language plays an important role in distributed databases? ie: Databases in C++ should
outperform databases in Java.
- 'The authors would like to thank the NSDI program committee and especially our shepherd, Ethan Katz-Bassett' What is shepherd? Someone from the committee to help you improve the (accepted) paper?
- Does this paper change or have impact on Cassandra's development direction?

- What does Cassandra use timestamp for? Have multiple versions and choose the latest?
~~- The logical time is maintained in one datacenter or across datacenter?~~

Miscellaneous

- very clear description on column based database
- TBD
- TBD

## Supplemental

- exclusively: only, no other
- TBD
- TBD

## Ref

- https://github.com/wlloyd/eiger
- http://spotidoc.com/doc/728186/eiger--stronger-semantics-for-low  (TODO: how to download)
- https://github.com/wlloyd/eiger/blob/eiger-release/vicci_dc_launcher.bash
- http://www.nmc-probe.org/ PRObE’s Kodiak testbed
- https://www.vicci.org/ VICCI testbed
