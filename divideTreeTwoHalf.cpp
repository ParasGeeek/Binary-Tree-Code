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

int checkUtil(struct node* root,int size)
{
	if(!root)
	{
		return 0;
	}
	int flag=0;
	int count=checkUtil(root->left,size)+1+checkUtil(root->right,size);
	if(count=size-count)
	{
		flag=1;
		return flag;
	}
	else
	{
		checkUtil(root->left,size);
		checkUtil(root->right,size);
	}
	return flag;
}

int count(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	static int c=0;
	count(root->left);
	count(root->right);
	return c;
}

int check(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	int size=count(root);
	return checkUtil(root,size);
}

int main() 
{ 
    struct node* root = newNode(5); 
    root->left = newNode(1); 
    root->right = newNode(6); 
    root->left->left = newNode(3); 
    root->right->left = newNode(7); 
    root->right->right = newNode(4); 
    if(check(root))
    {
		std::cout<<"Yes"<<endl;
	}
	else
	{
		std::cout<<"No"<<endl;
	}
    return 0; 
} 
