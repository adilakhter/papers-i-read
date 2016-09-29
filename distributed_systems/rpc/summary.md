# RPC

## Intro

### 1.3 Aims

- ease the pain and let more people build distributed systems
  - highly efficient
  - semantics of the RPC packages, as powerful as possible
  - resolve the tension between powerful semantics and efficiency

- secure communication

### 1.4 Fundamental Decisions

- Chose PRC over message passing
  - it is embedded in the Mesa language.
- shared memory is not practicable
- semantics of RPC should be close to total calls

### 1.5 Structure

- Stubs
  - user
  - user-stub
  - RPCRuntime
  - server-stub
  - server

stub pack and upack argument and result


## 2 Binding

- client specify what he wants to be bound to -> naming
- caller determine the machine address of the callee and specify to the callee the procedure to be invoked -> location


### 2.1 Naming

- use a distributed database called Grapevine

### 2.2 Locating

- also use Grapevine

## 3 Packet Level Transport Protocol
