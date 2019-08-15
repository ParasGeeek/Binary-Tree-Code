#include<stack>
#include<bits/stdc++.h>
#include <iostream>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struct node* newnode=new node();
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void printSpiral(struct node* root)
{
	if(!root)
	{
		return;
	}
	//struct node* temp;
	stack<node *>st1,st2;
	st1.push(root);
	while(!st1.empty() || !st2.empty())
	{
		while(!st1.empty())
		{
			struct node* temp=st1.top();
			st1.pop();
			std::cout<<temp->data<<" ";
			if(temp->right)
			{
				st2.push(temp->right);
			}
			if(temp->left)
			{
				st2.push(temp->left);
			}
		}
		while(!st2.empty())
		{
			struct node* temp=st2.top();
			st2.pop();
			std::cout<<temp->data<<" ";
			if(temp->left)
			{
				st1.push(temp->left);
			}
			if(temp->right)
			{
				st1.push(temp->right);
			}
		}
	}
	return;
}

int main() 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    printf("Spiral Order traversal of binary tree is \n"); 
    printSpiral(root); 
  
    return 0;
}
