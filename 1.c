#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1,fd2,offset;
	char c;
	fd1=open("foo.txt",O_RDONLY);
	if(fd1<0)
		printf("Open Error");
	fd2=open("foorev.txt",O_RDWR);
	if(fd2<0)
		printf("\n OPen Error");
	offset=lseek(fd1,0L,SEEK_END);
	while(offset>0)
	{
		read(fd1,&c,1);
		write(fd2,&c,1);
		lseek(fd1,-2,SEEK_CUR);
		offset--;
	}
	close(fd1);
	close(fd2);
	
return 0;
}
