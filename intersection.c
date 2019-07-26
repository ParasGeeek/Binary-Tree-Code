#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* current=NULL;
void intersection(struct node* head1,struct node* head2);

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

void intersection(struct node* head1,struct node* head2)
{
	struct node* current1=head1;
	struct node* current2=head2;
	if(!current1 && !current2)
		return;
	if(!current1)
		return;	
	if(!current2)
	    return;
	while(current1 && current2)
	{
		if(current1->data==current2->data)
		{
			printf("%d\t",current1->data);
			current1=current1->next;
			current2=current2->next;
		}
		else
		{
			current1=current1->next;
			current2=current2->next;
		}
	}
	return;
}      
	
void print_list(struct node* head)
{
	while(head)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}

int main()
{
	int n,i,m;
	struct node* head1=NULL;
	struct node* head2=NULL;
	printf("Enter the number of vertex in first list:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		head1=push(head1,m);
	}
	int j,m1,n1;
	printf("\n");
	printf("Enter the number of vertex in second link list:\n");
	scanf("%d",&n1);
	for(j=0;j<n1;j++)
	{
		scanf("%d",&m1);
		head2=push(head2,m1);
	}
	printf("List before applying function:\n");
	print_list(head1);
	printf("\n");
	print_list(head2);
	printf("\n");
	intersection(head1,head2);
	return 0;
}
	
