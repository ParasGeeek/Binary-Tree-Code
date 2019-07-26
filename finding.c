#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0,j=0,n=0,N=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d\n",&N);                     
		int* arr=(int*)malloc(sizeof(int)*(2*N+2));
		unsigned int xor=0;
		for(j=0;j<2*N+2;j++)
		{
			scanf("%d\n",&arr[j]);
			xor=xor^arr[j];
		}
		unsigned int right_most_bit_set=(xor)&~(xor-1);
		unsigned int a=0,b=0;
		for(j=0;j<2*N+2;j++)
		{
			if(arr[j]&right_most_bit_set)
			{
				a=a^arr[j];
			}
			else
			{
				b=b^arr[j];
			}
		}
		if(a<b)
		{
			printf("%d %d\n",a,b);
		}
		else
		{
			printf("%d %d\n",b,a);
		}
		free(arr);
	}
	return 0;
}
