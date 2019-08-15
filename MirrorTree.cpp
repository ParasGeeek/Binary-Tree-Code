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
//This is main code of the above logic...

void mirror_r(struct node* root)
{
	struct node* temp;
	if(!root)
	{
		return;
	}
	mirror_r(root->left);
	mirror_r(root->right);
	temp=root->left;
	root->left=root->right;
	root->right=temp;
}

int main() 
{ 
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    std::cout<<"Prior Preorder traversal is::"<<endl;
    inorder(root);
    std::cout<<"\n";
    mirror_r(root);
    std::cout<<"Inorder Traversal of above tree is:"<<endl;
    inorder(root);
    return 0;
}
