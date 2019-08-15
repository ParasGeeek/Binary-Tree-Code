#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<algorithm>
#include<list>
#include<map>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struc node* newnode=new node();
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

int main()
{
	int N, Q;
	string S;
	std::cin>>N>>Q;
	std::cin>>S;
	struct node* root;
	root=newNode(1);
	for(int i=0;i<N -1;i++)
	{
		int u, v;
		std::cin >> u >> v;
	    
	}
	while(Q --)
	{
		int u;
		char c;
		std::cin >> u >> c;
		// Process queries
	}
	return 0;
}
