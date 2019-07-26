#include<stdio.h>
#include<stdlib.h>

//int isLeaf(struct node* root); 

struct node
{
	int data;
	struct node* left;
	struct node *right;
};

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int LeftSumTree(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	static int sum=0;
	if(isLeaf(root->left))
	{
		sum=sum+root->left->data;
	}
	if(root->left)
	{
		LeftSumTree(root->left);
	}
	if(root->right)
	{
		LeftSumTree(root->right);
	}
	return sum;
}

int isLeaf(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		if(!root->left && !root->right)
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
}

int main() 
{ 
    struct node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12); 
    printf("Tree is given below:\n");
    inorder(root);
    printf("Left Leaves Sum is given below:\n");
    printf("%d",LeftSumTree(root));
    return 0; 
}
