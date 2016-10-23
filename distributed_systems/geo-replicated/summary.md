# Summary: Stronger Semantics for Low-Latency Geo-Replicated Storage

## Introduction

Low latency

- close to DC
- fast processing

Rich data model

- K-V is not enough
- Column DB like BigTable, Cassandra
  - Column family
  - Numeric counter

Eiger

- low latency
- rich column family data model
- stronger than eventual consistency
  - atomic update
  - transactions

**track dependencies on operations to ensure consistency** kind of like bayou?

- read only
  - logical time
- write only transactions
  - atomically update multiple columns of multiple keys spread across servers in a data center

## 2. Background

### 2.1 Web Service Architecture

... replica inside dc and cross dc

### 2.2 Column-Family Data Model

**Basic Data Model:**

- The column-family data model is a "map of maps of maps" of named columns"
- The first level map associates a key with a set of named column families
- The second level of maps associates the column-family with a set composed
exclusively of either columns or super columns.
- If present, the third and final level of maps associates each super column with a set
of columns.

**Figure 1**

- each location is represented as a compound key an a signle value 'row-key:column-family:super-column:column'.
- these pairs are stored in a simple ordered key-value store.
- **All data for a single row must reside on the same server.**
- [ ] what's count column?

- counter columns +1

### 2.3 Causal Consistency

> Provide a partial order over operations in the system according to the notion of potential causality

- Thread of Execution
- Reads-From
- Transitive-Closure

only the nearest dependencies are necessary for ensuring causal consistency

## 3 Eiger System Design

Three assumptions so they can focus on novel facets

Many existing systems [5, 13, 16, 54], in fact, provide all assumed properties when used inside a single datacenter.

### 3.1 Achieving Causal Consistency

... quite sleepy (anyway just finish this ...)

locator and unique id

Powerful Client library keep track of dependency and servers

...

Read only transactions

Write only transactions
