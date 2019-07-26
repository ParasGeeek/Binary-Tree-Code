#include<stdio.h>
#include<stdlib.h>

int tp=-1;
int stack[100];
int isEmpty(int *stack);
int top(int *stack);
void push(int *stack,int);
int pop(int *stack);
void sortedInsert(int *stack,int temp);

int isEmpty(int *stack)
{
	if(tp==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int top(int *stack)
{
	return stack[tp];
}

void push(int *stack,int item)
{
	stack[tp++]=item;
}

int pop(int *stack)
{
	int item;
	if(isEmpty(stack))
	{
		return 0;
	}
	else
	{
		item=stack[tp--];
	}
	return item;
}

void sort_stack(int *stack)
{
    int temp;
	if(!isEmpty(stack))
	{
		temp=pop(stack);
		sort_stack(stack);
		sortedInsert(stack,temp);
	}
}

void sortedInsert(int *stack,int temp)
{
	if(!isEmpty(stack) || temp > top(stack))
	{
		push(stack,temp);
	}
	else
	{
		temp=pop(stack);
		sortedInsert(stack,temp);
		push(stack,temp);
	}
}

int main()
{
	int m,Max;
	scanf("%d",&Max);
	for(int i=0;i<Max;i++)
	{
		scanf("%d",&m);
		push(stack,m);
	}
	sort_stack(stack);
	printf("Top element of the stack is %d:\n",pop(stack));
	return 0;
}

