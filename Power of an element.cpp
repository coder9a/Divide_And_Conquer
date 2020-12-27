#include<stdio.h>
int DAC_power(int,int);
int main ()
{
	int a,n,x;
	printf("Enter Number\n");
	scanf("%d",&a);
	printf("Enter Power\n");
	scanf("%d",&n);
	x = DAC_power(a,n);
	printf("%d",x);
	
}
int DAC_power(int a,int n)
{
	int b,c,mid;
	if(n==1||n==0)
	{
		return a;
	}
	else
	{
		mid = n/2;
		b = DAC_power(a,mid);
		c = b*b;
		if(n%2==0)
		{
			return c;
		}
		else
		{
			return c*a;
		}
	}
}
