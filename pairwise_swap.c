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

void print_list(struct node* head)
{
	current=head;
	while(current)
	{
		printf("%d\t",current->data);
		current=current->next;
	}
}
struct node* move(struct node* head)
{
	current=head;
	struct node* prev=NULL;
	while(current->next)
	{
		prev=current;
		current=current->next;
	}
	current->next=head;
	head=current;
	prev->next=NULL;
	return head;
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
	printf("Before Pairwise swapping:\n");
	print_list(head);
	head=move(head);
	printf("After applying our function..We have:\n");
	printf("\n");
	print_list(head);
	return 0;
}
