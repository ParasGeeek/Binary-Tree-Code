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

void delete(struct node* head)
{   
	if(!head)
		return;	
	reverse(head);
	delete_less(head);
	reverse(head);
}
void reverse(struct node* head)
{
	struct node* prev=NULL;
	struct node* next;
	current=head;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
void delete_less(struct node* head)
{
	
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
	int x,y,k;
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
	printf("\n");
	head= delete(head);
	printf("After applying our function..We have:\n");
	printf("\n");
	print_list(head);
	return 0;
}
