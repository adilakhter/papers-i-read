# Review: Chord: A Scalable Peer-to-peer Lookup Service for Internet Applications

Introduction, Related work, System model are covered in [previous summary](../distributed_systems/chord/summary.md)

## 4. The Base Chord Protocol

- does not handle concurrent joins or failures
- avoid the requirement that every node know about every other node
- each node maintains information only about `O(logN)` other nodes
- lookup requires `O(logN)` messages
- must update routing information with `O(log^2N)` messages

### 4.2 Consistent Hashing
