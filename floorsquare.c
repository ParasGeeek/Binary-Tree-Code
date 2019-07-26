#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int floor_square(int x)
{
	if(x==0 || x==1)
	{
		return x;
	}
	int start=1,end=x,ans;
	while(start<=end)
	{
		int mid=(start+end)/2;
		
	}
}

int main()
{
	int x;
	printf("Enter the number:\n");
	scanf("%d",&x);
	printf("%d",floor_square(x));
	return 0;
}

