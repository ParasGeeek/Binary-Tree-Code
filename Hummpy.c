#include<stdio.h>
#include<stdlib.h>

void hummpy(int *n,int *a,int *b,int *k)
{
	int i;
	int max_size=*n;
	int arr[max_size];
	for(i=0;i<max_size;i++)
	{
		scanf("%d",&arr[i]);
	}
	int count=0;
	int t=*k;
	i=0;
	while(count<t)
	{
		if(arr[i++]%*a==0 || arr[i++]%*b==0)
		{
			count++;
		}
		else
		{
			continue;
		}
	}
	if(count==t)
	{
		printf("Win");
	}
	else
	{
		printf("Loss");
	}
	return;
}

int main()
{
	int n,a,b,k;
	int t;
	printf("Enter the number of test cases:\n");
	scanf("%d\n",&t);
	while(t--)
	{
	   printf("Enter the number of problems:\n");
	   scanf("%d",&n);
	   printf("\n");
	   printf("Enter the value of a and b\n");
	   scanf("%d %d\t",&a,&b);
	   printf("How many problem do you want to solve:\n");
	   scanf("%d\n",&k);
	   hummpy(&n,&a,&b,&k);
	} 	
	return 0;
}
