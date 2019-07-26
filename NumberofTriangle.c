#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int NumberofTriangle(int *arr,int n)
{
	int i,j,k;
	int sum=0;
	for(i=0;i<(n-2);i++)
	{
		j=i+1;
		k=j+1;
		while(j<(n-1) && k<n)
		{
			if(arr[i]+arr[j] > arr[k])
			{
				sum++;
				k++;
			}
			else
			{
				j++;
				k=j+1;
			}
		}
	}
	return sum;
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
		printf("%d\n",NumberofTriangle(arr,n));
	}
	return 0;
}
