#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100000

void isPairExist(int *arr,int n,int sum)
{
	int temp;
	int flag=0;
	bool s[MAX]={0};
	for(int i=0;i<n;i++)
	{
		temp=sum-arr[i];
		if(s[temp]==1)
		{
			flag=1;
			break;
		}
		else
		{
			s[arr[i]]=1;
		}
	}
	if(flag==1)
	{
		printf("YES\n");
	}
	
	else
	{
		printf("NO\n");
	}
	return;
}

int main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		isPairExist(arr,n,m);
	}
	return 0;
}
