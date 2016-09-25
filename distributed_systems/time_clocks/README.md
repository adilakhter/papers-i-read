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
By expanding partial order, we get Clock Condition and two implementation rules, where logical clock ticks
based on events.
Combine all local clocks together we have a system of clocks that can be used for ordering all the events in
the system. To handle equality, we assign order to processes in arbitrary way, note that different order of processes
can generate different total order while the partial order is always the same. Fair method requires clock value.

Using total ordering we can solve mutual exclusion problem without introducing a central process with complex protocol.
It's a distributed algorithm where each processes have a request queue and do comparison locally.
Processes know all the other processes, when one find all the other processes have later request and its request is the
oldest, it can use the resource without concern about conflict. Process crash and message delivery is omitted as implementaion
detail.

To avoid anomalous behavior caused by messages external to the system,
both user action and strong clock condition can be used.
For latter, we specialized the two implementation rule of logical clocks on physical clocks and discuss the time taken for clocks to be synchronized.

strong

- partial ordering is unique
- total ordering can be extended from partial ordering
- physical clocks can be synchronized using the algorithm proposed.

weak

- implementation details for message is ignored (otherwise I won't understand)
- failure is not considered (covered in other paper)
- may not apply to today's multi processes system (I am just guessing)
- the proof in appendix is too hard (for me)

questions

- How to visualize the space-time diagram to 3D, is it possible to extent it to higher dimension for other usage.
- How to extend the algorithm if process join and quit dynamically
- Google is use atomic clock for Spanner, what's its relation with this computer
- For the mutual exclusion example, if use a central lock service, what must be implemented in the message(protocol)

## Ref
