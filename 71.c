#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
#include<utime.h>
int main(int argc, char *argv[]){
	struct stat fs1,fs2;
	struct utimbuf times;
	if(stat(argv[1],&fs1)<0){
		printf("error\n");
		exit(1);
	}
	if(stat(argv[2],&fs2)<0){
		printf("error\n");
		exit(1);
	}
	printf("before copying\n");
	printf("acces time %s \n modification time %s\n",ctime(&fs1.st_atime),ctime(&fs1.st_mtime));
	times.modtime=fs2.st_mtime;
	times.actime=fs2.st_atime;
	if(utime(argv[1],&times)<0)
		printf("error 1\n");
	stat(argv[1],&fs1);
	
	printf("after copying\n");
	printf("access time %s \n Modification time %s\n",ctime(&fs1.st_atime),ctime(&fs1.st_mtime));

}
