#include<stdio.h>
#include<stdlib.h>

int findCandidate(int *arr,int n)
{
	int count=1;
	int maj_index=0;
	for(int i=1;i<n;i++)
	{
		if(arr[maj_index]==arr[i])
		{
			count++;
		}
		else
		{
			count--;
		}
		if(count==0)
		{
			maj_index=i;
			count=1;
		}
	}
	return(arr[maj_index]);
}

int isMajority(int arr[],int n,int k)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==k)
		{
			count++;
		}
	}
	if(count > n/2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void MajorityElement(int arr[],int n)
{
	int cand=findCandidate(arr,n);
	if(isMajority(arr,n,cand)==1)
	{
		printf("%d\n",cand);
	}
	else
	{
		printf("-1\n");
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
		//for(int i=0;i<n;i++)
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
	    MajorityElement(arr,n);
	}
	return 0;
}
