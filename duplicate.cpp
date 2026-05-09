#include<stdio.h>
int main()
{
	int n,a[n],i,j,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==-1)
		continue;
		count=0;
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
			count+=1;
			a[j]=-1;}
		}
		if(a[i]!=-1)
		printf("\n%d is counted= %d",a[i],count+1);
	}
	return 0;
}
