# Submit

Before write the summary and questions, they most interesting thing I found out is the two papers have opposite attitude towards how engineers should work.
One think great tools can let engineers make products without knowing the detail.
Another think engineers should know what they are doing and use specific methods for
specific problem.
The trend in theses days agree with the first one, there are so many powerful language
frameworks, Sass. Just read the manual, write some glue code and debug/let if fail has become an endless loop
for many novice developers (at least this is the case in China, don't know much about US).
The gap between researcher and novice developers is becoming larger, one does not make it to
university does not mean he is not creative enough to come up with new ideas that can increase
the diversity in academy. It's true that the chance is low, but the first attitude is making this
chance even lower.
Some software engineers works like assemblers.
The reason why we need assemblers is because the machine is not clever enough.  
If the tools are powerful enough, then a lot of software engineers will lost their job.

The aim of RPC is to let engineers work on large scale systems with little knowledge to distributed systems. Just like most libraries, frameworks, Sass do in these days. Engineers don't know much about the detail, they assemble
everything together following the manual and then debug. If machine can read manual and manager's request like human do, do we still need most software engineers?


This paper (A Note on Distributed Computing) is against the first paper (PRC rule the world). RPC and related organizations are doomed to fail when their design flaws can no longer be covered by small scale.

The author then introduced the typical design process of RPC systems.
First they write application like local ones without care about object location and communication. (Do people from Sun all like Object so much, the word object is everywhere).
Then they tune performance (without knowing if the system will work).
At last they test and make patches. The author also listed their principles which are all proved not hold in following sections.

From the third section, the author stop pretending he is a fan of RPC.
He pointed out although people focused a lot on Protocols, this is not the key problem, partial failure and concurrency are. RPC guys are not spending their effort on the core problem.

The point of RPC is to make local and remote same to engineers. But the author pointed out this is a difference that can not be paper over.
Engineers can't leave all the though stuff to vendor, he showed this with
a funny story. (should draw a picture)
Then he use an industry product NFS, which is also the product of his own company to show he is right.

At last he provided the solution that engineers should accept the difference between local and remote and know what they are doing when they write the code. (The middle ground part is really not necessary IMO, he should just end in section 7)
