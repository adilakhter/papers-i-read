## 1. Intro

<!-- TODO: Add section for the following summaries -->

Fault is considered, no longer ideal, no FIFO.

standard enumeration of E_i

3 kinds of Events
- send event
- receive event
- internal event

Events are assume to be atomic (Q)

Do not deal with conflicts explicitly

causality relation (same as Lamport's happens before)

—> is
- irreflexive
- asymmetric
- transitive

P4 **the notion of consistency in distributed systems is basically an issue
of correctly reflecting causality.**

Applications

- obtain a consistent view in order to correctly evaluate the global predicate
- detect race condition and other synchronization errors
- proper replay of concurrent activities in distributed systems for the purpose of
debugging and monitoring

P4 [50] replay data can be reduced by appropriately representing the causal structure
of the computation.

- exploitation of Maximum parallelism

## 2. Causal History and Vector Time

C(e) contains all the events happens before e

when e is a receive event, s is the corresponding send event. C(e) = C(e_ij-1) U C(s) U {e_ij}

### 2.2 Vector Time

reduce call history size

P6 Rules to maintain vector time

- N Processes, initial V_i[k] = 0 for k = 1.... N
- each internal event V_i[i] := V_i[i] + 1
- send message m, update as 2), and attach the new vector to the message
- receive message m. update as 2), V_i := sup{V_i, V(m)}

## 3. Causality and Time

vector time's relation to real time.

the structure of vector time is isomorphic to the causality structure of the
underlying distributed computation.

**Definition 3.1** mentioned consistent and characterize

consistent - if
characterize - if and only if aka. iff

P7 **Definition 3.2** How to compare vector time 
