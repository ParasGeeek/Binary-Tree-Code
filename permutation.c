#include<stdio.h>
#include<stdlib.h>

void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void permutation(int arr[],int size,int n)
{
	if(size==1)
	{
		printArray(arr,n);
		return;
	}
	for(int i=0;i<size;i++)
	{
		permutation(arr,size-1,n);
		if(size%2==1)
		{
			swap(&arr[0],&arr[size-1]);
		}
		else
		{
			swap(&arr[i],&arr[size-1]);
		}
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	permutation(arr,n,n);
	return 0;
}
