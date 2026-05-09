#include<stdio.h>
int miss(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		while(a[i]>0 && a[i]<=n && a[a[i]-1]!=a[i])
		{
			int temp=a[i];
			a[i]=a[a[i]-1];
			a[temp-1]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=i+1)
		return i+1;
	}
   return n+1;
}
int main()
{
	int a[]={2,3,-7,6,8,1,-10,15},n;
	n=sizeof(a)/sizeof(a[0]);
	int b=miss(a,n);
	printf("the missed smallest positive element is %d",b);
	return 0;
}
