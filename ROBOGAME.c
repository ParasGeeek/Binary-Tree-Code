#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%s",&n);
		char str[n];
		scanf("%s",str);
		if(robogame(str,n))
		{
			printf("safe\n");
		}
		else
		{
			printf("unsafe");
		}
	}
}
int robogame(char str[],int n)
{
	
}
