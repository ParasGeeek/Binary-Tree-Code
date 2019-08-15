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
struct node* balance_bst(int arr[],int strt,int end)
{
	if(strt>end)
	{
		return NULL;
	}
	struct node* root;
	int mid;
	mid=strt+(end-strt)/2;
	root=newNode(arr[mid]);
	root->left=balance_bst(arr,strt,mid-1);
	root->right=balance_bst(arr,mid+1,end);
	return root;
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

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		struct node* temp=balance_bst(arr,0,n-1);
		preorder(temp);
		std::cout<<"\n";
	}
	return 0;
}
