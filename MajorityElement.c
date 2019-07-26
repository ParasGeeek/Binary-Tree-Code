#include<stdio.h>
#include<stdlib.h>

void MajorityElement(int arr[],int n)
{
	int max_count=0;
	int flag=-1;
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(arr[j]==arr[i])
			{
				count++;
			}
		}
		if(count>max_count)
		{
			max_count=count;
			flag=i;
		}
	}
	if(max_count>n/2)
	{
		printf("%d\n",arr[flag]);
	}
	else
	{
		printf("Majority element not found:\n");
	}
}
//Time complexity is O(n^2);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
	    int arr[n];
		//for(int i=0;i<n;i++)
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
	    MajorityElement(arr,n);
	}
	return 0;
}
