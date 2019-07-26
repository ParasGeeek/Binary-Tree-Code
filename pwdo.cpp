#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define EPS 1e-9

void productPuzzle(int arr[],int n)
{
	long double sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+(long double)log10(arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout << (int)(EPS + pow((long double)10.00,sum-log10(arr[i]))) << " ";
	}
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
		productPuzzle(arr,n);
		printf("\n");
	}
	return 0;
}
