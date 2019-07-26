#include<stdlib.h>
#include<stdio.h>
struct Qnode
{
	int data;
	struct Qnode* next;
};
struct Queue
{
	struct Qnode *front,*rear;
};

struct Qnode* newNode(int k)
{
	struct Qnode* temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp->data=k;
	temp->next=NULL;
	return temp;
}
struct Queue *createQueue()
{
	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;
	return q;
}

void enQueue(struct Queue *q,int k)
{
	struct Qnode* temp=newNode(k);
	if(q->rear==NULL)
	{
		q->rear=q->front=temp;
		return;
	}
	q->rear->next=temp;
	q->rear=temp;
}

struct Qnode* deQueue(struct Queue* q)
{
	if(q->front==NULL)
	{
		return NULL;
	}
	struct Qnode* temp=q->front;
	q->front=q->front->next;
	free(temp);
	if(!q->front)
	{
		q->rear=NULL;
	}
	return temp;
}
int main()
{
	struct Queue *q=createQueue();
	int i,n,m;
	printf("Enter the number of nodes in queue");
	scanf("%d",&n);
	for(i=0;i,n;i++)
	{
		scanf("%d",&m);
		enQueue(q,m);
	}
	deQueue(q);
	deQueue(q);
	enQueue(q,10);
	enQueue(q,25);
	enQueue(q,45);
	struct Qnode *n=deQueue(q);
	if(n!=NULL)
	{
		printf("Dequeued item is %d",n->key);
	}
	return 0;
}
