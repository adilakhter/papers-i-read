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
