#include<stdio.h>
#include<stdlib.h>

int EquilibriumIndex(int *arr,int n)
{
	int i,j;
	int equi_index=0;
	int *left_sum=(int*)malloc(sizeof(int)*n);
	int *right_sum=(int*)malloc(sizeof(int)*n);
	left_sum[0]=arr[0];
	right_sum[n-1]=arr[n-1];
	for(i=1;i<=n-1;i++)
	{
		left_sum[i]=left_sum[i-1] + arr[i];
	}
	for(j=n-2;j>=0;j--)
	{
		right_sum[j]=right_sum[j+1] + arr[j];
	}
	for(i=0;i<n-1;i++)
	{
		if(left_sum[i]==right_sum[i+1])
		{
			equi_index=i;
			break;
		}
	}
	return equi_index;
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
		printf("%d\n",EquilibriumIndex(arr,n));
		//printf("\n");
	}
	return 0;
}
