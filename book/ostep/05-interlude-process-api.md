# Chapter 5: Interlude: Process API

- interludes are for practical aspects, i.e. API from real OS

## Crux

- How to create and control process

## 5.1 The fork() System Call

content of [05-p1.c](05-p1.c)

````c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	printf("hello world pid:%d\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed return code:%d\n", rc);
		exit(1);
	} else if (rc == 0) { 
		printf("I am child pid:%d\n", (int) getpid());
	} else {
		printf("I am parent of %d pid:%d\n", rc, (int) getpid());
	}
	return 0;
}
````

````text
>  ./a.out
hello world pid:14423
I am parent of 14424 pid:14423
I am child pid:14424
````

- the forked process does not start from the very beginning of `main`, `hello world` is only printed once
- return value of `fork`, for parent it's the pid of child process, for child it is 0
- NOTE: it says due to CPU scheduler, the parent print may happens after child in the terminal, but for me it seems it's always the same order

## 5.2 The wait() System Call

- `wait` and `waitpid`

content of [05-p2.c](05-p2.c)

````c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
	printf("hello world pid:%d\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed return code:%d\n", rc);
		exit(1);
	} else if (rc == 0) { 
		printf("I am child pid:%d\n", (int) getpid());
	} else {
		int wc = wait(NULL);
		printf("I am parent of %d wc:%d pid:%d\n", rc, wc, (int) getpid());
	}
	return 0;
}
````

````text
>  ./a.out
hello world pid:16052
I am child pid:16053
I am parent of 16053 wc:16053 pid:16052
````

- the output is deterministic due to `wait`
- NOTE: 'on success, returns the process ID of the terminated child; on error, -1 is returned' from `man wait`

## 5.3 Finally, The exec() System Call

- `fork` gives you a copy, `exec` let you run a different program
- `exec`
  - load code from that executable and overwrites its current code segment (and current static data)
  - re-initialize memory space

content of [05-p3.c](05-p3.c)

````c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	printf("hello world pid:%d\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed return code:%d\n", rc);
		exit(1);
	} else if (rc == 0) { 
		printf("I am child pid:%d\n", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc"); // The strdup() function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string is obtained with malloc(3), and can be freed with free(3)
		myargs[1] = strdup("05-p3.c");
		myargs[2] = NULL; // end of array
		execvp(myargs[0], myargs);
		printf("you shall not see me");
	} else {
		int wc = wait(NULL);
		printf("I am parent of %d wc:%d pid:%d\n", rc, wc, (int) getpid());
	}
	return 0;
}
````

````text
>  ./a.out
hello world pid:18253
I am child pid:18254
 28 128 838 05-p3.c
I am parent of 18254 wc:18254 pid:18253
````

## 5.4 Why? Motivating The API

- getting it right (Lampson's Law)

**Why need fork before exec**: useful for shell

  > the separation of fork() and exec() is essential in building a Unix shell, because it lets the shell run code after the call to fork() but before the call to exec()

Examples

- `cat /proc/version > /tmp/ver.txt`, before call `exec`, it close stdout, open `/tmp/ver.txt` and redirect stdout to it

content of [05-p4.c](05-p4.c)

> this only works because Unix systems start looking for free file descriptors at 0, STDOUT_FILENO will be the first available one and thus get assigned when open() is called

- `ls -l /proc/<pid>/fd` and you will see number grow from 0 continuously
- Unix pipe are implemented in similar way

````c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> // for close stdio

int
main(int argc, char *argv[])
{
	printf("hello world pid:%d\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed return code:%d\n", rc);
		exit(1);
	} else if (rc == 0) { 
		close(STDOUT_FILENO);
		open("./05-p4.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); // TODO: what is S_IRWXU

		printf("I am child pid:%d\n", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc"); // The strdup() function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string is obtained with malloc(3), and can be freed with free(3)
		myargs[1] = strdup("05-p3.c");
		myargs[2] = NULL; // end of array
		execvp(myargs[0], myargs);
		printf("you shall not see me");
	} else {
		int wc = wait(NULL);
		printf("I am parent of %d wc:%d pid:%d\n", rc, wc, (int) getpid());
	}
	return 0;
}
````

````text
hello world pid:18443
I am parent of 18444 wc:18444 pid:18443

// cat 05-p4.txt
I am child pid:18444
 28 128 838 05-p3.c
````

## 5.5 Other Parts Of The API

- `kill`

> when run top, top claims it is the top resource hog

## 5.6 Summary

## References

- Hints for Computer Systems Design 1983
- Advanced Programming in the Unix Environment 2005

## Homework

> If you don't like to code, but want to become a computer scientist, this means you need to either (a) become really good at the theory of computer science, or (b) perhaps rethink this whole "computer science" thing you've been telling everyone about

- [ ] TODO: write them in os-learning repo, because try out apis