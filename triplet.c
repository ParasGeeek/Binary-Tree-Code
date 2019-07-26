#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>

int find_triplet(int *arr,int n,int sum)
{
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(arr[i]+arr[j]+arr[k]==sum)
				{
					//printf("%d %d %d",arr[i],arr[j],arr[k]);
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sum;
		scanf("%d %d",&n,&sum);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		//scanf("%d",&sum);
		if(find_triplet(arr,n,sum)==1)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
