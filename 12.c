//program such that it initializes itself as a daemon process
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
void deamonize()
{
	pid_t pid=fork();
	if(pid<0)
		fprintf(stderr,"Error Forking");
	else if(pid)
	{
	printf("PID of CHILD %d \n",pid);
	exit(0); //kill aprent process , child is orphaned and runs in background
	}
umask(0);
if(chdir("/")<0)
	printf("\n Error changing directory");
if((setsid())<0) 
	printf(" Error creating session"); // make the child process session leader
printf("\n Deamon created");
}

	int main()
	{
		deamonize();
	//	system("ps-axj");
	}
	
