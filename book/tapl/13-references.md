# 13 References

Side effects like assign value to variable, read/write file are called
*computational effects*, including reference, exception etc.

- 13.1 Introduction

## 13.1 Introduction

- naming biding and assign are kept separate in ML and its relatives
  - `x`'s value is number 5
  - `y`'s value is a reference (pointer) to a mutable cell whose current content is 5
  - use `!y` to obtain its current contents
  - in Java, C, the operation of dereferencing a variable to obtain its current contents is implicit

Basics

- allocation
  - `r = ref 5;`
  - `r : Ref Nat`
- dereferencing
  - `!r;`
  - `5 : Nat`
- assignment
  - `r := 7;`
  - `unit : Unit`

Side Effect and Sequencing

- `(r:=succ(!r); !r);`
- `8: Nat`
- `(r:=succ(!r); r:=succ(!r); r:=succ(!r); !r);`
- `13: Nat`
