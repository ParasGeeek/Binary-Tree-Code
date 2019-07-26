#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	return;
}

void next_greater(int *arr,int n)
{
	int smallest,x;
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i] > arr[i-1])
		{
			break;
		}
	}
	if(i==0)
	{
		printf("There is no such number exists:\n");
	}
	x=arr[i-1],smallest=i;
	for(int j=i+1;j<n;j++)
	{
		if(x<arr[j] && arr[smallest]>arr[j])
		{
			smallest=j;
		}
	}
	swap(&arr[i-1],&arr[smallest]);
	sort(arr+i,arr+n);
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
		next_greater(arr,n);
		printf("\n");
	}
	return 0;
}
