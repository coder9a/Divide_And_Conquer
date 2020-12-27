#include<stdio.h>
int n;
int DAC_binarysearch(int a[],int i,int j,int x);
int main()
{
	int x,y,a[n];
	printf("Enter array size\n");
	scanf("\n%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d",&x);
	y = DAC_binarysearch(a,0,n-1,x);
	if(y==-1)
	{
		printf("Element not found");
	}
	printf("Element found at %d",y+1);
}
int DAC_binarysearch(int a[],int i,int j,int x)
{
	int mid;
	if(i==j)
	{
		if(a[i] == x)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		mid = (i+j)/2;
		if(a[mid]==x)
		{
			return mid;
		}
		else if(x<a[mid])
		{
			DAC_binarysearch(a,i,mid-1,x);
		}
		else
		{
			DAC_binarysearch(a,mid+1,j,x);
		}
	}
}
