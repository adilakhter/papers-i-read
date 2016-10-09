# Time, Clocks, and the Ordering of Events in a Distributed System

For CMPS232 Fall16

## TODO

- [x] format and cleanup, add TBD etc.
- [ ] write the review and questions for the assignment in MD
- [ ] submit on easychair.
- [ ] watch the video from udacity/youtube and finish the summary.

## Usage

- Ayi run build
- Ayi run bib
- Ayi run build

strong

- partial ordering is unique
- total ordering can be extended from partial ordering
- physical clocks can be synchronized using the algorithm proposed.

weak

- implementation details for messaging is ignored (otherwise, I won't understand)
- failure is not considered (covered in other paper)
- may not apply to today's multi processes system (I am just guessing)
- the proof in the appendix is too hard (for me)

raised questions

- How to visualize the space-time diagram to 3D, is it possible to extend it to higher dimension.
- For the mutual exclusion example, if I want to use a central lock service, what must be implemented in the message(protocol) to avoid ordering problem.
- In network protocols like TCP, state machine can also be used, what's the similarity and difference between the one mentioned in total ordering.
- If we need to choose a protocol for send message, should we use reliable transport like TCP? If use UDP, what else should we do?
- How to extend the algorithm to multiple resources, is having multiple queues a practicable approach?
- The algorithm assumes every process can talk freely, what if processes have levels and each level can only talk to its neighbors. ie: Lv2 can talk to Lv1 and
  Lv3 but not Lv4. Does this algorithm still apply? Which structure is more efficient and/or stable, the plain one or the multiple levels one.
- Can we still use the algorithm if processes join and quit dynamically?
- Google is using atomic clock for Spanner, what's its relation to this paper?
- What are other clocks used in distributed system?
- When did Lamport invent Latex? What's the difference between Tex and LaTex?
- Does EasyChiar support **markdown**?

## Ref

- http://books.cs.luc.edu/distributedsystems/clocks.html
- [papers we love](https://www.youtube.com/watch?v=CWF3QnfihL4&t=1953s) [slide](https://speakerdeck.com/pborrill/time-clocks-and-the-reordering-of-events-pwl-san-francisco-14-jul-2016)
- Udacity https://www.youtube.com/watch?v=z2oY8LWHYq8
