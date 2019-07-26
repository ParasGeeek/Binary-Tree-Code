#include<stdio.h>
#include<stdlib.h>

void missing_number(int *arr,int n)
{
    int x1=arr[0];
    int x2=1;
    for(int i=1;i<n;i++)
    {
        x1=x1^arr[i];
    }
    for(int j=2;j<=n+1;j++)
    {
        x2=x2^j;
    }
    printf("%d\n",x1^x2);
    return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    missing_number(arr,n);
	}
	return 0;
}
