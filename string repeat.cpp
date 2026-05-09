#include<stdio.h>
#include<string.h>
int main()
{
	char a[10];
	int i,j;
	scanf("%s",a);
	int n=strlen(a);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				char temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			printf("\n%c is at %d",a[i],i);
			break;
		}
	}
	return 0;
}
