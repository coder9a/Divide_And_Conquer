#include<stdio.h>
int merge(int a[],int low, int mid, int high);
int mergesort(int a[],int i, int j);
void printarray(int *a, int n);
int main()
{
	int a[] = { 12, 11, 13, 5, 6, 7 },n=6, i=0;
	printf("Given array is\n");
	printarray(a,n);
	mergesort(a,i,n-1);
	printf("Sorted array\n");
	printarray(a,n);
	return 0;
}
void printarray(int *a,int n)
{
	int i;
    for (i = 0; i < 6; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
int mergesort(int a[],int i, int j)
{
	int mid;
	if(i==j)
	{
		return a[i];
	}
	if(i<j)
	{
		mid = (i+j)/2;		
		mergesort(a,i,mid);
		mergesort(a,mid+1,j);
		merge(a,i,mid,j);
	}
}
int merge(int a[],int low, int mid, int high)
{
	int i,j,k,b[100];
	i = low;
	j = mid + 1;
	k = low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			b[k] = a[i];
			k++,i++;
		}
		else
		{
			b[k] = a[j];
			k++,j++;
		}
	}
	while(i<=mid)
	{
		b[k] = a[i];
		k++,i++;
	}
	while(j<=high)
	{
		b[k] = a[j];
		k++,j++;
	}
	for(i=low;i<=high;i++)
	{
		a[i] = b[i];
	}
}
