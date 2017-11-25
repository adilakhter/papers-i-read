# 23 Universal Types

- 23.1 Motivation 339
- 23.2 Varieties of Polymorphism 340
- 23.3 System F 341
- 23.4 Examples 344
- 23.5 Basic Properties 353
- 23.6 Erasure, Typability, and Type Reconstruction 354
- 23.7 Erasure and Evaluation Order 357
- 23.8 Fragments of System F 358
- 23.9 Parametricity 359
- 23.10 Impredicativity 360

## 23.1 Motivation

- reuse code that has different type, but exact same logic, i.e. a list, tree etc.

## 23.2 Varieties of Polymorphism

- type systems that allow a single piece of code to be used with multiple types are collectively known as polymorhpic systems
  - poly = many
  - morph = form

There are several forms

- parametric polymorphism
  - uniform, all the instances behave the same
  - impredicative or firt-class, used in module systems in ML (OCaml?)
- ad-hoc polymorphism
  - exhibit difference behaviors when "viewed" at different types
  - overloading (static & dynamic)
