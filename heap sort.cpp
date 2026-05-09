#include<stdio.h>
int heapsort(int a[],int n);
int heapify(int a[],int n,int i);
int swap(int a[],int i,int j);
int printarray(int a[],int n);
int main()
{
	int a[]={12,6,3,8,2,15};
	int n=sizeof(a)/sizeof(a[0]);
	heapsort(a,n);
	printf("sorted array is \n");
	printarray(a,n);
	return 0;
}
int heapsort(int a[],int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	    heapify(a,n,i);
	for(i=n-1;i>0;i--)
	{
		swap(a,0,i);
		heapify(a,i,0);
	}
}
int heapify(int a[],int n,int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n  &&  a[left]>a[largest])
	   largest=left;
	if(right<n  &&  a[right]>a[largest])
	   largest=right;
	if(largest!=i)
	{
		swap(a,i,largest);
		heapify(a,n,largest);
	}
}
int swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int printarray(int a[],int n)
{
	for(int i=0;i<n;i++)
	   printf("%d  ",a[i]);
}
