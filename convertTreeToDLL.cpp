#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struct node* new_node=new node();
	new_node->data=new_data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

void printList(struct node* head)
{
	while(head)
	{
		std::cout<<head->data<<" ";
		head=head->next;
	}
	return;
}

void bintree2list(struct node* root,struct node** head)
{
	if(!root)
	{
		return;
	}
	static node* prev=NULL;
	bintree2list(root->left);
	if(!prev)
	{
		*head=root;
	}
	else
	{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	bintree2list(root->right);
}

int main()  
{  
    struct node *root = newNode(10);  
    root->left = newNode(12);  
    root->right = newNode(15);  
    root->left->left = newNode(25);  
    root->left->right = newNode(30);  
    root->right->left = newNode(36);
    struct node* head=NULL;    
    bintree2list(root,&head);  
    printList(head);  
    return 0;  
}
