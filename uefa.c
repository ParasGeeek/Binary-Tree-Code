#include<stdio.h>
#include<stdlib.h>
#define Max 100
struct ucl
{
	char str1[Max];
	int a;
	int b;
	char str2[Max];
};
struct ucl x[12];
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<12;i++)
		{
			scanf("%s %d %d %s\n",x[i].str1,x[i].a,x[i].b,x[i].str2);
		}
	}
	return 0;
}
