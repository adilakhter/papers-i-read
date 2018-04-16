# Chord: A Scalable Peer-to-peer Lookup Service for Internet Applications

For CMPS232 Fall16

- [Chord: A Scalable Peer-to-peer Lookup Service for Internet Applications](https://pdos.csail.mit.edu/papers/chord:sigcomm01/chord_sigcomm.pdf)

Related

- [Using Lightweight Modeling To Understand Chord](../chord-light)

## Short summary

see [summary.md](summary.md)

Strong points

- Chord is simple and efficient
- Nice graph and clean code
- Have real experiments

Weak points

- see the next paper on reading list.

Questions

- Is it possible to search by keywords that may exist in a key. Is there any hash mechanism that allow this kind of lookup.
Like I have `Book:CS`, `Book:MSE`, `Food:Cake` and I want to find all the key with keyword `Book`. The search mentioned in this paper seems
to be looping through all the keys and find if keywords exists in their value (document)
- How BitTorrent work? they have DHT as well. And what about BitCoin?
- How to think of counterexamples after you spent quite a while to understand what the author is talking about? (Play some Overwatch and refresh your head?)

## Supplemental

- TBD
- TBD
- TBD

## Ref
