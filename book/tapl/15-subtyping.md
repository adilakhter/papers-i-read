# Subtyping

- 15.1 Subsumption 181
- 15.2 The Subtype Relation 182
- 15.3 Properties of Subtyping and Typing 188
- 15.4 The Top and Bottom Types 191
- 15.5 Subtyping and Other Features 193
- 15.6 Coercion Semantics for Subtyping 200
- 15.7 Intersection and Union Types 206
- 15.8 Notes 207


> The calculus studied in this chapter is λ<:, the simply typed lambda-calculus with subtyping
(Figure 15-1) and records (15-3); the corresponding OCaml implementation is rcdsub. (Some
of the examples also use numbers; fullsub is needed to check these.)

## 15.1 Subsumption

- S is a subtype of T, written S <: T

t:S  S<:T
----------
    t:T

## 15.2 The Subtype Relation

- `S <: T` S is a subtype of T (or T is a supertype of S)

stipulations

- reflexive, `S <: S`
- transitive, if `S <:U` and `U <:T`, `S<:T`

### Record

- [ ] so is record struct in other language?)

Width subtyping  (S-RcdWidth)

{l_i:T_i^(1.n+k) <: {l_i:T_i^(1,n)}}

- the longer the record, the smaller the type
  - A longer record constitutes a more demanding - i.e. more informative specification, and so describes a smaller set of values

Depth typing (S-RcdDepth)

for each i S_i <: T_i
-----------------------------------
{l_i:S_i^(1,n)} <: {l_i:T_i^{1..n}}

Use both RcdWidth and RcdDepth

- [ ] TODO: it seems there are more than one way to get to the conclusion? so what do we use when check?

It's insensitive to the field order in record (S-RcdPerm)

A combination of three rules can be found in P211

### Function

S-Arrow

T1 <: S1   S2 <: T2
-------------------
S1 -> S2 <: T1 -> T2

~~Cat -> Dog <: WhiteCat -> Animal ???~~

- [ ] the subtype relation is reversed (contravariant) for the argument types in the left-hand premise while it runs in the same direction (covariant) for the result types as for the function types themselves

- [ ] ? is my example correct?

S1 -> S2 is {x: Nat} -> {y:Nat, z:Bool}
T1 -> T2 is {x: Nat, y:Nat} -> {y: Nat}

> An alternative view is that it is safe to allow function of one type S1 -> S2
to be used in a context where another type T1 -> T2 is expected as long as none of the arguments may be passed
to the function in the context will surprise it (T1 <: S1) and none of the results that it returns will surprise the context (S2 <: T2)

- https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-170-laboratory-in-software-engineering-fall-2005/lecture-notes/lec14.pdf

### Top

S <: Top

more in 15.4

## 15.3 Properties of Subtyping and Typing

- preservation and progress theorems

skipped

## 15.4 The Top and Bottom Types

Top

- can be removed without damaging correctness
- like `Object` in Java
- `Top` is a convenient technical device in more sophisticated systems combing subtyping and parametric polymorphism

Bot

- a minimal element that is subtype of every type
- is empty. no closed values of type Bot
- useful for throwing exception or invoking a continuation
  - [ ] TODO: continuation, CPS?
- signal to the typechecker that such an expression can safely be used in a context expecting any type of value

**the presence of Bot significantly complicates the problem of building a typechecker for the system**

so it is omitted ...

- [ ] any real world system has the type bot?

## 15.5 Subtyping and Other Features

### Ascription and Casting

(T) t

- up-casts
  - hide existence of some parts
- down-casts
  - compile time, accepts the type given, but insert a runtime check
  - in runtime, verify
  - the evaluation rule can't discard annotation, but need to validate it at runtime
  - loss progress

Odersky argued it's better to extend the Java type system with real polymorphism (Chapter 23 Universal Types),
but adds too much complexity to an already-large language

real language combine down-casts with type tags - single word tags, more in (Chapter 19 Featherweight Java)

### Variants

- similar to record, except S-VariantdWidth allow new variant to be added
- can drop the ascription

### Lists

- [ ] https://en.wikipedia.org/wiki/Covariance_and_contravariance_(computer_science)
in 15.5 Lists, mentionded covariant (records, variants, as well as function types on their right hand side) and contravariant (arrow, on the left-hand side)

### References

The Ref constructor must be taken to be invariant in order to preserve type safety

### Arrays

- should be invariant as reference, but Java allows, it is now considered a design flaw

### References Again

- source and sink

### Channel

just like the one in Go

- input and output channel

### Base Types

we can have Bool <: Nat ....

date <: datetime might be a better example

## 15.6 Coercion Semantics for Subtyping

- for speed?

## 15.7 Intersection and Union Types

- few implementation

## 15.8 Notes

- record polymorphism is subtle
- OCaml row-variable polymorphism
