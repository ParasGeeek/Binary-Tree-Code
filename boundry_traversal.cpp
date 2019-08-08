#include<iostream>
#include<stack>
#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<cmath>
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
	struct node* temp=new node();
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp; 
}

void printLeftBoundry(struct node* root)
{
	if(root)
	{
		if(root->left)
		{
			std::cout<<root->data<<" ";
			printLeftBoundry(root->left);
		}
		else if(root->right)
		{
			std::cout<<root->data<<" ";
			printLeftBoundry(root->right);
		}
	}
}

void printLeaves(struct node* root)
{
	if(root)
	{
		printLeaves(root->left);
		if(!root->left && !root->right)
		{
			std::cout<<root->data<<" ";
		}
		printLeaves(root->right);
	}
}

void printRightBoundry(struct node* root)
{
	if(root)
	{
		if(root->right)
		{
			printRightBoundry(root->right);
			std::cout<<root->data<<" ";
		}
		else if(root->left)
		{
			printRightBoundry(root->left);
			std::cout<<root->data<<" ";
		}
	}
}

void printBoundary(struct node* root)
{
	if(root)
	{
		std::cout<<root->data<<" ";
		printLeftBoundry(root->left);
		printLeaves(root->left);
		printLeaves(root->right);
		printRightBoundry(root->right);
	}
}

int main() 
{ 
	int test;
	std::cin>>test;
	while(test--)
	{
    struct node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 
    printBoundary(root);
    std::cout<<"\n";
   } 
    return 0; 
} 
