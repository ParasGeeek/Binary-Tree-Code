#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>

using namespace std;

class node
{
	public:
	int data;
	node *left;
	node* right;
};

node* newNode(int data)
{
	node* Node=new node();
	Node->left=NULL;
	Node->right=NULL;
	Node->data=data;
	return(Node);
}

int size(node *root)      // This is second logic....
{
	static int count=0;
	if(!root)
	{
		return 0;
	}
	else
	{
		size(root->left);
		count++;
		size(root->right);
	}
	return count;
}
/*
int size(node* root)       // This is first logic.....
{
	if(!root)
	{
		return 0;  
  
	}
	else
	{
		return (size(root->left)+1+size(root->right));
	}
}
*/
int main()  
{  
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    cout << "Size of the tree is " << size(root);  
    return 0;  
}  
  
