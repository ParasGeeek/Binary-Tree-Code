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
	int left_height=height(root->left);
	int right_height=height(root->right);
	if(left_height>right_height)
	{
		return left_height+1;
	}
	else
	{
		return right_height+1;
	}
}

int diameter(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	static int max_diameter=0;
	int left_dia=height(root->left);
	int right_dia=height(root->right);
	if((left_dia+right_dia)>max_diameter)
	{
		max_diameter=left_dia+right_dia+1;
	}
	diameter(root->left);
	diameter(root->right);
	return max_diameter;
}

int main() 
{ 
  
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  printf("Diameter of the given binary tree is %d\n", diameter(root)); 
  getchar(); 
  return 0; 
} 
