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

int level(struct node* root,struct node* key,int l)
{
	if(!root)
	{
		return 0;
	}
	if(root==key)
	{
		return l;
	}
	int level2=level(root->left,key,l+1);
	if(level2!=0)
	{
		return level2;
	}
	return level(root->right,key,l+1);
}

int isSibling(struct node* root,struct node* x,struct node* y)
{
	if(!root)
	{
		return 0;
	}
	if(root->left==x && root->right==y)
	{
		return 1;
	}
	isSibling(root->left,x,y);
	isSibling(root->right,x,y);
	return 0;
}

int isCousin(struct node* root,struct node* x,struct node* y)
{
	if(!root)
	{
		return 0;
	}
	if((level(root,x,1)==level(root,y,1)) &&(!isSibling(root,x,y)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main() 
{ 
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    struct node *Node1,*Node2; 
    Node1 = root->left->left; 
    Node2 = root->right->right; 
    if(isCousin(root,Node1,Node2))
    {
		std::cout<<"Both are cousine"<<endl;
	}
	else
	{
		std::cout<<"Both are not cousine"<<endl;
	} 
    return 0; 
} 
