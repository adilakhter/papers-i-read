# 8 Typed Arithmetic Expressions

## Exercises

- 8.3.6 subjection reduction property (?), does the opposite, subject expansion - also holds
- 8.3.7 suppose evaluation relation is defined in the big-step style, how should the intuitive property of type safety be formalized
- 8.3.8 suppose our evaluation relation is augmented with rules for reducing nonsensical terms to an explicit wrong state, as in exercise 3.5.16. Now how should type safety be formalized.

## 8.1 Types

- tell, without actually evaluating a term, that its evaluation will definitely *not* get stuck
- Nat and Bool

*conservative*, making only use of static information, not able to conclude the following, which does not stuck when evaluate

````
if (iszero 0) then 0 else false
if true then 0 else false
````

## 8.2 The Typing Relation

- T-TRUE
- T-FALSE
- T-IF
- T-SUCC
- T-PRED
- T_ISZERO

8.2.1 Definition: A term t is typeable (or well typed) if there is some T such that t : T

8.2.2 Lemma[Inversion of the Typing Relation]

- statements are formal assertions about the typing of programs
- typing rules are implications between statements
- derivations are deductions based on typing rules

## 8.3 Safety = Progress + Preservation

- progress: a well typed term is not stuck, it's either a value or can take a step according to evaluation rule
- preservation: if a well typed term take a step of evaluation, then the resulting therm is also well typed
  - it would be same type of we don't have subtyping

8.3.1 Lemma[Canonical Forms]

- if v is a value of type Bool, then v is either true or false
- if v is a value of type Nat, then v is a numeric value

8.3.2 Theorem[Progress]

8.3.3 Theorem[Preservation]
