#include<stdio.h>
#include<math.h>

void till_n(int *arr,int len);
int main()
{
	int n,i;
	printf("Enter the value of the n:\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int j=0;j<n;j++)
	{
		arr[j]=1;
	}
	int len=sizeof(arr)/sizeof(arr[0]);
	till_n(arr,len);
	return 0;
}

void till_n(int arr[],int len)
{
	int j=0,k;
    while(j<len)
    {
		if(arr[j]==1 && j>=2)
		{
			for(k=2;k<len;k++)
			{
				arr[j*k]=0;
			}
		}
		j++;
	}
	for(j=0;j<len;j++)
	{
		if(arr[j]==1)
		{
			printf("%d\t",j);
		}
	}
	return;
}
