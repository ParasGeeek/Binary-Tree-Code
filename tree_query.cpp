#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<algorithm>
#include<list>
#include<map>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struc node* newnode=new node();
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node* construct_tree(int arr[],struct node* root,int i,int n)
{
	if(i<n)
	{
		struct node* root1=newNode(arr[i]);
		root=root1;
		root->left=construct_tree(arr,root->left,2*i+1,n);
		root->right=construct_tree(arr,root->right,2*i+2,n);
	}
	return root;
}

int main()
{
	int n,q;
	std::cin>>n>>q;
	int *arr=new int[n];
	int i;
	for(i=0;i<n;i++)
	{
		std::cin>>arr[i];
	}
	struct node* root,*temp;
	temp=construct_tree(arr,root,0,n);
	for(int j=1;j<=q;j++)
	{
		std::cin>>x>>y>>z;
		if(x==1)
		{
			tree_query(temp,y,z);
		}
		else if(x==2)
		{
			tree_query(temp,y,z);
		}
		else if(x==3)
		{
			std::cin>>k;
			tree_query(temp,k,y,z);
		}
	}
	return 0;
}
