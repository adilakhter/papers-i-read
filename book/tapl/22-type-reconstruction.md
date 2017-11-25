# 22 Type Reconstruction

- get constraint based on syntax
- solve the constraint using unification to get the sigma (context?)
  - if there is a solution, well typed
  - no, not well typed

## 22.5 Principle Types

- can provide more accurate error message
- [ ] interleave generation and solving

## 22.6 Implicit Type Annotations

- one way is to add new fresh type 
- [ ] another way is regard a bare abstraction as being annotated with an invisble type variable, then making copies will yield several expression sharing the same argument type

## 22.7 Let-Polymorphism

- change T-let, perform a step of evaluation before calculating types
- in practice, a more longer rule ... and is changed to match evaluation rule

## 22.8 Notes

- principle type != principle typing

