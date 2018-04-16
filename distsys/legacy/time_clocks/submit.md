Time, Clocks and the Ordering of Events in a Distributed System talks about
how to define the order in distributed systems, which is different from our physical world.
Message takes time to transport and they may get lost, Lamport covered the latter one in
another paper, The implementation of reliable distributed multiprocess systems.
He introduced partial ordering, logical clocks, and total ordering in order to solve problems
like mutual exclusion and physical clock synchronization.
And he said that algorithm also applies to a single machine with multi processes.

Partial order is composed of two parts, the order inside the process and the order between processes,
the latter is determined by sender and receiver. Symbol -> is used to show this relation.
Logical clock has not relation with physical clock (at first).
By expanding partial order, Clock Condition and two implementation rules can be obtained.
Logical clock ticks based on events.
A system of clocks can be used to order all the events in the system.
To handle equality, the order of processes is assigned in an arbitrary way, result in total ordering with symbol =>.
Note that different order of processes can generate different total order while the partial order is always the same.
Fair method for process order requires clock value.

Using total ordering mutual exclusion problem can be solved without using a central process with a complex protocol.
It's a distributed algorithm where each process have its own local request queue and do comparison locally.
Processes know all the other processes by sending and receiving messages whenever they request or release the resource,
when one find all the other processes have later request and its request is the oldest, it can use the resource without concern about the conflict.
Process crash and message delivery are omitted as implementation detail.

To avoid anomalous behavior caused by messages external to the system, both user action, and strong clock condition can be used.
For latter one, the two implementation rules of logical clocks are specialized on physical clocks.
The time taken for clocks to be synchronized is also discussed.
