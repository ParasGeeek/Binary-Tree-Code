#include<stdio.h>
#include<stdlib.h>

struct petrolPump
{
	int petrol;
	int distance;
};

int printTour(struct petrolPum arr[],int n)
{
	int start=0;
	int end=0;
	int curr_petrol=arr[start].petrol-arr[start].distance;
	while(start!=end || curr_petrol<0)
	{
		start=(start+1)%n;
		curr_petrol=arr[start].petrol-arr[start].distance;
	}
	end=start+1;
	curr_petrol=0;
	while(end!=start && curr_petrol>0)
	{
		curr_petrol=curr_petrol+arr[end].petrol-arr[end].distance;
		end=(end+1)%n;
	}
	return (start+1);
}

int main()
{
	struct petrolPump arr[]={{6,4},{3,6},{7,3}};
	int n=sizeof(arr)/sizeof(arr[0]);
	int start=printTour(arr,n);
	if(start==-1)
	{
		printf("No solution exists:\n");
	}
	else
	{
		printf("Starting petrol station is %d:\n",start);
	}
	return 0;
}
