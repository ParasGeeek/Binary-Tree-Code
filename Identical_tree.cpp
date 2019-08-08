#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<deque>
#include<algorithm>
#include<queue>

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

int isIdentical(struct node* root1,struct node* root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	if(root1 && root2 && (root1->data==root2->data))
	{
		int lres=isIdentical(root1->left,root2->left);
		if(lres==0)
		{
			return 0;
		}
		int rres=isIdentical(root1->right,root2->right);
		if(rres==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
    struct node* root1 = newNode(5); 
    struct node* root2 = newNode(5); 
    root1->left = newNode(3); 
    root1->right = newNode(8); 
    root1->left->left = newNode(2); 
    root1->left->right = newNode(4); 
  
    root2->left = newNode(3); 
    root2->right = newNode(8); 
    root2->left->left = newNode(2); 
    root2->left->right = newNode(4); 
  
    if (isIdentical(root1, root2)) 
        std::cout << "Yes"<<endl; 
    else
        std::cout << "No"<<endl; 
    return 0; 
}
