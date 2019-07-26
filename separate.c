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

void separate(int *arr,int n)
{
	//int i;
	int left_index=0,right_index=n-1;
	while(left_index < right_index)
	{
		while((arr[left_index]==0) && (left_index < right_index))
		{
			left_index++;
		}
		while((arr[right_index]==1) && (right_index > left_index))
		{
			right_index--;
		}
		if(left_index < right_index)
		{
			arr[left_index++]=0;
			arr[right_index--]=1;
		}
	}
	return;
}
//The Vulture and the little girl
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
		separate(arr,n);
		printArray(arr,n);
	}
	return 0;
}
