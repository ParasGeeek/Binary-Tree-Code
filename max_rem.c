#include<stdio.h>
#include<stdlib.h>

int maxrem(int *arr)
{
	int len=sizeof(arr)/sizeof(arr[0]);
	return arr[len-3];
}

int comparator(const void *a,const void *b)
{
	return (*(int *)a - *(int*)b);
}

int main()
{
	int t;
	int n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[n];
		printf("Array elements are like:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int len=sizeof(arr)/sizeof(arr[0]);
	    qsort(arr,len,sizeof(int),comparator);
	    for(int j=0;j<len;j++)
	    {
			printf("%d\t",arr[j]);
		}
		printf("\n");
		int count=maxrem(arr);
		if(count>=1)
		{
			printf("%d",count);
		}
		else
		{
			count=-1;
			printf("%d",count);
		}
	}
	return 0;
}
