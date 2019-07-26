#include<stdio.h>
#include<stdlib.h>

void change(int*,int y);
int main()
{
	int a=10,b=20;
	change(&a,b);
	printf("\n");
	printf("%d\t%d",a,b);
	return 0;
}
void change(int *x,int y)
{
	printf("Previous value before function is:\n");
	printf("%d\t%d",*x,y);
	(*x)++;
	y++;
	printf("\n");
	printf("New Value is given as below:\n");
	printf("%d\t%d",*x,y);
	return;
}
