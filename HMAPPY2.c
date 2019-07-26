#include<stdio.h>
#include<stdlib.h>

int HMAPPY2(int *arr1);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int arr[4];
		for(int i=0;i<4;i++)
		{
			scanf("%d",&arr[i]);
		}
		int c=HMAPPY2(arr);
		if(c==arr[3])
		{
			printf("Win");
		}
		else
		{
			printf("Looser");
		}
	}
	return 0;
}

int HMAPPY2(int *arr1)
{
	int arr2[4];
	for(int i=1;i<=4;i++)
	{
		scanf("%d",&arr2[i]);
	}
	int count=0;
	int i=0;
	while(i<4)
	{
		if(arr2[i]%arr1[1]==0 && arr2[i]%arr1[2]==0)
		{
			i++;
		}
		else if(arr2[i]%arr1[1]==0 && arr2[i]%arr1[2]!=0)
		{
			count++;
			i++;
		}
		else if(arr2[i]%arr1[1]!=0 && arr2[i]%arr1[2]==0)
		{
			count++;
			i++;
		}
		else
		{
			i++;
		}	
	}
	
	if(count>=arr1[3])
	{
		return count;
	}
	else
	{
		return 0;
	}
}
