// program to demonstrate race condition among parent and child process

#include<stdio.h>
#include<unistd.h>
static void charatatime(char *);
int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
		printf("\n Fork error");
	else if(pid==0)
	{
		charatatime("\n output from childaaaaaaaaaaaaaaa\n");
	}
	else
		charatatime("\n Output from parentrrrrrrrrrrr\n");
	exit(0);
}
static void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;(c=*ptr++)!=0;)
	putc(c,stdout);
}

