# Encapsulation of Parallelism in the Volcano Query Processing System

## Abstract

Two methods for parallel

- bracket model
- operator model (their choice)

## 1 Introduction

- For test and education, 15, 000 LOC in C
- *exchange* module, allow parrallelsim all the other modules without changing their code
- existing problem, disk triping
- novel: use operator model instead of bracket model
- [ ] synchronzie multiple operators in complex query trees within a single process
and to exchange data items between operators are very similar to commercial dbs

## 2 Previous works

- strongly influenced by GAMMA except the **data exchange mechanism between operators**
- [ ] query execution engine should provide mechanisms, and that the query optimizer should incorporate and decide on polices
  - [ ] what is query executin engine
  - [ ] what is query optimizer

### 2.1 The Bracket Model of Parallelism

- it can't avoid network and IPC
- in most sigle process query processing engines, procedure calls are more efficient than system calls
