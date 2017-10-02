# Introduction

- 1.1 Types in Computer Science
- 1.2 What Type Systems Are Good For
- 1.3 Type Systems and Language Design
- 1.4 Capsule History
- 1.5 Related Reading

## 1.1 Types in Computer Science

Frameworks

- Hoare logic
- Algebraic Specification Language
- Modal logics
- Denotational Semantics
  - (there are operational, saw it in previous PL courses, Semantics With Applications, An Appetizer)

Lightweight formal methods

- modal checker
- runtime monitoring
- **type systems**

> A type system is a tractable syntactic method for proving the absense of certain program behaviors by classifying phrases according to the kinds of values they compute

static: compile-time analyses
dynamic typed: should be called dynamically checked

**conservativity** vs **expressiveness**

- only guarantee well-typed program are free from *certain* kinds of misbehavior
- run-time type errors: bad behaviors that can be eliminated by the type system in a given language
- safety (soundness) of each type system must be judged with respect to its own set of run-time errors

Type checkers

- built into compilers or linkers
- explicit type annotations
- can become a proof checker

## 1.2 What Type Systems Are Good For

Detecting Errors

- Dimension types **numerical calculations in scientific applications, refined type systems supporting dimension analysis** [Kennedy, 1994](https://link.springer.com/chapter/10.1007/3-540-57880-3_23)

Abstraction

Documentation

Language Safety

> The term "safe language" is, unfortunately, even mode contentious than "type system"

- a safe language is one that protects its own abstractions
- Language safety is not the same thing as static type safety
  - run-time checks that trap nonsensical operations at the moment to be executed

|  | Statically Checked     | Dynamically checked |
| :------------- | :------------- | :--- |
| Safe       | ML, Haskell, Java, etc.  | Lisp, Scheme, Perl, Postscript, etc. |
| Unsafe       | C, C++, etc.      | - |

- static typing alone can not achieve run-time safety, i.e. array-bounds checking is needed
- Unsafe is offered in many safe languages
- a safe language prevents untrapped error at runtime

Efficiency

- Fortan need to distinguish integer and float

Further Applications

- JNI
- automated theorem proving
- XML database? ....

## 1.3 Type Systems and Language Design

- language design should go hand-in-hand with type system design
- a well-designed statically typed language will never require huge amounts of type information to be explicitly and tediously maintained by the programmer

## 1.4 Capsule History

## 1.5 Related Reading
