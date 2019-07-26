#include<string.h>
#inlcude<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printZigZagConcat(string str,int n)
{
	if(n==1)
	{
		printf("%s",str);
		return;
	}
	string arr[n];
	int len=strlen(str);
	int row=0;
	bool down;
	for(i=0;i<len;i++)
	{
		arr[i]=str[i];
		if(row==n-1)
		{
			down=false;
		}
		else if(row==0)
		{
			down=true;
		}
		(down)?(row++):(row--);
	}
	for(i=0;i<n;i++)
	{
		printf("%s",arr[i]);
	}
	return;
}

int main()
{
	int Max;
	printf("Enter the value of the Max:\n");
	scanf("%d",&Max);
	string str[Max];
	scanf("%s",str);
	int k;
	scanf("%d",&k);
	return 0;
}
