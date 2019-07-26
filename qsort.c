#include<stdio.h>
#include<stdlib.h>

//int values[]={40,10,100,90,20,25};
int comparator(const void *a,const void *b)
{
	return (*(int *)a - *(int*)b);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int values[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&values[i]);
	}
	qsort(values,6,sizeof(int),comparator);
	for(i=0;i<n;i++)
	{
		printf("%d\t",values[i]);
	}
	return 0;
}
