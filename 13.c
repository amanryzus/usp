// program using sigaction system call which calls a signal handler on signint signal and then reset the default action of sigint signal

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

struct sigaction sig;
void handler(int val)
{
	printf("\n Interrupt Recieved! \n");
	sig.sa_handler=SIG_DFL;
	sigaction(SIGINT,&sig,0);
}
	int main()
{
	sig.sa_flags=0;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask,SIGINT); //listen only to SIGINT
	sig.sa_handler=handler;
	sigaction(SIGINT,&sig,0);
	while(1)
{	printf("\n Progress is hapiness  \n");
	sleep(1);
	}
}
