#include<stdio.h>
#include<stdlib.h>

// It will take T(n)=O(n)... and S(n)=O(n)....

int max(int a,int b)
{
	return(a>b?a:b);
}

int min(int a,int b)
{
	return(a>b?b:a);
}

int trapped_water(int *arr,int n)
{
	int *left=(int*)malloc(sizeof(int)*n);
	int *right=(int*)malloc(sizeof(int)*n);
	int sum=0;
	left[0]=arr[0];
	right[n-1]=arr[n-1];
	for(int i=1;i<n;i++)
	{
		left[i]=max(left[i-1],arr[i]);
	}
	for(int j=n-2;j>=0;j--)
	{
		right[j]=max(right[j+1],arr[j]);
	}
	for(int k=0;k<n;k++)
	{
		sum=sum+(min(left[k],right[k])-arr[k]);
	}
	return sum;
}

int main()
{
	int t;
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
		printf("%d\n",trapped_water(arr,n));
	}
	return 0;
}
