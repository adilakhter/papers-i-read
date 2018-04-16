# Implementing Fault-Tolerant Services Using the State Machine Approach: A Tutorial

Type: survey

For CMPS232 Fall16

- [Implementing Fault-Tolerant Services Using the State Machine Approach: A Tutorial](https://www.cs.cornell.edu/fbs/publications/SMSurvey.pdf)

Related

- [Paxos](../paxos) TODO: missing
- [Raft](../raft)


## Short summary

see [summary.md](summary.md)

Strong points

- Nice table of contents in introduction, which seems extinct now.
- Semantic Characterization of a State Machine. (Semantic is important, as mentioned in FLP)
- Those pseudocode for state machines really help understanding

Weak points

- Maybe it's better to mention Byzantine and fail-stop are the two polar of failure models, thus they choose to cover those two.
- The concept of replicate client and usage of output device is quite confusing (to me) For my
understanding it's client make a request, state machine execute the command with the help of some protocol and return the result to the client. The author's idea feels like I(client) press a switch and all the lights in my room is on (output).
- The reconfiguration part is more like what is required for self-healing, which is quite different from the concept of elastic scale(adding node under workload) we have today.
Also forever running Fault-Tolerant state machine(s) is too ideal, but he is the first author that comes up with health insurance for processors.

Questions

- why in footnote the author says `The term 'state machine' is a poor one, but, nevertheless, is the one used in the literature` Does state machine has formal name in math?
- 'Requests are processed by a state machine one at a time, in an order that is consistent
with potential causality.' so if multiple requests arrive, all the issuers are blocked until the one arrived first is finished?
- The author mentioned sensor when talking about replicate clients, and I think sensors used in
internet of thing is qualified as distributed system. It's larger and have higher rate of failure compared with distributed systems in data centers. Also P2P network like bitorrent and bitcoin are also distributed. Are we going to talk about those kind of distributed systems?
They are not so academic but very interesting.


Miscellaneous

- The author have a lot of similar style articles, ie: `Concepts and Notations for Concurrent Programming` http://www.cs.nyu.edu/~lerner/spring12/Read02-LangSurvey.pdf (Why I have a feeling
  that a lot of researchers in computer science are actually doing math and logic)
- Bitorrent can be used for DDOS attack. BotTorrent: Misusing BitTorrent to Launch DDoS Attacks
https://www.usenix.org/legacy/event/sruti07/tech/full_papers/eldefrawy/eldefrawy.pdf

## Supplemental

- TBD
- TBD
- TBD

## Ref
