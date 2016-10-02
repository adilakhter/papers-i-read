# Submit

Dynamo is Amazon's HA K-V. It scarifies certain consistency to achieve HA, also
it usage scenario is limited due to simple K-V and requirement for client application.
But it shows a combination of technology and tradeoffs can take a small bite on the
big distributed systems cake which is mostly eaten by people like Lamport and Waldo.
There are a lot things can be achieved given so many theoretical proof showing impossibilities.
After all, the real world is more tolerable than the real world in theory.

This paper covers a lot implementation details like the RPC one, but given the halo of
giant companies, readers will less likely to challenge their ideas. (otherwise they will
clean your shopping cart on Amazon) However this paper is not very academic, the introduction
is quite verbose, and some key concepts are not covered well. However, there are too many
technologies included and they need to `protect Amazon's business interests`, it's impossible
for them to write everything in detail.

This paper have a clear structure and took a weekend to read. (Though I have spent most of my time watching animation...)

A more detailed summary can be found here https://github.com/at15/papers-i-read/blob/master/distributed_systems/dynamo/summary.md
