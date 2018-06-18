# Chapter 4: The Abstraction: The Process

## Crux

- How to provide the illusion of many CPUs

## 4.0 Intro

- low level machinery mechanisms, i.e. time sharing
  - answers *how*
- high level policies
  - answers *which*

## 4.1 The Abstraction: A Process

- machine state: what a program can read or update when it is running
  - memory, address space
  - registers
    - program counter (PC), sometimes called instruction pointer or IP
    - stack pointer & associated frame pointer to manage the stack for function
  - storage devices

## 4.2 Process API

- create
- destroy
- wait
- miscellaneous control (suspend)
- status

## 4.3 Process Creation: A Little More Detail

- load code and static data into memory (the address space of the process)
  - early OS load everything (eager), modern oOs only load needed (lazily)
    - using paging and swapping
- allocate memory for stack, fill initial parameters
- allocate memory for heap
- I/O, i.e. three open file descriptors (std in/out/err)

## 4.4 Process States

- running
- ready
- blocked, i.e. I/O

## 4.5 Data Structures

- keep process list of
  - ready
  - blocked
- process context

````
// xv6 is used MIT 6.828 https://github.com/mit-pdos/xv6-public
// xv6 Proc structure
struct context {
  int eip; int esp; int ebx; int ecx; int edx; int esi; int edi; int ebp;
};

enum proc_state {
  UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE
};

struct proc {
  char *mem; // start
  unit sz; // size
  char *kstack; // bottom of kernel stack // TODO: why it's kernel stack instead of just stack

  enum proc_state state;
  int pid;
  struct proc *parent; // parent process // TODO: what about init.d
  void *chain; // if non zero, sleeping on chan
  int killed; // if non zero, have been killed
  struct file *ofile[NOFILE]; // open files TODO: what is NOFILE
  struct inode *cwd; // current directory
  struct context context; // switch here to run process TODO: ?
  struct trapframe *tf; // trap frame for the current interrupt
}
````

aside: Process Control Block (PCB)

## 4.6 Summary

## Reference

- https://github.com/mit-pdos/xv6-public

## Homework

- python program for simulation
- NOTE: need to modify the shebang line to use `#!/usr/bin/env python2` instead of `python` because Ubuntu ships `python3` as default
- `./process-run.py -h` to show help
- `./process-run.py -l 4:100,1:0` will show the instruction based on parameters `X:N`, `X` is number of instruction, `N` is it's chances it will use CPU or issue IO
- `./process-run.py -l 4:100,1:0 -c -p` will show the answer, trace (the state of program in each tick?), CPU usage etc.
- `./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p`, after io is finished, keep running what is currently running
- `./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE -c -p`, after io is finished, resume the process waiting for io (cause it might issue new io and start waiting again)
