//execDemo.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
		//A null terminated array of character 
		//pointers
		char *args[]={"./EXEC",NULL};
		execvp(args[0],args);
	
		/*All statements are ignored after execvp() call as this whole 
		process(execDemo.c) is replaced by another process (EXEC.c)
		*/
		printf("Ending-----");
	
	return 0;
}
/*
what's the difference between the two? With execv(), the first argument is a path to the executable. With execvp(), the first argument is a filename. It must be converted to a path before it can used.
*/
