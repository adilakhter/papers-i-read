# Practical Byzantine Fault Tolerance

Type: ?

For CMPS232 Fall16

- [Practical Byzantine Fault Tolerance](http://pmg.csail.mit.edu/papers/osdi99.pdf)

Related

- [Raft](../raft)
- TODO: Paxos

## Short summary

see [summary.md](summary.md)

Strong points

- Good paper structure, byzantine failure is a problem -> existing solution are limited (synchronous etc.) -> we have a new state machine replication protocol that tolerates that -> we show you the proof -> we made it -> it works good (at least in the evaluation)
- It address its limitation in the assumption, like the computation power the attacker has is limited (otherwise crypto equals to plain text), btw: I think bitcoin has
go beyond this limitation, since everyone is trying to make more bitcoin using the powerful machine instead of compromise the bitcoin network. (Use human weakness to solve problems that can't be solved by technology?)
- Optimization make the protocol practical, the more your protocol guarantee, the more cost in time and money. (btw: it is known the allowed transactions rate for bitcoin
is too low to make it used by normal people)

Weak points

- the configuration is fixed, since the leader (primary) is picked by ViewNumber mod NumberOfReplica.
- when 3f+1 is satisfied, adding more machine does not help, but add 3 machines increase f by 1.
- ViewNumber mod NumberOfReplica may have some performance suffer if a series of node are faulty, ie: let f = 3, 1,2,3 are in one rack, 4...13 are in other racks, 1 is the initial primary before it down with its rack, the system have to go through 2,3 and if somehow due to partition, the view number bump to 14, 1,2,3 need to be considered primary again. (Though you assign the id randomly instead of rack by rack)
- BFS is really not a good name for a product, people can't find you on the first page of search result.

Questions

- The 3f+1 seems to be different from the state machine replication paper we have read, where 2f+1 is required.
- Confused about the commit local and commit.
- It mentioned crypto using Key. So how to distribute the key, this also restrict configuration change (though it is not covered in the paper). Using Key distribute Center (KDC)?
- The ideal situation for all state machine replication protocol is the leader (primary) never change? (meaning no network partition for replicas and the leader does not fail, failure of replicas is transparent to client unless the majority requirement fails)

Miscellaneous

- I feel this paper like Raft a lot in terms of View & Term and Timeout.  And the author of this paper is also the author of Viewstamped Replication. (Maybe I should go back and read it with Paxos and Raft to find the similarity and differences, I think there should be survey for that)
- saw FLP when it explain why synchronous is a must in the system
- TBD

Acknowledgement

Most idea related with bitcoin comes from @czheo

## Supplemental

- TBD
- TBD
- TBD

## Ref

- https://bitcoin.org/bitcoin.pdf
- Viewstamped Replication Revisited http://pmg.csail.mit.edu/papers/vr-revisited.pdf
