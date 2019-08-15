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

int size(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	/*if(!root->left && !root->right)
	{
		return 1;
	}*/
	else
	{
		return(size(root->left)+1+size(root->right));
	}
}

int main()  
{  
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    std::cout<< "Size of the tree is: "<< size(root)<<endl;  
    return 0;  
}  
  
