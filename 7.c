// program to copy access and modification time of a file to another file using utime fucntion

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<utime.h>
#include<time.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int fd;
	struct stat statbuf1;
	struct stat statbuf2;
	struct utimbuf times;
	if(stat(argv[1],&statbuf1)<0)
		printf("\n Error \n");
	if(stat(argv[2],&statbuf2)<0)
		printf("\n Error \n");
	printf("\n Before copying \n");
	printf("\n Access time %s \n and modifictaion tome %s",ctime(&statbuf1.st_atime),ctime(&statbuf1.st_mtime) );
	times.actime=statbuf2.st_mtime;
	times.modtime=statbuf2.st_mtime;
	if(utime(argv[1],&times)<0)
		printf("\n Error copying timr");
	if(stat(argv[1],&statbuf1)<0)
		printf("\n Error");
	printf("\n After copying : \n");
	printf("\n Access Times %s and modification time %s \n",ctime(&statbuf1.st_atime),ctime(&statbuf1.st_mtime));
}

	
