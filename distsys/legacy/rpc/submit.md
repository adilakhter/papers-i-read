# Submit

This paper (Implementing Procedure Calls) is quite boring IMO.
It's more like a report paper, details a covered but since it is
published long time ago, readers won't have interest in these old
techs. It addresses the importance and requirement of RPC.
Programing distributed applications are difficult, RPC will make
programmers feel remote calls has no difference with local calls.
The structure of the system is user, user-stub, RPCRuntime, server-stub,
server. Thanks to @czhen, this is quite similar to the client server (C/S)
architecture, which we are more familiar with. 

Then the author continue to focus on the implementation detail, and there are
too many platform and language specific terms and too little about why they are doing this. Protocol is also described in detail, performance tuning is also covered. A funny thing is, they said security is an important thing that other distributed systems has paid little attention to and their system can work in public network. However, only one short paragraph is used.

At last, the author discuss current status and future development.
