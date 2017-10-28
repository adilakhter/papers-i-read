# Exceptions

- 14.1 Raising Exceptions 172
- 14.2 Handling Exceptions 173
- 14.3 Exceptions Carrying Values 175

## 14.1 Raising Exceptions

- a term `error` that when evaluated, completely aborts evaluation of the term in which is appears
- error itself is the result of a program that aborts
- the term `error` form is allowed to have any type
  - subtyping (15.4) assign error the minimal type Bot, can be promoted to any other type as necessary
  - parametric polymorphism (chap 23), give error the polymorphic type X.X, which can be instantiated to any other type

## 14.2 Handling Exceptions

- evaluation rules for error can be thought of as "unwinding the call stack"
- exception handler
  - non-local transfer of control

evaluation rules

try v_1 with t2 -> v_1
try error with t2 -> t2

## 14.3 Exceptions Carrying Values

It is generally useful to send back some extra information about which unusual thing has happened

- replace `error` by `raise t`

evaluation rules

try raise v11 with t2 -> t2 v11

- **typo** T-EXN should be T-Raise

- Texn, Nat, error number
- Texn, string, need to parse string (well, that's Go for you)
- Texn, variant type, no room for user define
- Texn, extensible variant type
- Texn, Java, classes,
  - natural partial order on exception tags
  - distinguish between exceptions and errors
