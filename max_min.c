#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct pair
{
	int min;
	int max;
};

struct pair getminmax(int *arr,int len)
{
	struct pair minmax;
	int i=0;
	if(len%2==0)
	{
		if(arr[0]>arr[1])
		{
			minmax.max=arr[0];
			minmax.min=arr[1];
		}
		else
		{
			minmax.max=arr[1];
			minmax.min=arr[0];
		}
		i=2;
	}
	else
	{
		minmax.max=arr[0];
		minmax.min=arr[1];
		i=1;
	}
	while(i<len-1)
	{
		if(arr[i]>arr[i+1])
		{
			if(arr[i]>minmax.max)
			{
				minmax.max=arr[i];
			}
			if(arr[i+1]<minmax.min)
			{
				minmax.min=arr[i+1];
			}
		}
		else
		{
			if(arr[i+1]>minmax.max)
			{
				minmax.max=arr[i+1];
			}
		    if(arr[i]<minmax.min)
		    {
				minmax.min=arr[i];
			}
		}
		i=i+2;
	}
  return minmax;
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
	int size=sizeof(arr)/sizeof(arr[0]);
	struct pair minmax=getminmax(arr,size);
	printf("%d\t%d",minmax.max,minmax.min);
	return 0;
}
