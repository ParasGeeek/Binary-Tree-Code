#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void convert_binary(int *);
int main()
{
	int t;
	int n;
	printf("Enter the number of test cases:\n");
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%d",&n);
		convert_binary(&n);
	}
	return 0;
}
void convert_binary(int *a)
{
	int t,p,n,i=0;
	printf("size of array:\n");
	scanf("%d",&n);
	int arr[n];
	while(*a)
	{
		t=*a%2;
		arr[i]=t;
		i++;
		*a=*a/2;
	}
	//i=0;
	int count=0;
	for(int j=0;j<i;j++)
	{
		if(arr[j]==1)
		{
			count++;
		}
		else
		{
			continue;
		}
	}
	printf("%d",count);
	return;
}
