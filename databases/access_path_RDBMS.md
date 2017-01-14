# Access path in realtional database management system

1979 IBM

## Take away

- [ ] optimzer cost formulas

## Abstract

System R, SQL is stated non-procedurally without reference to access path

- [ ] so it's like an query generator? from SQL to generate the real query plan,
which tuple should I read etc.

## 1 Introduction

> In System R a user need not know how the tuples are physically stored and what
access paths are avaliable (e.g. which columns have indexes)

> The System R optimizer chooses both join order and an access path for each table
in the SQL statement

## 2 Processing of a SQL statement

place of the optimizer in the processing of a SQL statement

> A SQL statement is subjected to 4 phases of processing

- parsing
- optimization
- code generation
- execution

Optimizer

- lookup in catalogs to gather tables, columns, relations, avaliable access paths
- rescan SQL for validation and type compatibility
- access path selection
- result is execution plan in Acess Specification Language (ASL)

Code genertor

- parse tree replaced by executable machine code and its associated data structure
- execute on RSS via RSI

## 3 The Research Storage System

storage component access paths that are avaliable on a single physically stored
table

- [ ] use locking for multi user
- Present Tuple Oriented interface (RSI) to user
- [ ] relations are stored in the RSS as a collection of tuples whose columns are physically contiguous
- tuples stored in 4K pages, no tuple spans a page
- pages are organized into logical units called segments.
- segments may contain one or more relations, but no relation may span a segmant

RSS Scan

- segmant scan
- index scan
  - use B-trees
  - indexes stored in different pages
  - clustered index
    - tuples are inserted into segment pages in the index ordering
      - [ ] TODO: sorted -> clustered index?
    - both index and data page will be touched only once during index scan

SARGS search arguments

- reject tuple within RSS
- Not all predicates are of the form that can become SARGS,
  - [ ] TODO: i.e. `where name > 12` can become SARGS and `where a.name > b.name` can not?

## 4 Cost for single relation access path

**optimizer cost formulas**

From simplest single relation, 2-way join, n-way joins, multiple query blocks (nested queries)

COST = PAGE FETCHES + W * (RSI CALLS)

- PAGE FETCHES I/O
- RSI CALLS represent CPU usage
  - [ ] is the predicted number of tuples returned from RSS
- W adjustable weight factor

WHERE tree

- [ ] considered to be in conujunctive normal form
- boolean factors
  - every tuple returned to the user must satisfy every boolean factor
  - [ ] a predicate or set of predicates matches an index access path when the predicates are sargable and the columns mentioned in the predicate(s) are an initila substring of the set of columns of the index key

Statistics are updated periodically by and `UPDATE STATISTICS` command which can
be run by any user
- [ ] TODO: it is not updated after every UPDATE, DELETE, INSERT command,
so meaning the statistics don't need to be "real-time"

The OPTIMIZER assigns a **selectivity factor 'F'** for each boolean factor in the
predicate list

- cardinality: the number of elements in a set .... (this is what I learned when writing [gommon](https://github.com/dyweb/gommon))
- [ ] TODO: columnA in subquery (didn't understand it clearly)
- [ ] TODO: Using an index access path or sorting tuples produces tuples in the index
value or sort key order.
- [ ] TODO: a tuple order is an interesting order if that order is one specified by the query block's GROUP BY or ORDER BY clauses

## 5
