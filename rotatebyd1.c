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

void rotatebyd(int arr[],int n,int d)
{
	int temp,i,j;
	for(i=0;i<d;i++)
	{
		temp=arr[0];
		for(j=0;j<n;j++)
		{
			arr[j]=arr[j+1];
			if(j==n-1)
			{
				arr[j]=temp;
			}
		}
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

