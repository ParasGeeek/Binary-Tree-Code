#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<deque>
#include<queue>
#include<algorithm>
#include<cmath>
#include<list>
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
	struct node* newnode=new node();
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
/*
struct node* lca(struct node* root,int n1,int n2)
{
	if(!root)
	{
		return NULL; 
	}
	if(root->data >= n1 && root->data<=n2)
	{
		return root;
	}
	else if(root->data>n1 && root->data>n2)
	{
		return lca(root->left,n1,n2);
	}
	else
	{
		return lca(root->right,n1,n2);
	}
}
*/

struct node* lca(struct node* root,int n1,int n2)
{
	if(!root)
	{
		return NULL;
	}
	if(root->data>n1 && root->data>n2)
	{
		return lca(root->left,n1,n2);
	}
	if(root->data<n1 && root->data<n2)
	{
		return lca(root->right,n1,n2);
	}
	return root;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		struct node* root=newNode(20);
		root->left = newNode(8);  
        root->right = newNode(22);  
        root->left->left = newNode(4);  
        root->left->right = newNode(12);  
        root->left->right->left = newNode(10);  
        root->left->right->right = newNode(14); 
        int n1,n2;
        std::cin>>n1>>n2;
        struct node *t=lca(root,n1,n2);
        std::cout<<t->data<<endl;
	}
	return 0;
}
