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
*/
struct node* lca(struct node* root,int n1,int n2)
{
	if(!root)
	{
		return NULL;
	}
	if(root->data==n1 || root->data==n2)
	{
		return root;
	}
	struct node* left=lca(root->left,n1,n2);
	struct node* right=lca(root->right,n1,n2);
	if(left && right)
	{
		return root;
	}
	return left?left:right;
}

int dist(struct node* root,int k)
{
	if(!root)
	{
		return -1;
	}
	int distt=-1;
	if((root->data==k) ||(distt=dist(root->left,k))>=0 || (distt=dist(root->right,k))>=0)
	{
		return (distt+1);
	}
	return distt;
}

int findDistance(struct node* root,int n1,int n2)
{
	if(!root)
	{
		return 0;
	}
	struct node* temp=lca(root,n1,n2);
	//std::cout<<temp->data<<endl;
	int d1=dist(temp,n1);
	int d2=dist(temp,n2);
	return (d1+d2);
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
	struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8);
    int n1,n2;
    std::cin>>n1>>n2;
    std::cout<<findDistance(root,n1,n2)<<endl;
}
    return 0;
}
