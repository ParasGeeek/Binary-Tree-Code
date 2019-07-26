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
struct node* reverse(struct node* head)
{
	struct node* prev=NULL;
	current=head;
	struct node* next;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}
int main()
{
	int n,m;
	struct node* head=NULL;
	printf("Enter the number of nodes in the link list:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		head=push(head,m);
	}
	print_list(head);
	head=reverse(head);
	printf("\n");
	printf("Link list after reversing:\n");
	print_list(head);
	return 0;
}
		
