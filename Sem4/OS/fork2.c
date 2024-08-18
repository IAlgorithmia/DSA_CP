#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	fork();
	printf("hello\n");
	fork();
	printf("hello\n");
	fork();
	printf("hello\n");
	return 0;
}

