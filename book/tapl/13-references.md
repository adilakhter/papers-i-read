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

Reference and Aliasing

- `s = r`
- `s := 82`
- `!r`
- `82`

Shared State 

- but putting incc and decr into a record, we have an object (more in Chap 18)

Reference to Compound Types

- use reference to function to define array (not efficient)
- mutable list, trees (recursive types) (Chap 20)

Garbage Collection

- it is extremely difficult to have type safety in the presence of an explicit deallocation operation

## 13.2 Typing

## 13.3 Evaluation

- take references to be some set of store locations
- take store to be partial function from location l to values

evalutation rule now takes term and store, not just term anymore

> we simply allow the store to keep growing without bound as evaluation proceeds, This does not affect the correctness of the results of evaluation

## 13.4 Store Typings

It provides two solutions

- lookup location and calculate type of the content
  - typechecking is rather inefficient
  - can't deal with store contain cycle, i.e. double linked list
- we know the type of the value when we store it, no need to evaluate it

## 13.5 Safety

skipped



