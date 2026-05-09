#include<stdio.h>
int mergesort(int a[],int l,int m,int r)
{
	int n1,n2,k,i,j;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	R[j]=a[m+l+j];
	i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[i])
		{
		a[k]=L[i];
		i++;
	    }
	    else
	    {
	    	a[k]=R[j];
	    	j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}
int merge(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-1)/2;
		merge(a,l,m);
		merge(a,m+1,r);
		mergesort(a,l,m,r);
	}
}
int print(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
int main()
{
	int a[]={5,9,3,17,6,1},n;
	n=sizeof(a)/sizeof(a[0]);
	printf("original sort ");
	print(a,n);
	merge(a,0,n-1);
	print(a,n);
	return 0;
}
