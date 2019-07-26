#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void common_element(int *arr1,int *arr2,int *arr3,int n,int m,int l)
{
	int i,j,k;
	int *arr=(int*)malloc(sizeof(int)*m);
	for(i=0;i<n;i++)
	{
		j=0;
		k=0;
		while(j<n)
		{
			if(arr1[i]==arr2[j])
			{
				arr[k++]=arr1[i];
				j++;
			}
			else
			{
				j++;
			}
		}
	}
	int size=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;i++)
	{
		j=0;
		while(j<l)
		{
			if(arr[i]==arr3[j])
			{
				printf("%d ",arr[i]);
				j++;
			}
			else
			{
				j++;
			}
		}
	}
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,l;
		scanf("%d %d %d",&n,&m,&l);
		int arr1[n],arr2[m],arr3[l];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr1[i]);
		}
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr2[j]);
		}
		for(int k=0;k<l;k++)
		{
			scanf("%d",&arr3[k]);
		}
		common_element(arr1,arr2,arr3,n,m,l);
	}
	return 0;
}
