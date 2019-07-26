#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct List{
	int data;
	struct List* next;
};

struct Queue
{
	int front,rear;
	int Size;
	struct node* array;
};

struct Queue* createQueue(int size)
{
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=-1;
	q->Size=size;
	q->array=(struct node**)malloc(sizeof(struct node*));
	int i;
	for(i=0;i<size;i++)
	{
		q->array[i]=NULL;
	}
}

void Enqueue(struct Queue* q,struct node* root)
{
	if(isFull(q))
	{
		return;
	}
	q->array[++q->rear]=root;
	if(isEmpty(q))
	{
		++q->front;
	}
}

struct node* Dequeue(struct Queue* q)
{
	if(isEmpty(q))
	{
		return NULL;
	}
	struct node* temp=q->array[q->front];
	if(hasOnlyOneItem(q))
	{
		q->front=q->rear=-1;
	}
	else
	{
		q->front++;
	}
	return temp;
}

int isEmpty(struct Queue* queue) 
{ 
    return queue->front == -1; 
} 
  
int isFull(struct Queue* queue) 
{ 
	 return queue->rear == queue->size - 1;
} 
  
int hasOnlyOneItem(struct Queue* q) 
{  
	return q->front==q->rear;
}

void push(struct List** head,int new_data)
{
	struct List* temp=(struct List*)malloc(sizeof(struct List));
	temp->data=new_data;
	temp->next=(*head);
	(*head)=temp;
}

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

struct node* ListToBT(struct node* root,struct List* head)
{
	struct Queue* q=createQueue(100);
	if(!head)
	{
		root=NULL;
		return NULL;
	}
	root=newNode(head->data);
	Enqueue(q,root);
	head=head->next;
	while(head)
	{
		struct node* parent=Dequeue(q);
		struct node* lc=NULL,*rc;
		lc=newNode(head->data);
		Enqueue(q,lc);
		head=head->next;
		if(head)
		{
			rc=newNode(head->data);
			Enqueue(q,rc);
			head=head->next;
		}
		parent->left=lc;
		parent->right=rc;
	}
	return root;
}
int main()
{
	struct List* head=NULL;
	push(&head,36);
	push(&head,30);
	push(&head,25);
	push(&head,15);
	push(&head,15);
	push(&head,12);
	push(&head,10);
	struct node* root;
	struct node* temp=ListToBT(root,head);
	printf("The Inorder Traversal of above Tree is given Below:\n");
	inorder(temp);
	return 0;
}
