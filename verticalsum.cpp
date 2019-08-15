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
void verticalSumUtil(struct node* root,int hd,map<int,int>&Map)
{
	if(!root)
	{
		return;
	}
	verticalSumUtil(root->left,hd-1,Map);
	Map[hd]+=root->data;
	verticalSumUtil(root->right,hd+1,Map);
}
void verticalSum(struct node* root)
{
	if(!root)
	{
		return;
	}
	map<int,int> Map;
	map<int,int> :: iterator it;
	verticalSumUtil(root,0,Map);
	for(it=Map.begin();it!=Map.end();it++)
	{
		std::cout<<it->second<<" ";
	}
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
    std::cout<<"Vertical Sum"<<endl;
    verticalSum(root); 
    std::cout<<endl;
    return 0; 
} 
