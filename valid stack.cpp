#include<stdio.h>
int check(int push[],int n,int pop[],int m)
{
	int a[100],i,j,popindex=0,top=-1;
	for(i=0;i<n;i++)
	{
		a[++top]=push[i];
		while(top>=0 && a[top]==pop[popindex])
		{
			top--;
			popindex++;
		}
	}
	return popindex==m;
}
int main()
{
	int push[100],pop[100],n=5,m=5,i;
	printf("push elementsn in stack");
	for(i=0;i<n;i++)
	scanf("%d",&push[i]);
	printf("pop elements in stack");
	for(i=0;i<m;i++)
	scanf("%d",&pop[i]);
	printf("%s\n ",check(push,n,pop,m)?"True":"false");
	return 0;
}
