#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void wave_sort(int *arr,int n)
{
	int i;
	for(i=0;i<n;i=i+2)
	{
		if((arr[i-1] > arr[i]) && i!=0)
		{
			swap(&arr[i],&arr[i-1]);
		}
		if(arr[i] < arr[i+1])
		{
			swap(&arr[i],&arr[i+1]);
		}
	}
	printArray(arr,n);
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
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
	    wave_sort(arr,n);
		//printArray(pink,n);
	}
	return 0;
}
