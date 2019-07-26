#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	printf("Enter the number of the bits in string:\n");
	scanf("%d",&n);
	int *binary=convert_binary(n);
	for(int i=countBit(n)-1;i>=0;i--)
	{
		if(*(binary+i)==0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	printf("The Maximum Power of 2 is :%d",count);
	return 0;
}

int *convert_binary(int n)
{
	int count=CountBit(n);
	int arr[count];
	int i,j;
	if(n<0)
	{
		printf("Nothing man:\n");
	}
	else
	{
		while(n>0)
		{
			q=n/2;
			if(q!=0)
			{
				arr[count-1-i]=n%2;
				n=n/2;
				i++;
			}
		}
	}
	return arr;
}

int countBit(int n)
{
	int count=0;
	int i;
	if(n==0)
	{
		return 0;
	}
	else
	{
		for(i=0;i<32;i++)
		{
			if((1<<i)&n)
			{
				count=i;
			}
		}
	}
	return ++count;
}
