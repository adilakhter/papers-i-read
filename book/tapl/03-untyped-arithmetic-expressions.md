# Untyped Arithmetic Expressions

- 3.1 Introduction
- 3.2 Syntax
- 3.3 Induction on Terms
- 3.4 Semantic Styles
- 3.5 Evaluation
- 3.6 Notes

A simple language for core concepts, then lambda-calculus,

## 3.1 Introduction

The language contains

- `true`, `false`
- conditional expression
- numeric constant 0
- arithmetic operators `succ`, `pred`
- `iszero`

conventions in grammar are close to standard [BNF](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form)

````
t ::=
  true
  false
  if t then t else t
  0
  succ t
  pred t
  iszero t
````  

- `t` is term
- the right side rules are `metavariable`
- use `term` and `expression` interchangeably for now

examples

````
if false then 0 else 1;
> 1
iszero (pred (succ 0));
> true
````

result will always be either boolean constants or numbers

## 3.2 Syntax

3.2.1 Definition[Terms, Inductively]: The set of terms is the smallest set T such that

````
{true, false, 0} belong T;
if t1 belong T then {succ t1, pred t1, iszero t1} belong T;
if t1 belong T, t2 belong T, and t3 belong T, then if t1 then t2 else t3 belong T;
````

3.2.2 Definition[Terms, By Inference Rules]: The set of terms is defined by the following rules:

````
true belong T    false belong T     0 belong T

t1 belong T           t1 belong T         t1 belong T
----------------   ----------------   ----------------
succ t1 belong T    pred t1 belong T   iszero t1 belong T

t1 belong T  t1 belong T  t1 belong T
-------------------------------------
    if t1 then t2 else t3 belong T
````

- rules with no premises (前提) are often called *axioms* (公理)
- inference rules are actually rule schemas

3.2.3 Definition[Terms, Concretely]: For each natural

````
S_0 = empty set
S_i+1 =    {true, false, 0}
        \/ {succ t1, pred t1, iszero t1 | t1 belong S_i}
        \/ {if t1 then t2 else t3 | t1, t2, t3 belong S_i}
````

3.2.6 Proposition T = S

skip P28

## 3.3 Induction on Terms

- we can give *inductive definitions of functions over the set of terms*
- we can give *inductive proofs of properties of terms*

3.3.1 Definition

TODO

## 3.4 Semantics
