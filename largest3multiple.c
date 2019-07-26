#include<stdio.h>
#include<stdlib.h>
#define Max 100

void sort_array(int *arr,int n)
{
	int count[Max]={0};
	int index=0;
	for(int i=0;i<n;i++)
	{
		count[arr[i]]++;
	}
	for(int j=0;j<Max;j++)
	{
		while(count[j])
		{
			arr[index++]=j;
			count[j]--;
		}
	}
}

void RemoveAndPrintArray(int *arr,int n,int ind1)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		if(i!=ind1)
		{
			printf("%d",arr[i]);
		}
	}
	return;
}

void RemoveAndPrint_Array(int *arr,int n,int ind1,int ind2)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		if(i!=ind1 && i!=ind2)
		{
			printf("%d",arr[i]);
		}
	}
	printf("\n");
	return;
}

void largest3multiple(int *arr,int n)
{
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	int rem=sum%3;
	sort_array(arr,n);
	if(rem==1)
	{
		int rem_1[2];
		rem_1[0]=-1,rem_1[1]=-1;
		for(i=0;i<n;i++)
		{
			if(arr[i]%3==1)
			{
				RemoveAndPrintArray(arr,n,i);
			}
			else if(arr[i]%3==2)
			{
				if(rem_1[0]==-1)
				{
					rem_1[0]=i;
				}
				if(rem_1[0]!=-1 && rem_1[1]==-1)
				{
					rem_1[1]=i;
				}
			}
		}
		if(rem_1[0]!=-1 && rem_1[1]!=-1)
		{
			RemoveAndPrint_Array(arr,n,rem_1[0],rem_1[1]);
		}
	}
	else if(rem==2)
	{
		int rem_1[2];
		rem_1[0]=-1,rem_1[1]=-1;
		for(i=0;i<n;i++)
		{
			if(arr[i]%3==2)
			{
				RemoveAndPrintArray(arr,n,i);
			}
			else if(arr[i]%3==1)
			{
				if(rem_1[0]==-1)
				{
					rem_1[0]=i;
				}
				if(rem_1[0]!=-1 && rem_1[1]==-1)
				{
					rem_1[1]=i;
				}
			}
		}
		if(rem_1[0]!=-1 && rem_1[1]!=0)
		{
			RemoveAndPrint_Array(arr,n,rem_1[0],rem_1[1]);
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
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		largest3multiple(arr,n);
	}
	return 0;
}
