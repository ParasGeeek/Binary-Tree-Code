#include<stdio.h>
#include<stdlib.h>


int find_triplet(int *arr,int m)
{
	int i,j;
	int sum;
	for(i=0;i<n-1;i++)
	{
		for(j=2;j<m;j++)
		{
			sum=arr[i]+arr[i+1]+arr[j]
		}
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	int i,m,p;
	while(t--)
	{
		scanf("%d",&m);
		int *arr=(int*)malloc(sizeof(int)*m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&arr[i]);
		}
		p=find_triplet(arr,m);
		if(p==1)
		{
			printf("Yes:\n");
		}
		else
		{
			printf("No:\n");
		}
		free(arr);
	}
}
