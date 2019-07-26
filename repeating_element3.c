#include<stdio.h>
#include<stdlib.h>

void fre(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		if(arr[abs(arr[i])]<0)
		{
			printf("%d ",abs(arr[i]));
		}
		else
		{
			arr[abs(arr[i])]=-1*arr[abs(arr[i])];
		}
	}
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
		fre(arr,n);
		printf("\n");
	}
	return 0;
}
