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

3.3.1 Definition `Constants`

````
Consts(if t1 then t2 else t3) = Consts(t1) \/ Consts(t2) \/ Consts(t3)
````

3.3.2 Definition `size` (# nodes) `depth`

````
size(if t1 then t2 else t3) = size(t1) + size(t2) + size(t3) + 1
depth(if t1 then t2 else t3) = max(depth(t1), depth(t2). depth(t3)) + 1
````

3.3.3 LEMMA: The number of distinct constants in a term t is no greater than the size of t

- [ ] TODO: detail induction steps

## 3.4 Semantics

Operational semantics (used exclusively in this book)

- abstract machine
- state: term
- behavior: transition function
- [ ] big step and small step?

Denotational semantics

- semantic domains
- interpretation function mapping terms into domains
- domain theory

Axiomatic semantics

- take the laws themselves as the definition of the language
- invariant
  - d..d.. dafny

## 3.5 Evaluation

- evaluation relation `t -> t'`, t evaluates to t' in one step

> what these rules do not say is just as important as what they do say

3.5.1 Definition: An *instance* of an inference rule is obtained by consistently replacing each metavariable by the same term in the rule's conclusion and all its premises (if any)

3.5.2

3.5.3 Definition: **one step evaluation** `->` is smallest binary relation on terms, when the pair (t, t') is in the evaluation relation, we say the evaluation statement (or judgment) `t -> t'` is derivable

derivation tree leads to induction on derivations

3.5.4 Theorem[Determinacy of one-step evaluation]: If t -> t' and t -> t'', then t' = t''

3.5.6 Definition: A term t is in *normal form* if no evaluation rule applies to it. i.e. `true` `false`

3.5.7 Theorem: Every value is in normal form

3.5.8 Theorem: If t is in normal form, then t is a value

3.5.9 Definition: The **multi step evaluation** `->*` is the reflexive, transitive closure of one step evaluation

3.5.11 Theorem[Uniqueness of normal forms]: If `t ->* u` and `t ->* u'`, where `u` and `u'` are both normal forms, then `u = u'`

3.5.12 Theorem[Termination of evaluation]: For every term there is some normal form `t'` such that `t ->* t'`

Figure 3.2 Arithmetic expressions

3.5.15 Definition: A closed term is *stuck* if it is in normal form but not a value

> Stuckness gives us a simple notion of run-time error for out simple machine

3.5.17 small & big step

## 3.6 Notes

just reference to books
