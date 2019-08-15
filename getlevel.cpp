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

int getLevelUtil(struct node* root,int key,int level)
{
	if(!root)
	{
		return 0;
	}
	if(root->data==key)
	{
		return level;
	}
	int level2=getLevelUtil(root->left,key,level+1);
	if(level2!=0)
	{
		return level2;
	}
	return getLevelUtil(root->right,key,level+1);
}

int getLevel(struct node* root,int key)
{
	if(!root)
	{
		return 0;
	}
	return getLevelUtil(root,key,1);
}

int main() 
{ 
    struct node *root = new struct node; 
    int x; 
    root = newNode(3); 
    root->left = newNode(2); 
    root->right = newNode(5); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
  
    for (x = 1; x <= 5; x++) 
    { 
        int level = getLevel(root, x); 
        if (level) 
        {
			std::cout<<"Level of "<<x<<" is"<<" "<<level<<endl;
		}
		else
		{
			std::cout<<"No level Exist"<<endl;
		}
    } 
    std::cout<<"\n";
    return 0; 
} 
