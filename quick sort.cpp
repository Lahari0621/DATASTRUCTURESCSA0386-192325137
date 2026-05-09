#include<stdio.h>
#include<stdlib.h>
int quick(int a[],int l,int b)
{
	int pivot=a[l];
	int start=l;
	int end=b;
	int temp;
	while(start<end)
	{
		while(a[start]<=pivot)
		start++;
		while(a[end]>pivot)
		end--;
	if(start<end)
	{
		temp=a[start];
		a[start]=a[end];
		a[end]=temp;
	}
}
temp=a[l];
a[l]=a[end];
a[end]=temp;
return end;
}
void sort(int a[],int l,int u)
{
	if(l<u)
	{
	int res=quick(a,l,u);
	quick(a,l,res-1);
	quick(a,res+1,u);
}
}
int print(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
int main()
{
	int a[]={8,6,7,2,9,1},n;
	n=sizeof(a)/sizeof(a[0]);
	printf("original array:");
	print(a,n);
	sort(a,0,n-1);
	printf("\nsorted array ");
	print(a,n);
	return 0;
}
