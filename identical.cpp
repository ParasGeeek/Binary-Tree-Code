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

int isIdentical(struct node* root1,struct node* root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	if(root1 && root2)
	{
		return((root1->data==root2->data)&&isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right));
	}
}

int main() 
{ 
    struct node* root1 = newNode(5); 
    struct node* root2 = newNode(5); 
    root1->left = newNode(3); 
    root1->right = newNode(8); 
    root1->left->left = newNode(2); 
    root1->left->right = newNode(4); 
    
    //Second Tree....
    root2->left = newNode(3); 
    root2->right = newNode(8); 
    root2->left->left = newNode(2); 
    root2->left->right = newNode(4); 
  
    if (isIdentical(root1, root2)) 
        std::cout << "Yes"<<endl; 
    else
        std::cout<< "No"<<endl; 
    return 0; 
} 
