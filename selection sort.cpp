#include<stdio.h>
int main()
{
	int a[]={8,2,6,10,5,4};
	int n=sizeof(a)/sizeof(a[0]);
	int i,j,min=a[0];
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(min>a[j])
				min=a[j];
		}
		int b=a[i];
		a[i]=min;
		min=b;
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
#include <stdio.h>

int main() {
    int a[] = {8, 2, 6, 10, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }

    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

