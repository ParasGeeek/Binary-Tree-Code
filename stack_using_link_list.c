#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*top=NULL;
void push(int);
void pop();
void display();

int main()
{
	int choice,value;
	while(1)
	{
		printf("1.Push\n2.Pop\n3 display\n4. Exit\n");
		printf("Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the value to be insert:\n");
			scanf("%d",&value);
			push(value);
			break;
			case 2:pop();
			break;
			case 3:display();Find maximum in a stack in O(1) time and O(1) extra space

			break;
			case 4:exit(0);
			break;
			default:
			         printf("\nInvalid choice:");
			       
		}
		}
	}
	
void push(int value)
{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=value;
  if(top==NULL)
  {
	  newNode->next=NULL;
  }
  else
  {
	  newNode->next=top;
	  top=newNode;
	  printf("Node is inserted:\n");
  }
}

void pop()
{
	if(!top)
	{
		return;
	}
	else
	{
		struct Node* temp=top;
		printf("%d",top->data);
		printf("\n");
		top=temp->next;
	}
}

void display()
{
	if(!NULL)
	{
		return;
	}
	else
	{
		struct Node* temp=top;
		while(temp->next)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
		printf("%d--->NULL\n\n",temp->data);
	}
}

