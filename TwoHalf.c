#include<stdio.h>
#include<stdlib.h>

struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
int res=0;

struct Node* newNode(int x) 
{ 
    struct Node* temp = new Node; 
    temp->data = x; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void check(struct node* root)
{
	if(!root)
	{
		return;
	}
	int n=size(root);
	return(checkUtil(root,n,res))
}
int checkUtil(struct node* root,int n,int res)
{
	if(!root)
	{
		return  0;
	}
	int c=checkUtil(root->left,n,res)+1+checkUtil(root->right,n,res);
	if(c=n-c)
	{
		res=1;
		return c;
	}
}
int main() 
{ 
    struct Node* root = newNode(5); 
    root->left = newNode(1); 
    root->right = newNode(6); 
    root->left->left = newNode(3); 
    root->right->left = newNode(7); 
    root->right->right = newNode(4); 
  
    check(root)?  printf("YES") : printf("NO"); 
  
    return 0; 
} 
