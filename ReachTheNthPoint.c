#include <stdio.h>
#include<stdlib.h>


int n;
int CountWays(int);
int CountPossibleWays(int);
int main() 
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    printf("%d\n",CountWays(n));
	}
	return 0;
}
int CountWays(int n)
{   
	if(n==0 || n<0)
	{
		return 0;
	}
    return CountPossibleWays(n+1);
}
int CountPossibleWays(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
		return 0;
	}
    else 
    {
        return CountPossibleWays(n-1)+CountPossibleWays(n-2);
    }
}
