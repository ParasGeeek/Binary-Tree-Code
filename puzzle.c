#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int puzzle_game(int arr[3][3])
{
	
}
int main()
{
	int t,i,j;
	int count;
	scanf("%d",&t);
	while(t--)
	{
		int arr[3][3];
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d",arr[i][j]);
			}
		}
		count=puzzle_game(arr);
		if(count>=1)
		{
			printf("%d",count);
		}
		else
		{
			count=-1;
			printf("%d",count);
		}
	}
	return 0;
}
