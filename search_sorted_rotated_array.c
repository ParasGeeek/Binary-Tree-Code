#include<stdio.h>
#include<stdlib.h>

int findPivot(int arr[],int low,int high)
{
	if(high<low)
	{
		return 0;
	}
	if(low==high)
	{
		return low;
	}
	int mid=(low+high)/2;
	
	if(mid < high && arr[mid]>arr[mid+1])
	{
		return mid;
	}
	
	if(mid>low && arr[mid]<arr[mid-1])
	{
		return (mid-1);
	}
	
	if(arr[low]>=arr[mid])
	{
		findPivot(arr,low,mid-1);
	}
	
	return findPivot(arr,mid+1,high);
}

int binarySearch(int arr[],int low,int high,int key)
{
	if(high<low)
	{
		return -1;
	}
	int mid=(low+high)/2;
	if(key==arr[mid])
	{
		return mid;
	}
	if(key>arr[mid])
	{
		binarySearch(arr,mid+1,high,key);
	}
	return binarySearch(arr,low,mid-1,key);
}

int pivotedBinarySearch(int arr[],int n,int key)
{
	int pivot=findPivot(arr,0,n-1);
	if(pivot==0)
	{
		return binarySearch(arr,0,n-1,key);
	}
	if(arr[pivot]==key)
	{
		return pivot;
	}
	if(arr[0]<=key)
	{
		return binarySearch(arr,0,pivot-1,key);
	}
	return binarySearch(arr,pivot+1,n,key);
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
		int key;
		scanf("%d",&key);
		//printf("Index of seached element is:\n");
		int index=pivotedBinarySearch(arr,n,key);
		printf("%d",index);
	}
	return 0;
}
