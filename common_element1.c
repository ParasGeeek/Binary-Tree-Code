#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void common_element(int *arr1,int *arr2,int *arr3,int n1,int n2,int n3)
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2 && k<n3)//It will take same time compare to previous algo..but space complexity will be O(1)
	{
		if((arr1[i]==arr2[j]) && (arr2[j]==arr3[k]))
		{
			printf("%d ",arr1[i]);
			i++;
			j++;
			k++;
		}
		else if(arr1[i] < arr2[j])
		{
			i++;
		}
		else if(arr2[j] < arr3[k])
		{
			j++;
		}
		else
		{
			k++;
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
