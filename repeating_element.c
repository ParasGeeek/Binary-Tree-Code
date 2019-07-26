#include<stdio.h>
#include<stdlib.h>
/*
void printArray(int *arr,int n)
{
	int i;
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}
*/
void fre(int *arr,int n)
{
	int *count=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		if(count[arr[i]]==1)
		{
			printf("%d ",arr[i]);
		}
		else
		{
			count[arr[i]]++;
		}
	}
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n+2];
		for(int i=0;i<n+2;i++)
		{
			scanf("%d",&arr[i]);
		}
		fre(arr,n+2);
	}
	return 0;
}
