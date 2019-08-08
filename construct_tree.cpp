#include<iostream>
#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<stack>
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

void preorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	std::cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int search(int in[],int iIndex,int eIndex,int key)
{
	int i;
	for(i=0;i<=eIndex;i++)
	{
		if(key==in[i])
		{
			break;
		}
	}
	return i;
}

struct node* uniqTreeUtil(int in[],int post,int sIndex,int eIndex,int *index)
{
	if(sIndex>eIndex)
	{
		return NULL;
	}
	struct node* root=newNode(post[*index]);
	(*index)--;
	if(sIndex==eIndex)
	{
		return root;	
	}
	int iIndex=search(in,iIndex,eIndex,root->data);
	root->left=uniqTreeUtil(in,post,sIndex,iIndex-1,index);
	root->right=uniqTreeUtil(in,post,iIndex+1,eIndex,index);
	return root;
}

struct node* uniqTree(int in[],int post[],int n)
{
	int index=n-1;
	return uniqTreeUtil(in,post,0,n-1,index);
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		struct node* root;
		int n,i;
		std::cin>>n;
		int *arr1=new int[n];
		int *arr2=new int[n];
		for(i=0;i<n;i++)
		{
			std::cin>>arr1[i];
		}
		for(int j=0;j<n;j++)
		{
			std::cin>>arr2[j];
		}
		root=uniqTree(arr1,arr2,n);
		preorder(root);
	}
	return 0;
}

/*
int find(int* in,int key,int s,int e)
{
    for(int i=e;i>=s;i--)
    {
        if(in[i]==key) return i;
    }
}

Node* getNode(int x)
{
    Node* temp = (Node*)malloc(sizeof(Node*));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

Node* build(int* in,int* post,int start,int end,int& id)
{
    if(id<0 || start>end) return NULL;
    int key = post[id--];
    int idx = find(in,key,start,end);
    Node* root = getNode(in[idx]);
    root->right = build(in,post,idx+1,end,id);
    root->left = build(in,post,start,idx-1,id);
    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    int id = n-1;
    Node* root = build(in,post,0,n-1,id);
    return root;
}
*/
