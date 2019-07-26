#include<stdio.h>
#include<stdlib.h>

int lucky(int n);
int main()
{
	int t,n,i;
	scanf("%d",&t);
	int flag=0;
	while(t--)
	{
		scanf("%d",&n);
		int count=lucky(n);
		if(count==1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
    return 0;
}


int lucky(int n)
{
	static int counter=2;
	int next_position=n;
	if(counter>n)
	{
		return 1;
	}
	if(n%counter==0)
	{
		return 0;
	}
	next_position -=next_position/counter;
	counter++;
	return lucky(next_position);
}

