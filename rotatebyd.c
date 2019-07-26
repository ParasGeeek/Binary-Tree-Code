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

void rotatebyd(int *arr,int n,int d)
{
	int i,j;
	int *arr1=(int*)malloc(sizeof(int)*d);
	for(i=0;i<d;i++)
	{
		arr1[i]=arr[i];
	}
	for(i=d;i<=n;i++)
	{
		arr[i-d]=arr[i];
	}
	for(i=n-d,j=0;i<=n,j<d;i++,j++)
	{
		arr[i]=arr1[j];
	}
	printArray(arr,n);
	return;
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
