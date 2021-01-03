#include<stdio.h>
void swap(int *a, int *b)
{
	int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int low, int high)
{
	int pivot, i, j;
	pivot = a[low];
	i = low;
	for(j=low+1;j<=high;j++)
	{
		if(a[j]<=pivot)
		{
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[low],&a[i]);
	return i;
}
int selectionprocedure(int a[],int low, int high, int k)
{
	int m, i = low, j = high;
	if(i==j)
	{
		return a[i];
	}
	else 
	{
		m = partition(a, low, high);
		if(m == k)
		{
			return (m);
		}
		else if(k<m)
		{
			selectionprocedure(a,i,m-1,k);
		}
		else
		{
			selectionprocedure(a,m+1,j,k);
		}
	}
}
int Quicksort(int a[],int i, int j)
{
	int m;
	if(i<j)
	{
		m = partition(a,i,j);		
		Quicksort(a,i,m-1);
		Quicksort(a,m+1,j);
	}
}
int main()
{
	int m,k, a[] = { 12, 11, 13, 5, 6, 7 },n=6;
	Quicksort(a,0,n-1);
	printf("\nSorted array\n");
	for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
	printf ("\nEnter the kth element to be searched (less than 7)\n");
	scanf("%d",&k);
	m = selectionprocedure(a,0,n-1,k);
	printf("\n%d",a[m-1]);
}
