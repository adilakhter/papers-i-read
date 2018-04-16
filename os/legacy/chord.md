# Review: Chord: A Scalable Peer-to-peer Lookup Service for Internet Applications

2003, MIT

Introduction, Related work, System model are covered in [previous summary](../distributed_systems/chord/summary.md)

## 4. The Base Chord Protocol

- does not handle concurrent joins or failures
- avoid the requirement that every node know about every other node
- each node maintains information only about `O(logN)` other nodes
- lookup requires `O(logN)` messages
- must update routing information with `O(log^2N)` messages

### 4.2 Consistent Hashing

- hash node IP -> *m* bit
- hash key -> *m* bit
- use base function like SHA-1
- *m* must be large enough to make the probability of two nodes or keys hashing to the same identifier negligible
- successor: Key *k* is assigned to the first node whose identifier is **equal** or **follows** (the identifier of) k in the identifier space. This node is called the successor node of key k, denoted by *successor(k)*. If the identifier are represented as a circle of numbers from 0 to 2^m - 1, the *successor(k)* is the first nod clockwise from k.  
- join: keys previously assigned to *n*'s successor now become assigned to *n*
- leave: all keys are reassigned to *n*'s successor
- > the consistent hashing paper shows that ? can be reduced to an arbitrarily small constant by having each node run O(log(N)) **virtual nodes** each with its own identifier

### 4.3 Scalable Key Location

- routing information for speed up
- as long as successor information is maintained correctly, the correctness is guaranteed

### 4.4 Node Joins

- each node maintains a predecessor pointer
