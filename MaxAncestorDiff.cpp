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

int maxDiffUtil(struct node* root,int *res)
{
	if(!root)
	{
		return INT_MAX;
	}
	if(!root->left && !root->right)
	{
		return root->data;
	}
	int leftmin=maxDiffUtil(root->left,res);
	int rightmin=maxDiffUtil(root->right,res);
	int minimum=min(leftmin,rightmin);
	res=max(res,root->data-minimum);
	return min(minimum,root->data);
}
int maxDiff(struct node* root)
{
	int res=INT_MIN;
	maxDiffUtil(root,&res);
	return res;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		struct node* root; 
        root = newNode(8); 
        root->left = newNode(3); 
        root->left->left = newNode(1); 
        root->left->right = newNode(6); 
        root->left->right->left = newNode(4); 
        root->left->right->right = newNode(7); 
        root->right = newNode(10); 
        root->right->right = newNode(14); 
        root->right->right->left = newNode(13);
        std::cout<<maxDiff(root)<<endl;
	}
	return 0;
}
