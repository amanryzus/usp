// program to demonstrate creation of soft links and various properties of hard links

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
	printf("\n ARGC : %d ",argc);
	if(argc==3)
	{
		printf("HARD Linking %s and %s",argv[1],argv[2]);
		if(link(argv[1],argv[2])==0)
			printf("\n Hard link created");
		else printf("\n HArd link not created");
		
	}	
	else if(argc==4)
		{
			printf("\n Soft linking %s and %s ",argv[1],argv[2]);
			if(symlink(argv[1],argv[2])==0)
				printf("\n Soft link crated");
			else printf("\n soft link not created");
		}
	return 0;

	}

