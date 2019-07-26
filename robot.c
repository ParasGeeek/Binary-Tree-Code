#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 256
#define N 0
#define E 1
#define S 2
#define W 3

int isCircular(char *path)
{
	int x=0,y=0;
	int dir=N;
	for(int i=0;*(path+i);i++)
	{
		char move=path[i];
		if(move=='R')
		{
			dir=(N+1)%4;
		}
		else if(move=='L')
		{
			dir=(4+N-1)%4;
		}
		else
		{
			if(dir==N)
			{
				y++;
			}
			else if(dir==E)
			{
				x++;
			}
			else if(dir==S)
			{
				y--;
			}
			else
			{
				x--;
			}
			
		}
	}
	if(x==0&&y==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char str[Max];
	scanf("%s",str);
	if(isCircular(str))
	{
		printf("Yes:\n");
	}
	else
	{
		printf("No:\n");
	}
	return 0;
}
