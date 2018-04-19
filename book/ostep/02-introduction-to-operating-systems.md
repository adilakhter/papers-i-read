# Chapter 2: Introduction to Operating Systems

## Crux

- How to virtualize resources
  - why is obvious, easier to use
- How to build correct concurrent programs
- How to store data persistently

## 2.0 Intro

OS virtualize the underlying hardware for programs running on it

> Thus, we sometimes refer to the operating systems as a virtual machine

## 2.1 Virtualizing CPU

- an example c program that print args[1]
- multiple process seems to be running in parallel even when there is just one physical CPU

## 2.2 Virtualizing Memory

- memory is just an array of bytes
- an example c program that calls malloc and print pointer address
  - different process have same pointer address because it's virtual address
  - need to disable address-space randomization
    - stack smashing attack

## 2.3 Concurrency

- an example c program use pthread

## 2.4 Persistence

> You should be using Emacs. If you are using vi, there is probably something wrong with
you. If you are using something that is not a real code editor, that is even worse.

- filesystem delays writes a while hoping to batch them
- journaling or copy-on-write

## 2.5 Design Goals

- virtualization (abstraction)
- performance (minimize the overhead)
- protection

## 2.6 Some History

- operator that does the job os operating system
- system call was invented to distinguish os from other programs
- unix
- PC, DOS
- UNIX & LINUX