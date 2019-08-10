#include<iostream>
#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<algorithm>
#include<stack>
#include<cmath>
#include<set>
#include<map>
 
using namespace std;

struct node
{
	string data;
	struct node* left;
	struct node* right;
};

struct node* newNode(char new_ch)
{
	struct node* new_node=new node();
	new_node->ch=new_ch;
	new_ch->left=NULL;
	new_ch->right=NULL;
	return new_ch;
}

int eval(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	if(!root->left && !root->right)
	{
		return root->data;
	}
	int left_data=eval(root->left);
	int right_data=eval(root->right);
	if(root->data=='*')
	{
		return left_data*right_data;
	}
	else if(root->data=='-')
	{
		return left_data-right_data;
	}
	else if(root->data=='+')
	{
		return left_data+right_data;
	}
	return left_data/right_data;

}

int main()
{
	
    struct node* root = newNode("+");  
    root->left = newNode("*");  
    root->left->left = newNode("5");  
    root->left->right = newNode("4");  
    root->right = newNode("-");  
    root->right->left = newNode("100");  
    root->right->right = newNode("/");  
    root->right->right->left = newNode("20");  
    root->right->right->right = newNode("2");  
    std::cout << eval(root)<<endl;  
    return 0;  
}
