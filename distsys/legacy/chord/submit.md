# Chord

We all know Chord since we have read the Dynamo paper. Chord is not very complex,
compared with the following reading. (Paxos is simple, Lamport is right ....)
It solves a major problem in distributed systems, location. How to find the value
when we have the key. It's simple when we do it on single machine, have everything
in RAM or Disk and just look for it. Some structure like B+ tree might be needed to
speed up the process. But things are a lot different when there are so many nodes,
in fact in the experiments for Chord, their node numbers are so big that no companies
could have due to commercial and physical limitations. (Though these nodes does not
mean a one to one match to physical machine)

Chord compared itself with many famous P2P and Location technologies like DNS and many
academic products. I was wondering why things like BitTorrent, BitCoin are not discussed?
And come up with the conclusion that Chord is simple and scalable and reliable. (Too good to
believe it is true)

Section 4 and 5 have detailed explanation about how Chord works, and if you saw the next
paper, you will found out there are many version of Chord, some are more practical some are
more correct. So Chord is not perfect as it seems. But if accept all the assumptions and forgot
some details, you will like the author until you see the next paper.

Unlike some paper which say they have proof in theory and hard to find real example, Chord gave a
lot of application examples and have experiment on prototype. (They should deploy a node in China, and
they will feel the power of wall that makes all the lookup algo fail)

I am quite curious to know if there are some open source distributed applications using Chord after reading this paper. 
