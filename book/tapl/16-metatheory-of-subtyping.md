# Metatheory of Subtyping

- 16.1 Algorithmic Subtyping 210
- 16.2 Algorithmic Typing 213
- 16.3 Joins and Meets 218
- 16.4 Algorithmic Typing and the Bottom Type 220

T-SUB is not syntax directed

i.e. for other rules you can have

match t {
  case abs x body { TODO: how to check abstraction ?}
  case abs param { TODO: how to check parameter type is same as the applied parameter}
  case if x1 then x2 else x3 { check(x1) == bool, check(x2) == check(x3)}
}

but with T-SUB, every term match this rule 'T-SUB' can be applied to *any* kind of term

S-TRANS has same problem as T-SUB, plus, need to guess U out of nowhere

- algorithmic subtyping
- algorithmic typing

And we show the declarative rules are equivalent  

## 16.1 Algorithmic Subtyping

- drop S-Trans and S-Refl
- S-RCD is added because we drop S-Trans and S-Refl

- [ ] TODO: lemma 16.1.2
- S <: S can be derived for every type S without using S-REFL
- if S <: T is derivable, then it can be derived without using S-Trans

pseudocode for subtype

- the subtype function is a decision procedure for the declarative subtype relation

## 16.2 Algorithmic Typing

T-SUB is used for application only, so just update the rule T-APP

## 16.3 Joins and Meets

if true then {x=true, y=false} else {x=false, z=true}

The minimal type for the whole condition is the least type that is supertype of both branch

- [ ] TODO: then what is meets for?

## 16.4 Algorithmic Typing and the Bottom Type

skipped
