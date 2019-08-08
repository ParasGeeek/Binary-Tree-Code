#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<deque>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

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

int isSumTree(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	if(!root->left && !root->right)
	{
		return root->data;
	}
	int leftSum=isSumTree(root->left);
	int rightSum=isSumTree(root->right);
	if(leftSum==-1 || rightSum==-1)
	{
		return -1;
	}
	if(root->data==leftSum+rightSum)
	{
		return 2*(root->data);
	}
	return 1;
}

int main() 
{ 
    struct node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 
    if(isSumTree(root)) 
    {
		std::cout<<"Yes"<<endl;
	}
	else
	{
		std::cout<<"No"<<endl;
	}
    return 0; 
} 
