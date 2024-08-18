#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void hello(){
	printf("Hello there \n");
}

void forkexample()
{
	int x = 1;
	pid_t p = fork();
	if(p<0){
	perror("fork fail");
	exit(1);
	}
	hello();
	kill(p, 9);
	hello();

}
int main()
{
	forkexample();
	return 0;
}
