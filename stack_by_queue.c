#include<stdio.h>
#include<stdlib.h>
#define QUEUE_EMPTY_MAGIC 0xdeadbeef

struct queue
{
	int *arr;
	int rear,front,count,max;
};

struct queue *queue_allocation(int n);
void queue_insert(struct queue* q,int v);
int queue_remove(struct queue* q);
int queue_count(struct queue* q);
int queue_is_empty(struct queue* q);

void stack_push(struct queue* q,int v)
{
	queue_insert(q,v);
}

int stack_pop(struct queue* q)
{
	int i,n=queue_count(q);
	int removed_element;
	for(i=0;i<(n-1);i++)
	{
		removed_element=queue_remove(q);
		queue_insert(q,removed_element);
	}
	removed_element=queue_remove(q);
	return removed_element;
}

int stack_is_empty(struct queue* q)
{
	return queue_is_empty(q);
}

int stack_count(struct queue* q)
{
	return queue_count(q);
}
/*Simulated stack operation ends*/
/*Queue operation Start*/
int queue_count(struct queue* q)
{
	return q->count;
}
	
struct queue* queue_allocation(int n)
{
	struct queue* queue_t=(struct queue*)malloc(sizeof(struct queue));
	if(!queue_t)
	{
		return NULL;
	}
	queue_t->max=n;
	queue_t->arr=malloc(sizeof(int)*n);
	queue_t->rear=n-1;
	queue_t->front=n-1;
	return queue_t;
}

void queue_insert(struct queue* q,int v)
{
	if(q->count==q->max)
	{
		return;
	}
	q->rear=(q->rear+1) % q->max;
	q->arr[q->rear]=v;
	q->count++;
}

int queue_remove(struct queue* q)
{
	int retval;
	if(q->count==0)
	{
		return QUEUE_EMPTY_MAGIC;
	}
	q->front=(q->front+1) % q->max;
	retval=q->arr[q->front];
	q->count--;
	return retval;
}

int queue_is_empty(struct queue* q)
{
	return(q->count==0);
}

void queue_display(struct queue* q)
{
	int i=(q->front+1) % q->max,elements=queue_count(q);
	while(elements--)
	{
		printf("[%d]",q->arr[i]);
		i=(i>=q->max)?0:(i+1);
	}
}
#define MAX 128
int main()
{
	struct queue *q;
	int x,select;
	q=queue_allocation(MAX);
	do
	{
		printf("\n[1]Push\n[2]Pop\n[0] exit");
		printf("\nChoice:");
		scanf("%d",&select);
		switch(select)
		{
			case 1: printf("\nEnter the value to Push:\n");
			scanf("%d",&x);
			stack_push(q,x);
			printf("\n");
			queue_display(q);
			printf("\n\n Pushed Value:%d",x);
			printf("\n");
			break;
			case 2:
			x=stack_pop(q);
			printf("\n");
			queue_display(q);
			if(x==QUEUE_EMPTY_MAGIC)
			{
				printf("\n No values is removed");
			}
			else
			{
				printf("\nPopped Value:%d",x);
				printf("\n");
				break;
			}
			case 0:
			printf("\nQuitting.\n");
			return 0;
			default:
			printf("\n Quitting.\n");
			return 0;
		}
	}
		while(1);
	return 0;
}

