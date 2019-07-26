#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return;
}

int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return(b,a%b);
	}
}

void rotatebyd(int arr[],int n,int d)
{
	int g=gcd(d,n);
	int i=0,j,temp;
	while(i<g)
	{
		temp=arr[i];
		for(j=i;j<=n;j=j+g)
		{
			arr[j]=arr[j+g];
		}
	}
	printArray(arr,n);
}

int main()
{
	int t,d;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
        scanf("%d",&d);
        rotatebyd(arr,n,d);	
	}
	return 0;
}
