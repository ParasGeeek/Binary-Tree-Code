#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i,flag=0;
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
