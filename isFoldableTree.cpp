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

int isFoldableUtil(struct node* root1,struct node* root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	if(!root1 || !root2)
	{
		return 0;
	}
	return(isFoldableUtil(root1->left,root2->right) && isFoldableUtil(root1->right,root2->left));
}

int isFoldable(struct node* root)
{
	if(!root)
	{
		return 1;
	}
	return(isFoldableUtil(root->left,root->right));
}

int main(void) 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->right->left = newNode(4); 
    root->left->right = newNode(5); 
    if (isFoldable(root) == 1) 
    { 
        std::cout << "Yes"<<endl; 
    } 
    else 
    { 
        cout <<"No"<<endl; 
    } 
    return 0; 
} 
  
