#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int key)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int isIdentical(struct node *root1,struct node* root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	else if(!root1 && root2)
	{
		return 0;
	}
	else if(root1 && !root2)
	{
		return 0;
	}
	else 
	{
		if(root1->data == root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}



void inorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
	return;
}

int isSubtree(struct node* root1,struct node* root2)
{
	if(!root1)
	{
		return 0;
	}
	if(!root2)
	{
		return 0;
	}
	if(isIdentical(root1,root2))
	{
		return 1;
	}
	else
	{
		return isSubtree(root1->left,root2) || isSubtree(root1->right,root2);
	}
}

int main() 
{ 
    struct node *T        = newNode(26); 
    T->right              = newNode(3); 
    T->right->right       = newNode(3); 
    T->left               = newNode(10); 
    T->left->left         = newNode(4); 
    T->left->left->right  = newNode(30); 
    T->left->right        = newNode(6); 
    struct node *S    = newNode(10); 
    S->right          = newNode(6); 
    S->left           = newNode(4); 
    S->left->right    = newNode(30); 
  
  
    if (isSubtree(T, S)) 
        printf("Tree 2 is subtree of Tree 1:\n"); 
    else
        printf("Tree 2 is not a subtree of Tree 1"); 
    return 0; 
} 
