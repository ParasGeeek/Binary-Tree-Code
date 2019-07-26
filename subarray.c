#include<stdio.h>
#include<stdlib.h>

void subArraySum(int arr[], int n, int sum) 
{ 
    int curr_sum = arr[0], start = 0, i; 
    for (i = 1; i <= n; i++) 
    { 
        while (curr_sum > sum && start < i-1) 
        { 
            curr_sum = curr_sum - arr[start]; 
            start++; 
        } 
        if (curr_sum == sum) 
        { 
            printf("%d %d",start,i-1); 
            //return 1; 
        } 
        if (i < n) 
         curr_sum = curr_sum + arr[i]; 
    } 
    printf("-1");
    return; 
} 
  
int main()
{
	int t,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&sum);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		subArraySum(arr,n,sum);
		printf("\n");
	}
	return 0;
}
