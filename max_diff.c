#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}

void MaxDiff(int *arr,int n)
{
	
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
		MaxDiff(arr,n);
		//printf("After segregation:\n");
		printArray(arr,n);
	}
	return 0;
}

