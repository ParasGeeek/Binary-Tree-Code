#include<stdio.h>
#include<stdlib.h>

struct Qnode
{
	int data;
	struct Qnode* prev,*next;
};
struct Queue
{
	int count;
	unsigned numberOfFrames; 
	struct Qnode *front,*rear;
};

struct Hash
{
	int capacity;
	struct Qnode** arr;
};

struct Qnode* newNode(int new_data)
{
	struct Qnode* temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp->data=new_data;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

struct Queue* createQueue(int numberOfFrames)
{
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->numberOfFrames=numberOfFrames;
	q->count=0;
	q->front=NULL;
	q->rear=NULL;
	return q;
}

struct Hash* createHash(int capacity)
{
	struct Hash* hash=(struct Hash*)malloc(sizeof(struct Hash));
	hash->capacity=capacity;
	hash->arr=(struct Qnode**)malloc(hash->capacity*sizeof(struct Qnode*));
	int i;
	for(i=0;i<hash->capacity;i++)
	{
		hash->arr[i]=NULL;
	}
	return hash;
}
int AreAllFramesFull( Queue* queue ) 
{ 
    return queue->count == queue->numberOfFrames; 
} 
int isQueueEmpty( Queue* queue ) 
{ 
    return queue->rear == NULL; 
}
void deQueue( Queue* queue ) 
{ 
    if( isQueueEmpty( queue ) ) 
        return; 
    if (queue->front == queue->rear) 
        queue->front = NULL;  
    QNode* temp = queue->rear; 
    queue->rear = queue->rear->prev; 
  
    if (queue->rear) 
        queue->rear->next = NULL; 
  
    free( temp ); 
    queue->count--; 
} 
void Enqueue(struct Queue* q,struct Hash* h,unsigned pageNumber)
{
	if(AreAllFramesFull(queue))
	{
		hash->arr[q->rear->pageNumber]=NULL;
		deQueue(q);
	}
	struct Qnode* temp=newNode(pageNumber);
	temp->next=q->front;
	if(isQueueEmpty(q))
	{
		q->rear=q->front=temp;
	}
	else
	{
		q->front->prev=temp;
		q->front=temp;
	}
	hash->arr[pageNumber]=temp;
	q->count++;
}

void Fifo(struct Queue* q,struct Hash* hash,int pageNumber)
{
	struct Qnode* reqPage=hash->arr[pageNumber];
	if(!reqPage)
	{
		enQueue(q,hash,pageNumber);
	}
	
}
#define MAX1 5;
#define MAX2 10;

int main()
{
	struct Queue* q=createQueue(MAX1);
	struct Hash* hash=createHash(MAX2);
	int i,n,m;
	printf("How many times do you want to enter string into queue:\n");
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		Fifo(q,hash,m);
	}
	display(hash);
	printf("\n");
	printf("Alternate way to print Node:\n");
	printf("%d\t",q->front);
	printf("%d\t",q->front->next);
	printf("%d\t",q->front->next->next);
	printf("%d",q->front->next->next->next);
	return 0;
}
