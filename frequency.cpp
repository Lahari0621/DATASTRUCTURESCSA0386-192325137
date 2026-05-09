#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	scanf("%s",a);
	int i,j,count=0,n;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		count=1;
		if(a[i]==-1)
		continue;
	    for(j=i+1;j<n;j++)
	    {
	    	if(a[i]==a[j])
	    	{
	    		count++;
	    		a[j]=-1;
			}
		}
		if(a[i]!=-1)
		printf("%c->%d ",a[i],count);
	}
	return 0;
}
