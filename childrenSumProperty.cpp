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

void increment(struct node* root,int diff)
{
	if(root->left)
	{
		root->left->data=root->left->data+diff;
		increment(root->left,diff);
	}
	else if(root->right)
	{
		root->right->data=root->right->data+diff;
		increment(root->right,diff);
	}
}

void convertTree(struct node* root)
{
	int diff;
	if(!root ||(!root->left && !root->right))
	{
		return;
	}
	convertTree(root->left);
	convertTree(root->right);
	int left_data=root->left->data;
	int right_data=root->right->data;
	diff=left_data+right_data - root->data;
	if(diff>0)
	{
		root->data=root->data+diff;
	}
	else if(diff<0)
	{
		increment(root,-diff);
	}
	return;
}

int main()  
{  
    struct node *root = newNode(50);  
    root->left = newNode(7);  
    root->right = newNode(2);  
    root->left->left = newNode(3);  
    root->left->right = newNode(5);  
    root->right->left = newNode(1);  
    root->right->right = newNode(30);  
    std::cout<<"Inorder Traversal"<<endl;
    printInorder(root); 
    convertTree(root); 
    std::cout<<endl;
    std::cout<<"Final Inorder Traversal"<<endl; 
    printInorder(root);  
    return 0;
}
