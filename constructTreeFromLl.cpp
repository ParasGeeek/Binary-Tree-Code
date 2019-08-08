#include<iostream>
#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>

using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct Lnode
{
	int data;
	struct Lnode* next;
};

void inorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		inorder(root->left);
		std::cout<<root->data<<" ";
		inorder(root->right);
	}
}
void push(struct Lnode** head_ref,int data)
{
	struct Lnode* L_node=new Lnode();
	L_node->data=data;
	if(!(*head_ref))
	{
		*head_ref=L_node;
	}
	L_node->next=(*head_ref);
	(*head_ref)=L_node;
}

struct node* newNode(int new_data)
{
	struct node* new_node=new node();
	new_node->data=new_data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

void buildTree(struct Lnode* head,struct node* root)
{
	queue<node*>q;
	if(!head)
	{
		root=NULL;
		return;
	}
	root=newNode(head->data);
	q.push(root);
	head=head->next;
	while(head)
	{
		struct node* parent=q.front();
		q.pop();
		struct node* leftChild=NULL,*rightChild=NULL;
		leftChild=newNode(head->data);
		head=head->next;
		q.push(leftChild);
		if(head)
		{
			rightChild=newNode(head->data);
			head=head->next;
			q.push(rightChild);
		}
		parent->left=leftChild;
		parent->right=rightChild;
	}
}

int main()
{
	int test;
	struct Lnode* head=NULL;
	struct node* root;
	std::cin>>test;
	while(test--)
	{
		int n,m,i;
		std::cin>>n;
		for(i=0;i<n;i++)
		{
			std::cin>>m;
			push(&head,m);
		}
		buildTree(head,root);
		inorder(root);
	}
	return 0;
}
