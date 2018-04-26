// program to avoid zombie status of a process

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
	printf("\n Fork Error ");
	else if(pid==0) //first child
	{
		if((pid=fork())<0)
		printf("\n Fork Error");
		else if(pid>0)
			exit(0);\
		sleep(2);
		printf("Second child,parent pid =%ld \n",(long)getppid());
	exit(0);
	}
	if((waitpid(pid,NULL,0))!=pid)
	printf("\n Wait pid error ");
	exit(0);
}
