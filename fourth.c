#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h> 

struct node
{
	int data;
	struct node* next;
};

struct node* current;
struct node* reverse(struct node*,struct node*);
bool compare(struct node*,struct node*,struct node*);
void count_loop(struct node*);
struct node* push(struct node*,int);
int count_node(struct node* head);

struct node* push(struct node *head,int new_data)
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

bool isPalindrome(struct node* head)
{
	int count=count_node(head);
	int n;
	bool res;
	struct node* prev=NULL;
	struct node* current=head;
	struct node* current1=NULL;
	if(count%2==0)
	{
		n=count/2;
		while(--n)
		{ 
			prev=current;
			current=current->next;
		}
		current1=reverse(current,prev);
		res=compare(head,current1,prev);
	}
	else
	{
			n=count/2+1;
			while(--n)
			{  
				prev=current;
				current=current->next;
			}
		current1=reverse(current,prev);
	    res=compare(head,current1,prev);
			
	}
	return res;
	
}
bool compare(struct node *head,struct node* current1,struct node* prev)
{
	struct node* head1=head;
	struct node* head2=current1;
	while((head1->data!=prev->data) && (head2->data!=prev->data))
	{ 
		if(head1->data==head2->data)
		{
			head1=head1->next;
		    head2=head2->next;
		}
		else
		{
			return 0;
		}
		
	}
}

struct node* reverse(struct node* head,struct node* prev1)
{
 struct node* temp=prev1;	
 struct node* current=head;
 struct node* next;
 while(current)
 {
	 next=current->next;
	 current->next=prev1;
	 prev1=current;
	 current=next;
 }
 temp->next=NULL;
 return prev1;	
}

int count_node(struct node* head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
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
	struct node* head=NULL;
	printf("Enter the number of nodes in link list:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		head=push(head,m);
	}
	print_list(head);
	printf("\n");
	isPalindrome(head)? printf("Yes"):printf("No");
	return 0;
}

	
