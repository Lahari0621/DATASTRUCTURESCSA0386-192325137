#include<stdio.h>
int main()
{
	int a[]={25,47,42,56,32};
	int n=sizeof(a)/sizeof(a[0]);
	printf("the even elements are:");
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		  printf("%d ",a[i]);
	}
	printf("\nthe odd elements are:");
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		  printf("%d ",a[i]);
	}
	return 0;
}
