#include<stdio.h>
#define Max 10
int main()
{
	int t,s,i;
	int flag=0;
	int sum=0;
	scanf("%d",&t);
	int arr1[Max];
	while(t--)
	{
		scanf("%d",&s);
		for(i=0;i<Max;i++)
		{
			scanf("%d",&arr1[i]);
		}
		for(i=0;i<Max;i++)
		{
			sum=0;
			for(int j=i;j<Max;j++)
			{
				sum=sum+arr1[j];
				if(sum==s)
				{
					printf("%d %d",i,j);
					flag=1;
					break;
				}
				else
				{
					continue;
				}
			}
		if (flag==1)
		break;
			
		}
	}
	return 0;
}
