#include<stdio.h>
int main()
{
	int a[]={1,4,3,6,7,8},n,gap,i,j;
	n=sizeof(a)/sizeof(a[0]);
	for(gap=n/2;gap>=1;gap/=2)
	{
		for(j=gap;j<n;j++)
		{
			for(i=j-gap;i>=0;i-=gap)
			{
				if(a[i+gap]>a[i])
				break;
				else
				{
					int temp=a[i+gap];
					a[i+gap]=a[i];
					a[i]=temp;
				}
			}
		}
	}
	printf("sorted array is ");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
    return 0;
}
