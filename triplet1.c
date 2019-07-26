#include<stdio.h>
#include<stdlib.h>

int find_triplet(int arr[],int size,int sum)
{
	int left_index,right_index;
	//left_index=arr[1];
	int s;
	//right_index=arr[size-1];
	for(int i=0;i<size-2;i++)
	{
		left_index=i+1;
		right_index=size-1;
		while(left_index < right_index)
		{
			s=arr[i]+arr[left_index]+arr[right_index];
			if(s==sum)
			{
				return 1;
			}
			else if(s < sum)
			{
				left_index++;
			}
			else 
			{
				right_index--;
			}
		}
	}
	return 0;
}

int compare(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
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
		qsort(arr,n,sizeof(int),compare);
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
