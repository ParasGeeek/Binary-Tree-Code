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

int height(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	int l=height(root->left);
	int r=height(root->right);
	if(l>r)
	{
		return (l+1);
	}
	else
	{
		return (r+1);
	}
}

void printKDistantfromLeafUtil(struct node* root,int path[],bool visited[],int pathlen,int k)
{
	if(!root)
	{
		return;
	}
	path[pathlen]=root->data;
	pathlen++;
	visited[pathlen]=false;
	if((!root->left && !root->right) &&(visited[pathlen-k-1]==false && pathlen-k-1>=0))
	{
		std::cout<<path[pathlen-k-1]<<" ";
		visited[pathlen-k-1]=true;
	}
	printKDistantfromLeafUtil(root->left,path,visited,pathlen+1,k);
	printKDistantfromLeafUtil(root->right,path,visited,pathlen+1,k);
}

void printKDistantfromLeaf(struct node* root,int k)
{
	if(!root)
	{
		return;
	}
	int n=height(root);
	bool visited[n]={false};
	int path[n];
	//memset(visited,false,sizeof(visited));
	printKDistantfromLeafUtil(root,path,visited,0,k);
}

int main() 
{
    struct node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    cout << "Nodes at distance 2 are: "; 
    printKDistantfromLeaf(root, 2); 
  
    return 0; 
} 
