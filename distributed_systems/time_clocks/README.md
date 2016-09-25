# Time, Clocks, and the Ordering of Events in a Distributed System

For CMPS232 Fall16

## TODO

- [x] format and cleanup, add TBD etc.
- [ ] write the review and questions for the assignment in MD
- [ ] submit on easychair.
- [ ] watch the video from udacity/youtube and finish the summary.

## Usage

- Ayi run build
- Ayi run bib
- Ayi run build

## Short summary

Time, Clocks and the Ordering of Events in a Distributed System talks about
how to define order in distributed systems, which is different from our physical world.
Message takes time to transport and they may get lost, Lamport covered the latter one in
another paper, The implementation of reliable distributed multiprocess systems.
He introduced partial ordering, logical clocks and total ordering in order to solve problems
like mutual exclusion and physical clock synchronization.
And he said those algorithm also applies to a single machine with multi processes.

Partial order is composed by two parts, the order inside the process and the order between processes,
the latter is determined by sender and receiver. Symbol -> is used to show this relation.
Logical clock has not relation with physical clock (at first).
By expanding partial order, Clock Condition and two implementation rules can be obtained.
Logical clock ticks based on events.
A system of clocks can be used to order all the events in the system.
To handle equality, order of processes is assigned in an arbitrary way, result in total ordering with symbol =>.
Note that different order of processes can generate different total order while the partial order is always the same.
Fair method for process order requires clock value.

Using total ordering mutual exclusion problem can be solved without using a central process with complex protocol.
It's a distributed algorithm where each processes have its own local request queue and do comparison locally.
Processes know all the other processes by sending and receiving messages whenever they request or release the resource,
when one find all the other processes have later request and its request is the oldest, it can use the resource without concern about conflict.
Process crash and message delivery is omitted as implementation detail.

To avoid anomalous behavior caused by messages external to the system, both user action and strong clock condition can be used.
For latter, the two implementation rule of logical clocks are specialized on physical clocks.
The time taken for clocks to be synchronized is also discussed.

strong

- partial ordering is unique
- total ordering can be extended from partial ordering
- physical clocks can be synchronized using the algorithm proposed.

weak

- implementation details for message is ignored (otherwise I won't understand)
- failure is not considered (covered in other paper)
- may not apply to today's multi processes system (I am just guessing)
- the proof in appendix is too hard (for me)

raised questions

- How to visualize the space-time diagram to 3D, is it possible to extent it to higher dimension for other usage.
- For the mutual exclusion example, if I want to use a central lock service, what must be implemented in the message(protocol) to avoid ordering problem.
- In network protocols like TCP, state machine can also be used, what's the similarity and difference between the one mentioned in total ordering.
- If we need to choose a protocol for send message, should we use reliable transport like TCP? If use UDP, what else should we do?
- How to extend the algorithm to multiple resources, is having multiple queues a practicable approach?
- The algorithm assume every process can talk freely, what if processes have level and each level can only talks to its neighbors. ie: Lv2 can talk to Lv1 and
  Lv3 but not Lv4. Does this algorithm still apply? Which structure is more efficient and/or stable, the plain one or the multiple level one.
- Can we still use the algorithm if process join and quit dynamically?
- Google is use atomic clock for Spanner, what's its relation with this paper?
- What are other clocks used in distributed system?
- When did Lamport invented Latex? What's the difference between Tex and Latex?
- Does easychiar support **markdown**?

## Ref
