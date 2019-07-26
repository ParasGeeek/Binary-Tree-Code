#include<stdio.h>
#include<stdlib.h>

int comparator(const void *p,const void *q)
{
	int l=*(const int *)p;
	int r=*(const int *)q;
	if((l&1) &&(r&1))
	{
		return (r-l);
	}
	if(!(l&1) && !(r&1))
	{
		return (l-r);
	}
	if(!(l&1))
	{
		return 1;
	}
	return -1;
}

void printArr(int arr[],int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("%d\t",arr[i]);
	}
}

int main()
{
	int arr[]={1,6,5,2,3,9,4,7,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	qsort((void*)arr,size,sizeof(arr[0]),comparator);
	printf("Output array is:\n");
	printArr(arr,size);
	return 0;
}
