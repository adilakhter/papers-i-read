# Map Reduce

Type: ?

For CMPS232 Fall16

- [MapReduce: Simplied Data Processing on Large Clusters](https://static.googleusercontent.com/media/research.google.com/en//archive/mapreduce-osdi04.pdf)

Related


## Short summary

see [summary.md](summary.md)

Strong points

- We have it running in google
- Its logic is simple and straight
- Optimization like combiner are used to speed up

Weak points

- `There is one master, so the chance it fails is rare and if it fails we abort the job` The master have a lot of work, so even its possibility for failure is less than a bunch of machines, it will have more chances than normal machine which just run something like static file server. Also abort is a waste of resource, maybe it should resume.
- Writing intermediate result to distributed file system is resourcing consuming.
- There are a lot of logic that can not be described using the map reduce model.

Questions

- What does google use before they have map reduce?

Miscellaneous

-
-
-

## Supplemental

- TBD
- TBD
- TBD

## Ref

-
-
-
