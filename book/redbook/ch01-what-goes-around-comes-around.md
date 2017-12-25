# What Goes Around Comes Around

https://github.com/at15/papers-i-read/issues/92

## Abstract

summary of 35 years of data model proposals, groups into 9 different eras.

> he who does not understand history is condemned to repeat it

XML era (current) is similar to CODASYL from 1970's which failed due to complexity

## Introduction

- Hierarchical (IMS): 1960, 1970
- Network (CODASYL): 1970
- Relational: 1970, 1980
- Entity-Relationship: 1970
- Extended Relational: 1980
- Semantic: 1970, 1980
- Object-oriented: 1980, 1990
- Object-relational: 1980, 1990
- Semi-structured (XML): 1990 - 2005?

Example, supplier, parts, supply

- Supplier (sno, sname, scity, sstate)
- Part(pno, pname, psize, pcolor)
- Supply (sno, pnp, qty, price)

## II IMS Era

- record type, fields and types of each fields
- types need to be tree, all should have parent except root (hard to express the example)
- DL/1 record at a time, many ways to write it, some are good, related with storage format
- pure sequential can't insert, read all, insert and write all `old-master-new-master` processing
- very low **physical data independence**
- has **logical data independence**, you can add field later and exclude them in query
- can craft physical database together to form logical database (hard, so IBM goes to relational decade after)

### Lessons

- **Physical and logical data independence are highly desirable**
- Tree structured data models are very restrictive
- It's a challenge to provide sophisticated logical reorganizations of tree structured data
- **a record-at-a-time user interface forces the programmer to do manual query optimization, and this is often hard**

## III CODASYL Era

a network data model along with a record-at-a-time data manipulation language

- no physical and logical independence
- can be used to describe graph (it's network ... tree with cycle after all)
- even harder for programmer to think

### Lessons

- Networks are more flexible than hierarchies but more complex
- loading and recovering networks is more complex than hierarchies
