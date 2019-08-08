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

int toSumTree(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	int prev=root->data;
	int leftSum=toSumTree(root->left);
	int rightSum=toSumTree(root->right);
	root->data=leftSum+rightSum;
	return prev+root->data;
}
void printInorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		printInorder(root->left);
		std::cout<<root->data<<" ";
		printInorder(root->right);
	}
}
int main()  
{  
    struct node *root = NULL;  
    int x;  
    root = newNode(10);  
    root->left = newNode(-2);  
    root->right = newNode(6);  
    root->left->left = newNode(8);  
    root->left->right = newNode(-4);  
    root->right->left = newNode(7);  
    root->right->right = newNode(5);  
    std::cout<<toSumTree(root)<<endl;;    
    std::cout<<"Inorder Traversal"<<endl;
    printInorder(root);  
    return 0;  
}  
