# 20 Recursive Types

- consider list of number (generic list is in Chapter 29 Type Operators and Kinding)

NatList = <nil: Unit, cons: {Nat, NatList}>

- explicit recursion operator u

NatList = uX. <nil:Unit, cons: {Nat, X}>;

- equi-recursive (ligher)
- iso-recursive

## 20.1 Examples

### List

- [ ] TODO: I remeber we can remove the ascription after we have Subtyping

nil = <nil=unit> as NatList;
cons = lambda n:Nat. lambda l:NatList. <cons={n, l}> as NatList;
isnil = lambda l:NatList. case l of
                              <nil=u> -> true
                            | <cons=p> -> false;
hd = lambda l:NatList. case l of <nil=u> -> 0 | <cons=p> -> p.1;
tl = lambda l:NatList. case l of <nil=u> -> l | <cons=p> -> p.2;

### Hungry Functions

- accept any number of numeric arguments and always return a new function that is hungry for more

Hungry = uA. Nat -> A;

f = fix (lambda f: Nat -> Hungry. lambda n:Nat. f);

(... isn't this function just ignore argument and return itself)

### Streams

Stream = uA. Unit -> {Nat, A};
Process = uA. Nat -> {Nat, A};

### Objects

- *purely functional object* return a new object when object method is called

### Recursive Values from Recursive Types

- a well-typed implementation of the fixed-point combinator
- [ ] TODO: breaks strong normalization property
  - https://people.mpi-sws.org/~dg/teaching/pt2012/sn.pdf

### Untyped Lambda-Calculus, Redux

## 20.2 Formalities

What's the relationship between ux. T and its one step unfolding

*equi-recursive*

- take two expressions as definitionally equal, stand for the same infinite tree
- implementation requires some work, see Chap 21
- complex when it comes to advanced features like bounded quantification and type operators

*iso-recursive*

- **fold and unfold**
- in practice, coalescing them with other annotations
  - ML, datatype, implicitly introduces a recursive type
  - Java, each class definition implicitly introduces a recursive type, invoke method involves an implicit unfold

## 20.3 Subtyping

- [ ] TODO: got a visual ...
