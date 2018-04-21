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
