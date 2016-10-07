# Summary: Impossibility of Distributed Consensus with One Faulty Process

Don't want to go back the old way ... but I don't think I can finish using the
printed version

## Introduction

> The problem of reaching agreement among remote processes is one of the most fundamental
problems in distributed computing and is at the core of many algorithms for distributed
data processing, distributed file management, and fault-tolerant distributed applications.

In DB, the `transaction commit problem`, all nodes must agree one the same decision.

Partial failure -> The best is tolerant to a prescribed number of "expected" faults.

**No completely asynchronous consensus protocol can tolerate even a single unannounced process death**

- No Byzantine failure.
- reliable message, deliver correct message exactly once.

Assumptions

- processing is completely asynchronous
- not access to synchronized clocks -> time out can't be used
- can't detect death

Apply to even a *very weak form* of the consensus problem.

- All processes starts with initial value in {0,1}
- A nonfaulty process decides on a value in {0,1} by entering a appropriate decision state.
- All nonfaulty processes that make a decision are required to choose the same value.

? For the purpose of the impossibility proof, we require only that *some* process eventually make a decision ?
- [ ] so other processes stay in a state of what?
- [ ] 0 is always chosen is ruled out by stipulating that both 0 and 1 and possible decision values, although perhaps for
different initial configurations.

- Processes are modeled as automata (with possibly infinitely many states?) that communicate by means of messages
  - [ ] infinitely?
- In one atomic step, a process can attempt to receive a message, perform local computation on the basis of whether or not a message
  was delivered to it (and if so, which one), and send an arbitrary but finite set of messages to other processes.

> In particular, an "atomic broadcast" capability is assumed, so a process can send the same message in one step to all other processes
with the knowledge that if any nonofaulty process receives the message, then all the nonfaulty processes will.  

- [ ] but based one the assumption, how can the message failed to deliver? example scenario?

- Every message is eventually delivered, but time and order is not guaranteed.

Prove a widely believed tenet in the folklore -> all asynchronous commit protocols have a "window of vulnerability" - an interval of time during
the execution of the algorithm in which the delay or inaccessibility of a single process can cause the entire algorithm to wait indefinitely.

- [ ] which interval of time ?

## Consensus Protocols

A *Consensus protocol* P is

- an asynchronous system of N (N >=2) processes.
- each P has ... -> internal state
  - input register x_p
    - [ ] does input also have values in {b, 0, 1}
  - output register y_p values in {b, 0, 1}
    - [ ] why there is a value b? (for beginning I guess...)
    - is write once
  - unbounded amount of internal storage
  - program counter?
    - [ ] what is program counter?

Initial states (prescribe)

> Initial states prescribe fixed starting value for all but the input register

- [ ] does the above <-> Initial states set y_p to b

- x_p = ?
- y_p = b

Decision states

- y_p = 0 || 1

p acts deterministically according to a *transition* function

Transition function

- cannot change y_p once the process has reached a decision state <-> can only change y_p with value b <-> y_p is write once
- [ ] who execute the transition function?

The entire system P is specified by

- transition functions associated with each of the processes
- initial value of the input registers

Message

- Processes communicate by sending each other messages
- A pair of (p, m)
  - p: name of the destination process
  - m: message value from a fixed universe M
    - [ ] what is `a fixed universe M`
- message buffer (keep messages that have been sent but yet not delivered)
  - [ ] how to know the message is delivered? As long as one nonfaulty process receive it? using ACK?
  - send(p, m): Places (p,m) in the message buffer
  - receive(p): Delete some message (p,m) from the buffer and return m, in which case we say
    (p, m) is delivered, or returns the special null marker and leaves the buffer unchanged
    - [ ] feels like lamport example for the mutual exclusion problem
    - [ ] whoes buffer? the sender's ?
    - [ ] why null marker? delete once? when other receiver ack there is nothing to delete?
    - [ ] who and how to invoke the receive operation, transition function?
- if receive(p) is performed infinitely many times, then every message (p, m) in the buffer is eventually delivered.
- [ ] > the message system is allowed to return null mark a finite number of times in response to receive(p),
    even though a message (p,m) is present in the buffer.

Configuration

- internal state of each process
- contents of the message buffer
- *initial Configuration*
  - initial state (y_p = b)
  - empty buffer
- [ ] is this a global view?

Step

- take one configuration to another and consists of a primitive step by a single process p
- First: receive(p) is performed on the message buffer in C to obtain a value m belongs to M or null marker
- Second: p enter a new internal state and send a finite set of messages to other processes

Event

- e = (p, m)
- the receipt of m by p
- e(C) denotes the resulting configuration, we say that e can by applied to C.
- e(p, null) can always be applied to C

Schedule

- A schedule from C is a finite or infinite sequence $\\sigma$ of events that can be applied, in turn, starting from C.
- The associated sequence of steps is called a *run*
- [ ]  *schedule* = C + *run*
- if $\\sigma$ is finite, we let $\\sigma$(C) denote the resulting configuration, which is said to be reachable
from C. A configuration reachable from some initial configuration is said to be *accessible*.

Lemma 1

- C -> C_1
- C -> C_2
- sg1 && sg2 == null (processes disjoint)
- C_1 + sg2 == C_2 + sg1 == C_3

A configuration C has decision value v if some processes p is in a decision state with y_p = v
- [ ] some process?

Partially correct

- No accessible configuration has more than one decision value
- For each v belongs {0,1}, some accessible configuration has decision value v

A process p is nonfaulty in a run provided that it takes infinitely many steps, and it is faulty otherwise.
- [ ] infinitely?

A run is *admissible* provided that at most one process is faulty and that all messages sent to nonfaulty processes are eventually received

A run is a *deciding* run provided that some processes reaches a decision state in that run

A consensus Protocol P is totally correct in spite of one fault if

- it is partially correct
- every admissible run is a deciding run

But the second one does not hold for every protocols

## 3. Main Result

Theorem 1. No consensus protocol is totally correct in spite of one fault

Proof: a sequence of lemmas which eventually lead to a contradiction

Show circumstances under which the protocol remains forever indecisive

- First: there is some initial configuration in which the decision is not already predetermined
- Second: construct an admissible run that avoids ever taking a step that would commit the system to a particular decision

Let

- C : Configuration
- V : the set of decision values of configurations reachable from C

- C is *bivalent* if |V| = 2
  - [ ] what does the | mean?
- C is *univalent* if |V| = 1

Lemma 2.

- P has a bivalent initial configuration

- [ ] ? what does the | means exactly?

Lemma 3.
... can't write without latex style ..

## 4. Initially Dead Processes

A protocol that solves the consensus problem for N processes as long as a majority of the processes are nonfaulty and no processes dies during the
execution of the protocol.

No processes knows in advance.

## 5. Conclusion 
