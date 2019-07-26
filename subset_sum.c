#include<stdio.h>
#include<stdbool.h>

bool isSubsetSum(int set[],int n,int sum)
{
   int i,j;
   bool subset[n+1][sum+1];
   for(i=0;i<=n;i++)
   {
	   subset[i][0]=0;
   }
   for(i=0;i<=n;i++)
   {
	   subset[0][i]=0;
   }
   for(i=0;i<=n;i++)
   {
	   for(j=0;j<=sum;j++)
	   {
		if( j<set[i-1])
		{
			subset[i][j]=subset[i-1][j];
		}  
		else
		{
			subset[i][j]=subset[i-1][j] || subset[i-1][j-set[i-1]];
		} 
	   }
   }
   return subset[n][sum];	
}

int main()
{
	int set[]={3,34,4,12,5,2};
	int sum=9;
	int n=sizeof(set)/sizeof(set[0]);
	if(isSubsetSum(set,n,sum)==true)
	{
		printf("Found subset of given subset:\n");
	}
	else
	{
		printf("No subset is found:\n");
	}
	return 0;
}

