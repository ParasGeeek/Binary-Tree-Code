#include<stdio.h>
#include<stdlib.h>

struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 

struct node *newNode(int key) 
{ 
    struct node *temp =(struct node*)malloc(sizeof(struct node)); 
    temp->data  = key; 
    temp->left  = temp->right = NULL; 
    return temp; 
}

int isMirror(struct node* root1,struct node* root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	if(root1 && root2 && root1->data==root2->data)
	{
		return (isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left));
	}
	return 0;
}

int isSymmetric(struct node* root)
{
	return isMirror(root,root);
}
int main() 
{ 
    struct node *root        = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(2); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left  = newNode(4); 
    root->right->right = newNode(3); 
  
    int count=isSymmetric(root);
    if(count)
    {
		printf("Yes:\n");
	} 
	else
	{
		printf("No:\n0");
	}
    return 0; 
}
