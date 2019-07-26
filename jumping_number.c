#include<stdio.h>
#include<stdlib.h>

void jumping_number(int *);
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		jumping_number(&n);
	}
	return 0;
}

void jumping_number(int *n)
{
	int i,j,k;
	for(i=0;i<(*n);i++)
	{
		if(i<=10)
		{
			printf("%d\t",i);
		}
		else
		{
			j=0;
			while(i)
			{
				arr[j]=i%10;
				i=i/10;
				j++;
			}
			int *arr=(int *)malloc(j*sizeof(int));
			k=0;
			while(j--)
			{
				arr[k]=i%10;
				i=i/10;
				k++;
			}
			for(int m=0;m<k;m++)
			{
				if(arr[m]-arr[m+1]==1 || arr[m]-arr[m+1]==-1)
				{
					printf("%d\t",i);
				}
				else
				{
					break;
				}
			}
			free(arr);
		}
	}
	return;
}
