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

int isIdentical(struct node* root1,struct node* root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	else
	{
		return(root1->data==root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
	}
}

int isSubtree(struct node* root1,struct node* root2)
{
	if((!root1 && !root2) &&(!root1))
	{
		return 1;
	}
	if(root2->data==root1->data)
	{
		return isIdentical(root1,root2);
	}
	return (isSubtree(root1->left,root2) || isSubtree(root1->right,root2));
}

int main()  
{  
    node *T = newNode(26);  
    T->right         = newNode(3);  
    T->right->right = newNode(3);  
    T->left         = newNode(10);  
    T->left->left     = newNode(4);  
    T->left->left->right = newNode(30);  
    T->left->right     = newNode(6);  
    
    node *S = newNode(10);  
    S->right     = newNode(6);  
    S->left     = newNode(4);  
    S->left->right = newNode(30);  
    if (isSubtree(T, S))  
        cout << "Yes"<<endl;  
    else
        cout << "No"<<endl;  
  
    return 0;  
}  
  
