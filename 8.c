// program to illustrate effect of setjump and long jump fucntions on register and volatile variables

#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>

static void f1(int ,int ,int ,int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int main(void)
{
	int autoval;
	register int regival;
	volatile int volaval;
	static int statval;
	
	globval=1;autoval=2;regival=3;volaval=4;statval=5;
	if(setjmp(jmpbuffer)!=0)
	{
		printf("\n After long jump :\n");
	printf("Globval =%d,autoval=%d,regival=%d,volaval=%d,statval=%d\n",globval,autoval,regival,volaval,statval);
	exit(0);
	}

        globval=95;autoval=96;regival=97;volaval=98;statval=99;
	f1(autoval,regival,volaval,statval);
		exit(0);
}

static void f1(int i,int j,int k,int l)
{
	printf("\n in f1() :\n");
	printf("\n globval =%d,autoval=%d,regival=%d,volaval=%d,statval=%d\n",globval,i,j,k,l);
	j=10000;
	f2();
}

static void f2(void)
{
	longjmp(jmpbuffer,1);
}
