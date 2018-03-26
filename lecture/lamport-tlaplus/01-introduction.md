# 1 Introduction to TLA+

- Lamport: I am Lamport
- AWS is using TLA+, How Amazon Web Services Uses Formal Methods
  - 'learn an use in 2-3 weeks'
- Why spec instead of code?
  - Formal Development of a Network-Centric RTOS
    - 10x code reduction by having a 'cleaner architecture'

The basic abstraction underlying TLA+

- an execution of a system is represented as a sequence of discrete steps
- step: state change
- execution: a sequence of states

State machines

- a behavior is a sequence of states
- a state is an assignment of values to variables

1. all possible initial states
2. what next states can follow any given state
  - it halts if there is no possible next state

A state machine is described by:

- what the variables are
- possible initial values of variables
- a relation between their values in the current state and their possible values in the next state

A Tiny Example

````c
int i;

int main() {
  i = someNumber();
  i = i + 1;
}
````

need to consider both `i` and `pc` (which line is being executed)

State machine is simpler than program because implementation detail like control, heap, call stack etc. are abstracted away.
