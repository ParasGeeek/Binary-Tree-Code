#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int NumberofTriangle(int *arr,int n)
{
	int sum=0;
	int i,j,k;
	for(i=0;i<n-2;i++)
	{
		k=i+2;
		for(j=i+1;j<n-1;j++)
		{
			while(k<n && (arr[i]+arr[j]) > arr[k])
			{
				k++;
			}
			sum=sum+k-j-1;
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

