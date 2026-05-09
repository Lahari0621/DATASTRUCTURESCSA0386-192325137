#include<stdio.h>
int main()
{
	int a[10],b[10],i=0,sum=0,n=0,m=0;
	scanf("%d%d",&n,&m);
	if(n<=10 && m<=10)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
			sum+=b[i];
		}
	}
	printf("\nsum is %d",sum);
}
