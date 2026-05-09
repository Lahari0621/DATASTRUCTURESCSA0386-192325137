#include<stdio.h>
int main()
{
	int f1=0,f2=1,f3=f1+f2,sum=0;
	sum=f1+f2+f3;
	int i;
	printf("%d %d %d ",f1,f2,f3);
	for(i=0;i<10;i++)
	{
		f1=f2;
		f2=f3;
		f3=f1+f2;
		sum=sum+f3;
		printf("%d ",f3);
	}
	printf("\nsum of fib series %d ",sum);
	return 0;
	
}
