/*#include<stdio.h>
int main()
{
	int f=1,n,i;
	scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    	f=f*i;
	}
	printf("%d",f);
	return 0;
}*/
#include<stdio.h>
int main()
{
	int a[5]={1,2,3,4,5},f=1,i,b[5];
    for(i=0;i<5;i++)
    {
    	f=f*a[i];
    	b[i]=f;
	printf(" %d ",b[i]);
}
	return 0;
}
