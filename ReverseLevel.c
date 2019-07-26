#include <stdio.h> 
#include <stdlib.h> 


struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

int height(struct node* root) 
{ 
    if (!root) 
        return 0; 
    else
    { 
        int lheight = height(root->left); 
        int rheight = height(root->right); 
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
} 

void reverseLevelOrder(struct node* root)
{
	if(!root)
	{
		return;
	}
	int i,h;
	h=height(root);
	for(i=h;i>=1;i--)
	{
		reverseLevelOrderUtil(root,i);
	}
}

void reverseLevelOrderUtil(struct node* root,int level)
{
	if(!root)
	{
		return;
	}
	if(level==1)
	{
		printf("%d ",root->data);
	}
	else if(level>1)
	{
		reverseLevelOrderUtil(root->left,level-1);
		reverseLevelOrderUtil(root->right,level-1);
	}
}

struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*) 
                        malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    printf("Reverse Level Order traversal of binary tree is \n"); 
    reverseLevelOrder(root);   
    return 0; 
} 
