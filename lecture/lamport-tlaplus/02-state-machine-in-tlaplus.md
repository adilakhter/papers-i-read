# 2 State machines in TLA+

We need a language for describing state machines -> use math

> The hard part of learning to write TLA+ specs is learning to think abstractly about the system

````c
int i;

int main() {
  i = someNumber();
  i = i + 1;
}
````

`pc` means current value, `pc'` means next value

````
IF pc = "start"
  THEN (i' \in 0..100) /\ (pc' = "middle")
  ELSE IF pc = "middle"
    THEN (i' = i+1) /\ (pc' = "done")
    ELSE FALSE
````

Simplify

````
\/  /\ pc = "start"
    /\ i' \in 0..1000
    /\ pc' = "middle"
\/  /\ pc = "middle"
    /\ i' = i + 1
    /\ pc' = "done"
````

`\/` and `/\` are commutative

Decompose

- use names
