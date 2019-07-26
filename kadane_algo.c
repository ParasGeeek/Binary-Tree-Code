#include<stdio.h>
#include<stdlib.h>

void kadane_algo(int *arr,int n)
{
	/* This is Dynamic Paradism algorithm:....T(n)=O(n) */
	int max_so_far=0,max_ending_here=0;
	for(int i=0;i<n;i++)
	{
		max_ending_here=max_ending_here + arr[i];
		if(max_ending_here < 0)
		{
			max_ending_here=0;
		}
		if(max_so_far < max_ending_here)
		{
			max_so_far=max_ending_here;
		}
	}
	printf("%d\n",max_so_far);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int *arr=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		kadane_algo(arr,n);
	}
	return 0;
}
