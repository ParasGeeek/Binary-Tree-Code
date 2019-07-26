#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int data;
	struct node* next;
};

struct node* current=NULL;

struct node* push(struct node* head,int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->next=NULL;
	if(!head)
	{
		head=temp;
	}
	else
	{
		current=head;
		while(current->next)
		{
			current=current->next;
		}
		current->next=temp;
	}
	return head;
}
/*
struct node* swap_nodes(struct node* head,int data1,int data2)
{
	struct node* temp1=(struct node*)malloc(sizeof(struct node));
	struct node* temp2=(struct node*)malloc(sizeof(struct node));
	temp1->data=data1;
	temp1->next=NULL;
	temp2->data=data2;
	temp2->next=NULL;
	struct node* current=head;
	//struct node* prev=NULL;
	if(data1==data2)
		return NULL;
		
	while(current->next)
	{
		if(current->next->data==temp1->data)
		{
			temp2->next=current->next->next;
			current->next=temp2;
			//free(prev);
		}
		else if(current->next->data==temp2->data)
		{
			temp1->next=current->next->next;
			current->next=temp1;
			//free(prev);
		}
		else
		{
			current=current->next;
			//prev=current;
		}
	}
	return head;
}
*/
struct node* swap_nodes(struct node* head,int x,int y)
{
	struct node* curx=head;
	struct node* cury=head;
	struct node* prevx=NULL;
	struct node* prevy=NULL;
	if(x==y)
		return NULL;
	while(curx && curx->data!=x)
	{
		prevx=curx;
		curx=curx->next;
	}
	while(cury && cury->data!=y)
	{
		prevy=cury;
		cury=cury->next;
	}	
	if(curx==NULL || cury==NULL)
		return NULL;
    if(prevx!=NULL)
		prevx->next=cury;
	else
		head=cury;	
	if(prevy!=NULL)
		prevy->next=curx;
	else
		head=curx;	
	struct node* temp=cury->next;
	cury->next=curx->next;
	curx->next=temp;
    return head; 		
}
void print_list(struct node* head)
{
	current=head;
	while(current)
	{
		printf("%d\t",current->data);
		current=current->next;
	}
}

int main()
{
	int n,m;
	int x,y;
	struct node* head=NULL;
	printf("Enter the number of nodes in the link list:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		head=push(head,m);
	}
	printf("Before Swapping nodes of link list are like below:\n");
	print_list(head);
	printf("\n");
	printf("Enter the nodes which are swapped:\n");
	scanf("%d\t%d",&x,&y);
	head=swap_nodes(head,x,y);
	printf("Nodes of link list after swapping:\n");
	print_list(head);
	return 0;
}
