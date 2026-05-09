#include<stdio.h>
int main()
{
	int a[3]={1,2,3},b[3]={1,2,3},c[9],i,j;	
	for(i=0;i<3;i++)
		{
			c[i]=a[i];
		}
	for(i=0;i<3;i++)
		{
			c[3+i]=b[i];
		}
	for(i=0;i<6;i++)
		{
			printf("%d",c[i]);
		}
return 0;	
}
