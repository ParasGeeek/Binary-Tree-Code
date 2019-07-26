#include<stdio.h>
#include<stdlib.h>

void fre(int *arr,int n)
{
	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n+2];
		for(int i=0;i<n+2;i++)
		{
			scanf("%d",&arr[i]);
		}
		fre(arr,n+2);
	}
	return 0;
}

