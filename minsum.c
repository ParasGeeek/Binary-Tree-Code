#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define Max 9999

int notpossibleminsum(int *arr,int n)
{
	int p=1,i=0;
	while(i<n)
	{
		if(p < arr[i])
		{
			return p;
		}
		else
		{
			p=p+arr[i];
			i++;
		}
	}
	return 0;
}

int compare(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
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
		qsort(arr,n,sizeof(int),compare);
		printf("%d\n",notpossibleminsum(arr,n));
	}
	return 0;
}
