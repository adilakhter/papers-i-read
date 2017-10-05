# The Untyped Lambda-Calculus

5.1 Baiscs 52
5.2 Programming in the Lambda-Calculus 58
5.3 Formalities 68
5.4 Notes 73

- untyped or pure lambda-calculus
- [ ] the underlying computational substrate
- core + derived forms
- all computation is reduced to the basic operations of function definition and application
- a simple programming language in which computations can be described and as a mathematical object about which rigorous statements can be proved
- extensions eventually lead to ML, Haskell, Scheme

## 5.1 Basics

- Procedural (or functional) abstraction is a key feature of essentially all programming languages
- In the lambda-calculus **everything** is a function
  - the arguments accepted by functions are themselves functions
  - the result returned by a function is another function

````
t ::=                     terms:
    x                   variable
    lambdax. t       abstraction
    t t              application
````

### Abstract and Concrete Syntax

Adopted conventions in this book

- application associates to the left, s t u means (s t) u
- the bodies of abstractions are taken to extend as far the right as possible
  - i.e. lx. ly. x y x is lx. (ly. ( (x y) x))

### Variables and Metavariables

- metavariable `t`, `s`, `u` stands for an arbitrary term
- `x`, `y`, `z` stands for an arbitrary variable
- the might be mixed, but you can make it clear from context

### Scope

- an occurrence of variable x is said to be bound when it occurs in the body `t` of an abstraction `lx.t`
- `x` is *free* if it shows in a position that is not bound by an enclosing abstraction on `x`
  - i.e. `x` in `x y` and `ly. x y`
- a term with no free variables is said to be *closed*, also called *combinators*
  - *identity* function `id = lx.x`

### Operational Semantics

- in its pure form, no built-in constants or primitive operators
- "compute" application of functions to arguments (which themselves are functions)

````
(lx. t12) t2 -> [x |-> t2]t12
````

- `[x |-> t2]t12` replacing all free occurrences of x in t12 by t2
  - `(lx. x) y` evaluates to `y`
  - `(lx. x (lx.x)) (u r)` evaluates to `u r (lx.x)`
    - x is free but lx.x is not free, so x is replaced by u r and the x in lx.x remains same
- *redex* (reducible expression) `(lx .t12) t2`
- *beta-reduction* the operation of rewriting

Evaluation strategy

- full beta-reduction, any redex may be reduced at any time
- normal order, leftmost, outermost is always reduced first
- call by name, no reductions inside abstractions
  - Haskell, call by need, reduction relation on abstract syntax graphs, rather than syntax tree
  - **non-strict (lazy)**
- call by value, most language
  - **strict**, always evaluated, no matter used or not
  - only outermost redexes are reduced and where a redex is reduced only when its right-hand side has already been reduced to a value

  **call by value** is used in the book

- it makes little different when it comes to type systems
- common
- easiest for Exception (Chap 14)and References

## 5.2 Programming in the Lambda-Calculus

Just warm up

### Multiple Arguments

- using *higher-order* functions that yield functions as result
- this transformation of multi-argument functions into higher-order functions is called *currying* in honor of Haskell Curry, a contemporary of Church

### Church Booleans

````
tru = lt. lf. t;
fls = lt. lf. f;
test = lo. lm. ln. o m n;
````

- [ ] TODO: the example graph

## Pairs

- encode pairs of values as terms

````
pair = lf. ls. lb. b f s;
fst = lp. p tru;
snd = lp. p fls;
````

## Church Numerals

- each number n is represented by a combinator c_n that takes two arguments, s and z (successor and zero) and applies s, n times, to z

## Enriching the Calculus

- `\lambdaNB`
- two types of boolean and number, Church and primitive

````
realbool = lb. b true false;
churchbool - lb. if b then tru else fls;
````

## Recursion

Terms with no normal form are said to *diverge*

````
omega = (lx. x x) (lx. x x)
````

omega has a useful generalization called *fixed-point combinator*, is is often called the *call-by-value Y-combinator*

````
fix = lf. (lx. f (ly. x x y)) (lx. f (ly. x x y));
````

- first define `g = lf. <body containing f>`
- then `h = fix g`
- [ ] TODO: .....

## Representation

- there is no observable difference between the real numbers and their Church-numeral representation
