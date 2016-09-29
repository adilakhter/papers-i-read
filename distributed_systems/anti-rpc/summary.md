# Anti-RPC

## 1. Intro

Those RPC guys will fail. They want to fill the gap between local and
remote objects, but this only works for small size systems, for enterprise
level distributed systems, this will not work.

## 2. The Vision of Unified Objects

Three phases

- write application without considering object location and communication.
- tune performance
- test with real builds

Principle that seems to hold at glance

- there is a single natural object-oriented design for a given application.
- failure and performance issues should be left out of an initial design.
- the interface of an object is independent of the context in which that object is used.

## 3. Deja Vu All Over Again

Communication Protocols develop follow two path

- integration with current language model
- solving the problems inherent in distributed computing

the language approach has been the less influential one.
when the discover the percentage of distributed application has not increased significantly, they invent new language and protocols and announce a new distributed computing paradigm.

The hard problem is not in the protocols but

- partial failure
- the lack of central resource manager
- concurrency
- different memory access paradigms

## 4. Local and Distributed Computing

Major differences

- Latency
- Memory access
- Partial Failure
- Concurrency

Latency is most obvious but least fundamental.
Partial failure and concurrency make unifying the local and remote computing models impossible without making unacceptable compromises.

### 4.1 Latency

two prong

- rely on the steadily increasing speed of the underlying hardware to make the difference in latency irrelevant.
- use tool to see what pattern of communication is between objects and tuning for efficiency. However, it is important to get the application correct first.

so obvious that mask other (more) important issues.

### 4.2 Memory access

pointers in a local address space are not valid in another address space.

- all memory access must be controlled by the underlying system
- programmers must be aware of the different type of access

there is NO between.

still conceptually possible like latency.

### 4.3 Partial failure and concurrency

Partial failure is detectable in local machine, but not the case for distributed systems.

No common agent that is able determine what component has failed and inform the other components of that failure.
The failure of a network link is indistinguishable from the failure of a processor on the other side of the link


 Insuring the state of the whole system is consistent after such a failure.

 - programs deal with indeterminacy, react in a consistent way to possible partial failures.

 - interfaces connect the components must be able to state whenever the possible the cause of failure
 - interfaces that allow reconstruction of a reasonable state when failure occurs and the cause cannot be determined

 To have a unified model, two paths

 - treat everything as local. -> not robust
 - treat everything as remote -> unnecessary guarantees and semantics for objects that are never intended to be used remote. & oppose the purpose of RPC, which tends to make distributed computing like local computing.

 Different with multi-threaded application

 - no real source of indeterminacy in multi-threaded application.
 - operating system can for resource allocation, synchronization, failure recovery while it's not the case in distributed systems

### 5 The Myth of "Quality of Service"

Throw a question, can using more reliable implementation of interfaces making the system more reliable?

A Queue example to show that vendor software won't work as expected.

Another example of naming.

Two example shows robustness/reliability needs to be expressed at the interface level. And this also applies to performance.

### 6. NFS

An example of a non-distributed application programmer interface re-implemented in a distributed way.

soft mounts -> expose network or server failure to the client program -> file are easily corrupted. -> only read-only or special application
hard mounts -> hangs until server backup -> one machine crashes, all machine freeze -> universal

NFS protocols

- stateless, server doesn't care what happens to the client
- pure client-server protocols, failure can be limited to
  - the server
  - the client
  - the network

The reliability of NFS cannot be changed without a changing the interface to reflect the distributed nature of the application.

### 7. Taking the Difference Seriously

A better approach is to accept that there are irreconcilable difference.
And interface can still be defined using language like IDL, but need to specify it is meant to be used locally or remotely.

Engineers need to know they are dealing with local or remote objects.

### 8. A Middle Ground

in different address space but are guaranteed to be on the same machine.
