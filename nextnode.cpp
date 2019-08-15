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

void test(struct node* root,int key)
{
	struct node* x;
	struct node* y;
	if(!root)
	{
		return;
	}
	queue<node *>q;
	q.push(root);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(x->data==key)
		{
			y=q.front();
			q.pop();
			std::cout<<y->data<<" ";
		}
		else
		{
			if(root->left)
			{
				q.push(root->left);
			}
			if(root->right)
			{
				q.push(root->right);
			}
		}
	}
}

int main() 
{ 
    struct node *root = newNode(10); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->right->right = newNode(5); 
    root->left->left = newNode(8); 
    root->left->right = newNode(4); 
    int n,k;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
		std::cin>>k;
		test(root,k);
	}
    return 0; 
}
