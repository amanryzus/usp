// program to simulate copy command by accepting the file names form command lin
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int n;
	char line[100];
	int fd1,fd2;
	fd1=open(argv[1],O_RDONLY);
	if(fd1<0) printf("FD1 ERROR \n");
	fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd2<0) printf("\n FD2 ERROR \n");
	n=read(fd1,line,sizeof(line));
	while(n!=0)
	{
		write(fd2,line,n);
		n=read(fd1,line,sizeof(line));
	}
	printf("\nDONE\n");
	return 0;
}	
