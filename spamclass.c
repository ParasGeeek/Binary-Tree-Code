#include<stdio.h>
#include<stdlib.h>

void spamClass(int n,int min,int max)
{
	int w,b,res,t=1;
	int p;
	int count_even=0;
	int count_odd=0;
	int i;
	for(i=min;i<=max;i++)
	{
		res=t;
		p=n;
		while(p>0)
		{
			scanf("%d%d",&w,&b);
			res=res*w+b;
			p--;
		}
		if(res%2==0)
		{
			count_even++;
		}
		else
		{
			count_odd++;
		}
		t++;
	}
	printf("%d %d",count_even,count_odd);
	return;
}

int main()
{
	int t;
	long long int n,minX,maxX;
	printf("Enter the number of test cases:\n");
	scanf("%d",&t);
	while(t>0)
	{
		printf("Enter n ,minX and maxX:\n");
		scanf("%d %d %d",&n,&minX,&maxX);
		spamClass(n,minX,maxX);
		t--;
	}
	return 0;
}

