# Using Lightweight Modeling To Understand Chord

This paper is an advertisement for the Lightweight modeling language Alloy by pointing
out some defects in the distributed lookup protocol Chord. There are many version of
Chord, none of them are correct in theory using their pseudocode. There are many implementations
for Chord, and those implementations didn't say or even may not know which Chord they are
implementing. Even if they want to, Chord does not have semantic versioning like 1.0, 1.1, and
no specification to avoid misinterpretation. Thanks to the endless effort of engineers, a working
implementation is a correct implementation (fail immediately and fail eventually is close in theory, but
very different in production, current implementation will be replaced by new theory before it fails).

Just like some advertisements on youtube, you see hot girls and handsome boys first and their product at last (sometimes
their brand just flash at you don't know what the ads is for). This paper spend a lot of time talking about
defects in Chord. Without this paper, I don't think I can find those problems in Chord, it took me a while to understand Chord,
so it's hard to jump out its box and come up with a counterexamples. However I doubt if all the defects are the result of the
lightweight modeling language Alloy. But the author did have very detailed examples, covering 7 invariants.
And the Chord he mentioned is different from what we know from the paper we are asked to read about Chord.
Words like flush never shows up in that paper.

The author comes to Alloy at last, its syntax is not very strange, at least I could figure out which part is comment.
But it is using brutal force to test the model, enumerate all the cases to see if they hold. At least it's better than
do it manually, not to mention it has GUI, everyone loves colorful graphs, since they can fool people who don't understand
what those axis mean.

In general I have more desire to implement Chord rather than try Alloy after reading this paper, I may not be their target client I guess. 
