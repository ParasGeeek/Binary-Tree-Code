#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void printSpiral(struct node* root)
{
	int h=height(root);
	int i;
	int ltr=false;
	for(i=1;i<=h;i++)
	{
		printGivenLevel(root,i,ltr);
		ltr=~ltr;
	}
}

void printGivenLevel(struct node* root,int level,int ltr)
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
			if(ltr)
			{
				printGivenLevel(root->left,level-1,ltr);
				printGivenLevel(root->right,level-1,ltr);
			}
			else
			{
				printGivenLevel(root->right,level-1,ltr);
				printGivenLevel(root->left,level-1,ltr);
			}
		}
}

int height(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		int l=height(root->left);
		int r=height(root->right);
		if(l>r)
		{
			return (l+1);
		}
		else
		{
			return (r+1);
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
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int main()
{
	struct node* root=newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    printf("Spiral Order traversal of binary tree is \n"); 
    printSpiral(root); 
    return 0; 
} 
