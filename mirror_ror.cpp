#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<map>
#include<list>
#include<algorithm>
#include<stack>
#include<deque>
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
    struct node* newnode=new node();
    newnode->data=new_data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void search(struct node* root,int key,struct node** temp)
{
    if(!root)
    {
        return;
    }
    if(root->data==key)
    {
        *temp=root;
    }
    search(root->left,key,temp);
    search(root->right,key,temp);
}

int mirror(struct node* root1,struct node* root2,int val)
{
    if(!root1 || !root2)
    {
        return -1;
    }
    if(root1->data==val)
    {
        return root2->data;
    }
    if(root2->data==val)
    {
        return root1->data;
    }
    int level2=mirror(root1->left,root2->right,val);
    if(level2!=-1)
    {
        return level2;
    }
    return mirror(root1->right,root2->left,val);
}

int main()
{
    int n,q;
    std::cin>>n>>q;
    int father,child,i,val;
    char ch;
    struct node* root,*temp;
    root=newNode(1);
    for(i=0;i<n-1;i++)
    {
        std::cin>>father>>child>>ch;
        search(root,father,&temp);
        if(ch=='L')
        {
            temp->left=newNode(child);
        }
        else
        {
            temp->right=newNode(child);
        }
    }
    for(i=0;i<q;i++)
    {
        std::cin>>val;
        std::cout<<mirror(root,root,val)<<endl;
    }
    return 0;
}
