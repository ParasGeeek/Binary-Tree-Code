#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<deque>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

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
/*
void Inorder(struct node* root)    //Inorder Traversal of constructed tree....
{
	if(!root)
	{
		return;
	}
	else
	{
		Inorder(root->left);
		std::cout<<root->data<<" ";
		Inorder(root->right);
	}
}
*/
void verticalPrintUtil(struct node* root,int d,map<int,vector<int>>&hash_map)
{
	if(!root)
	{
		return;
	}
	hash_map[d].push_back(root->data);          //Basic C++ hash function ...very useful to solve above code..
	verticalPrintUtil(root->left,d-1,hash_map);
	verticalPrintUtil(root->right,d+1,hash_map);
}

void verticalPrint(struct node* root)
{
	map<int,vector<int>>hash_map;
	verticalPrintUtil(root,0,hash_map);
	//Now I am going to print the value of the each diagonal....
	for(auto i=hash_map.begin();i!=hash_map.end();++i)
	{
		for(int j=0;j<i->second.size();j++)
		{
			std::cout<<i->second[j]<<" ";
		}
	}
	return;
}

int main() 
{ 
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    verticalPrint(root); 
    return 0;
 }
