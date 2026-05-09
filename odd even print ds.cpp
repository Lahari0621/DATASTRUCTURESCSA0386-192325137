#include<stdio.h>
int main()
{
	int a[5]={1,2,3,4,5},i;
	for(i=0;i<5;i++)
	{
		if(a[i]%2==0)
		printf("\neven %d",a[i]);
		else if(a[i]%2==1)
		printf("\nodd %d",a[i]);
	}
	return 0;
}
