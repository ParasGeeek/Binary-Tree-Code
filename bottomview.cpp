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
	int hd;
	struct node* left;
	struct node* right;
	node(key)
	{
		data=key;
		node* left=NULL:
		node* right=NULL;
		hd=INT_MAX;
	}
};

struct node* newNode(int new_data)
{
	struct node* newnode=new node();
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void bottomView(struct node* root)
{
	if(!root)
	{
		return;
	}
	int hd=0;
	map<int,int>Map;
	queue<node *>q;
	root->hd=hd;
	q.push(root);
	while(!q.empty())
	{
		struct node* temp=q.front();
		q.pop();
		Map[hd]=temp->data;
		if(temp->left)
		{
			temp->left->hd=hd-1;
			q.push(temp->left);
		}
		if(temp->right)
		{
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}
	for(auto it=Map.begin();it!=Map.end();it++)
	{
		std::cout<<it->second<<" ";
	}
	return;
}

void preorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		std::cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main() 
{ 
    struct node *root = new node(20); 
    root->left = new node(8); 
    root->right = new node(22); 
    root->left->left = new node(5); 
    root->left->right = new node(3); 
    root->right->left = new node(4); 
    root->right->right = new node(25); 
    root->left->right->left = new node(10); 
    root->left->right->right = new node(14); 
    std::cout<<"Preorder Traversal of the above tree:\n";
    preorder(root);
    std::cout<<"\n";
    std::cout<<"Bottom view of the given binary tree :\n";
    bottomView(root); 
    return 0; 
} 
