# Circonus

[Monitoring Architecture with Theo Schlossnagle ](https://softwareengineeringdaily.com/2016/10/11/monitoring-architecture-with-theo-schlossnagle/)


> Theo Schlossnagle is the CEO of Circonus, where he has been working on architecting the company’s monitoring software for six years. In this episode, we talk about how to build a monitoring system and the requirements for the underlying time-series database, as well as what monitoring even is.

## Time series database

they built their own tsdb. It seems it is not open sourced. https://github.com/circonus-labs/reconnoiter is the closest I can find.

- no need for expensive consensus (no Paxos, no Raft)
- write once
- HA (they have 6 replica in each DC, and have 2 remote DC) (The guy from prometheus is wrong about no need for HA, actually I think the host created some misunderstanding when he reply the message from prometheus guy)

## Push or Pull

- the question itself is nonsense, once you have the TCP connection, you can both pull or push. Both pull and push can scale. (e .. I agree with the idea, but not all agent use long connection)

e... that's all I remembered ...
