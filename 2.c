#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int file=0,n;
	char buffer[25];
	if((file =open("testfile.txt",O_RDONLY))<0)
		return 1;
	if(read(file,buffer,20)!=20)
		return 1;
	printf("\n");

	if(lseek(file,10,SEEK_SET)<10)
		return 1;
	if(read(file,buffer,20)!=20)
		return 1;
	write(STDOUT_FILENO,buffer,20);
	printf("\n");
	if(lseek(file,10,SEEK_CUR)<0)
		return 1;
	if(read(file,buffer,20)!=20)
		return 1;
	write(STDOUT_FILENO,buffer,20);

	printf("\n");
	if((n= lseek(file,0,SEEK_END))<0)
		return 1;

	printf("\n Size of file is %d bytes \n",n);
	close(file);
	
return 0;
} 


