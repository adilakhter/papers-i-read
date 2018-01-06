# Architecture of a Database System

## TOC

- Abstract
- 1 Introduction
  - 1.1 Relational Systems: The Life of a Query
  - 1.2 Scope and Overview
- 2 Process Models

## 1 Introduction

### 1.1 Relational Systems: The Life of a Query

![Fig 1.1 Main component of a DBMS](main-components-of-a-DBMS.png)

#### 1. Communication Manager

- establish connection, remember state, respond SQL from caller
- return both data and control messages (error code etc.)

Tiers

- two tier: client server
- three tier: browser php mysql
- four tier: browser php java mysql

#### 2. Process Manager

- assign a "thread of computation" to the command.
- decide when to start processing the query.

#### 3. Relational Query

- compile SQL query to internal query plan
- query optimization
- plan executor, consists operators
  - join, selection, projection, aggregation, sorting

#### 4. Transactional Storage Manager

- buffer manager: when and what data to transfer between disk and memory buffer
- lock manager: ACID
- log manager: updates

#### 5. Result

- unwind the stack
- client make multiple call for large dataset
  - [ ] does server keep a cache of it, or re-run the query when client ask more

#### Shared utilities

- catalog manager: authentication, parsing, query optimization

### 1.2 Scope and Overview

- overall process structure, uniprocessor machines, then parallel architecture

## 2 Process Models

> when designing any multi-user server, early decisions need to be made regarding the execution of concurrent user requests and how these are mapped to operating system processes or threads.

- *OS Process* is scheduled by kernel and has its own unique address space
- *OS Thread* no private context, no private address space, has full access to other threads within same process, scheduled by kernel, `k-threads`
- *Lightweight Thread Package* (LWT) user-space thread, blocks all thread when any thread has blocking operation like synchronous I/O
- *DBMS Client*, JDBC, ODBC, OLE/DB, Embedded SQL
- *DBMS Worker*  thread of execution in the DBMS that does work on behalf of a DBMS Client. 1:1 mapping.

### 2.1 Uniprocessors and Lightweight Threads