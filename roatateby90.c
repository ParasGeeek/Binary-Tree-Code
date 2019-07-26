#include<stdio.h>
#include<stdlib.h>
#define R 4
#define C 4

void printArray(int arr[R][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void rotateby90(int arr[R][C])
{
	int i,j,k;
	for(i=0;i<R;i++)
	{
		for(j=0,k=C-1;j<k;j++,k--)
		{
			swap(&arr[i][j],&arr[i][k]);
		}
	}
	//Now I am going to transpose it.
	for(i=0;i<R;i++)
	{
		for(j=i;j<C;j++)
		{
			swap(&arr[i][j],&arr[j][i]);
		}
	}
	printArray(arr);
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int arr[R][C];
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		rotateby90(arr);
		printArray(arr);
	}
	return 0;
}
