# Chapter 6: Mechanism: Limited Direct Execution

## Take away

- the OS is also a program, it must regain control of CPU from current running program to do fill its OS job
- reboot is useful

## TODO

- [ ] kernel stack

## Crux

- How to efficiently virtualize the CPU with control
- How to perform restricted operations
- How to regain control of the CPU
  - when a process is running, the OS is not running, but the OS need to stop one process to run another one
- How to gain control without cooperation

## Intro

- performance
- control

## 6.1 Basic Technique: Limited Direct Execution (LDE)

- just run the program, jump to its main
- can't control what the program do
- can't stop it in the middle

## 6.2 Problem #1: Restricted Operations

aside: why syscall look like procedure calls

- it is procedure call
- the **trap** instruction is hidden inside, assembly code is in library so you don't need to write it

User mode

- can't issue I/O requests
  - the OS would kill the process
  - [ ] so kernel bypass? DPDK, SPDK

Kernel mode

- do anything

System Call

- program execute a special `trap` instruction
- jumps into kernel and raise privilege level to kernel mode
- os calls `return-from-trap` instruction, returns into calling user program nad reduce the privilege level back to user mode
- hardware, on x86, processor will push program counter, flags into a per-process **kernel stack**
  - saw it in previous xv6 process struct, has a `kstack` pointer
- `trap table` is **set up at boot time**
  - os tell hardware location of trap handlers
- user code specify `system-call number` instead of the address it wants to jump to

## 6.3 Problem #2: Switching Between Processes

> if a process is running on the CPU, this by definition means the OS is not running. If the OS is not running, how can it do anything at all? (hint: it can't)

### A Cooperative Approach: Wait For System Calls

- take in the past by Machintosh
- OS **trusts** the process to give up the CPU periodically even it runs for a long time, so the OS can run
- OS passively wait for the process to make system call or doing illegal action
- what about `while (1) { i = 0;}`
  - reboot ....

> In fact, in the cooperative approach, your only recourse when a process gets stuck in an infinite loop is to resort to the age-old solution to all problems in computer systems: reboot the machine

### A Non-Cooperative Approach: The OS Takes Control

A timer interrupt in hardware

- every several milliseconds, interrupt is raised and a `interrupt handler` in the OS is called
  - thus OS regain control of the CPU
  - [ ] TODO: what about other devices, it seems OS always control other devices since other program run in user mode and can't access device directly
- [ ] TODO: the timer can be turned off, will discuss later after concurrency?
- hardware need to save state when interrupt happens, just like trap

### Saving and Restoring Context

- scheduler decide if the progress should continue running or a new process should take its place
  - [ ] TODO: maybe the OS can take its place since OS also need to run some compute
- context switch
  - save current running (onto its kernel stack)
  - restore to be executed

aside: lmbench to measure cost of context switch, https://github.com/dmonakhov/lmbench not official I guess

## 6.4 Worried About Concurrency ?

What if in the middle of system call, a timer interrupt occurs or when handling one interrupt, another one happens?

- disable interrupts during interrupt processing
- locking schemes

## 6.5 Summary

tip: reboot is useful

## References

- Microreboot - A Technique for Cheap Recovery

> An excellent paper pointing out how far one can go with reboot in building more robust systems

## Homework

Measure cost of system call and context switch

- use `sched_setaffinity()` to ensure both processes are on the same processor