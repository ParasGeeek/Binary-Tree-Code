#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct HeadNode
{
	int hd;
	struct entry* list;
	struct HeadNode* left,*right;
};

struct entry
{
	int data;
	struct entry* next;
};

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

struct HeadNode* BuildDLL(struct node* root,struct HeadNode* head)
{
	struct entry *e=(struct entry*)malloc(sizeof(struct entry));
	e->data=root->data;
	e->next=head->list;
	head->list=e;
	if(root->left)
	{
		if(!head->left)
		{
			head->left=newHeadNode(hd-1);
			head->left->right=head;
		}
		BuildDLL(root->left,head->left);
	}
	if(root->right)
	{
		if(!head->right)
		{
			head->right=newHeadNode(hd+1);
			head->right->left=head;
		}
		BuildDLL(root->right,head->right);
	}
}

struct HeadNode* newHeadNode(int new_data)
{
	struct HeadNode* temp=(struct HeadNode*)malloc(sizeof(struct HeadNode));
	temp->hd=new_data;
	temp->left=NULL;
	temp->right=NULL;
	temp->
}
