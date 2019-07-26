#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* current=NULL;
struct node* head1=NULL;
struct node* head2=NULL;

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

struct node* segregate(struct node* head)
{
	current=head;
	while(current)
	{
		if((current->data)%2==0)
		{
			head1=push(head,current->data);
		}
		else
		{
			head2=push(head,current->data);
		}
		current=current->next;
	}
	struct node* current1=NULL;
	current1=head1;
	while(current1->next)
	{
		current1=current1->next;
	}
	current1->next=head2;
	return head1;
}

void print_list(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}

int main()
{
	int i,m,n;
	struct node* head=NULL;
	struct node* head1=NULL;
	printf("Enter the number of nodes do you want to enter into link list:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		head=push(head,m);
	}
	printf("\n");
	printf("Link list Before applying function:\n");
	print_list(head);
	printf("\n");
	head1=segregate(head);
	printf("After applying our function:\n");
	print_list(head1);
	return 0;
}

