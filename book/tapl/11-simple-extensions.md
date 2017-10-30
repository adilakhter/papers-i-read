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

- `let x=t1 in t2` mean evaluate the expression t1 and bind the name x to the resulting value while evaluating t2
- give names to some of its subexpressions
  - [ ] TODO: isn't this variable?... no, it isn't, i.e. [ocaml local "variables"](http://ocaml.org/learn/tutorials/structure_of_ocaml_programs.html#Local-quot-variables-quot-really-local-expressions)
- call by value evaluation order like ML  
- different with other derived form, we can derive its evaluation behavior by desugaring it, but its typing behavior must be built into the internal language

````
utop # let f a b =
   let x = a +. b in
   x +. x ** 2.
;;
val f : float -> float -> float = <fun>  
````

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

## 11.9 Sums

- heterogeneous collections of values
- T1 + T2, T1 is tagged with `inl` and T2 is tagged with `inr`
- `case`
- breaks the old Uniqueness of Types theorem
  - guess, type reconstruction (chap 22)
  - subtyping (chap 15)
  - explicit annotation

## 11.10 Variants

- binary sums generalized to labeled variants
- `<l1:T1, l2:T2>`

Options

- `OptionalNat = <none:Unit, some:Nat>;`
- null value in C++ and Java is actually an option in disguise

Enumerations

- a variant type in which the field type associated with each label is Unit

````
Weekday = <monday:Unit, tuesday:Unit, wednesday: Unit>;
````

Single-Field Variants

````
V = <l:T>;
````

usual operations on T cannot be applied to elements of V without first unpacking them: a V cannot be accidentally mistaken for a T

i.e. dollar and euros types

Variants vs. Datatypes

- [ ] more about OCamel details? type and datatype?

Variants as Disjoint Unions

- include all elements from T1 and T2
- a given element is from T1 or T2

Type Dynamic

- even in statically typed languages, there is often the need to deal with data whose type cannot be determined at compile time
- data from external sources, database, network, file etc.
- Dynamic

## 11.11 General Recursion

- fix is a *generator*
- fix can't be defined in STLC
  - no expression that can lead to non-terminating computations can be typed using only simple types
- add fix as a new primitive
- can also be used to define a record of mutually recursive functions as the fixed point of a function on records

## 11.12 Lists

- base type, Bool, Unit
- type constructors, -> and X
- List T describes finite-length lists whose elements are drawn from T
