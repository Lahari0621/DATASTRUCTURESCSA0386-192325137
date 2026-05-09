#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		int swap=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap=1;
			}
		}
			if(swap==0)
			break;
	}
	printf("\nsorted array is ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[10]={9,10,-9,23,67,-90},n=6;
	sort(a,n);
	return 0;
}
