#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<algorithm>
#include<list>
#include<map>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int new_data)
{
	struct node* new_node=new node();
	new_node->data=new_data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

void printAllDown(struct node* root,int key)
{
	if(!root)
	{
		return;
	}
	if(key==0)
	{
		std::cout<<root->data<<" ";
	}
	printAllDown(root->left,key-1);
	printAllDown(root->right,key-1);
}

int printkdistanceNode(struct node* root,struct node* target,int key)
{
	if(!root)
	{
		return -1;
	}
	if(root==target)
	{
		printAllDown(target,key);
		return 0;
	}
	
}

int main() 
{ 
    node * root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 
    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 
    node * target = root->left->right; 
    printkdistanceNode(root, target, 2); 
    return 0; 
}

