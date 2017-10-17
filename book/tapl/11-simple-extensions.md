# 11 Simple Extensions

- 11.1 Base Types 117
- 11.2 The Unit Type 118
- 11.3 Derived Forms: Sequencing and Wildcards 119
- 11.4 Ascription 121
- 11.5 Let Bindings 124
- 11.6 Pairs 126
- 11.7 Tuples 128
- 11.8 Records 129
- 11.9 Sums 132
- 11.10 Variants 136
- 11.11 General Recursion 142
- 11.12 Lists 146

## 11.1 Base Types

- comes with some set `A` of uninterpreted or unknown base types
- atomic types, they have no internal structure as fas as the type system is concerned
  - i.e. (my example) String might be a fixed size byte array, but it's type just string type, it could also be a reference to a string table

## 11.2 The Unit Type

- used in the ML family
- main use is side effect
- `unit` is the only possible result of evaluating an expression of type Unit
- similar to `void` in C and Java

## 11.3 Derived Forms: Sequencing and Wildcards

- `t1;t2`, evaluate t1, though away its result and go on to t2
  - used in language with side effects

11.3.1 Theorem[Sequencing is a derived form]

- syntactic sugar, derived forms
- desuggaring, replacing a derived form with its lower-level definition

- Wildcards, `_`, i.e. `lambda _:S.t` instead of `lambda x:S.t`

## 11.4 Ascription

- [ ] annotation in java?
- documentation
- printing, abbreviation
- abstraction
  - subtyping, casting

## 11.5 Let Bindings

- give names to some of its subexpressions
  - [ ] TODO: isn't this variable?...
- call by value evaluation order like ML  
- different with other derived form, we can derive its evaluation behavior by desugaring it, but its typing behavior must be built into the internal language

## 11.6 Pairs

- `{t1, t2}`
- new type, product `T1 x T2`

## 11.7 Tuples

- generalized pair
- if all the fields before j has been reduced to value, we can have tj -> tj'

## 11.8 Records

- [ ] TODO: feels like hashmap ...
- order or not order has import impact on performance (15.6)
- patterns and pattern matching
