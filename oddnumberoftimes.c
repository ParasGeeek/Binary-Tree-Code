#include<stdio.h>
#include<stdlib.h>

void oddnumberoftimes(int *arr,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum^arr[i];
	}
	printf("%d\n",sum);
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
	    oddnumberoftimes(arr,n);
	}
	return 0;
}
