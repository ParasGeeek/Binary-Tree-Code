#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	struct node *left;
	struct node* right;
	int data;
};

void inorder(struct node *root)
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

int isFoldable_util(struct node* root1,struct node* root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	else if(!root2)
	{
		return 0;
	}
	else
	{
		return isFoldable_util(root1->left,root2->right) && isFoldable_util(root1->right,root2->left);
	}
}

int isFoldable(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		return isFoldable_util(root->left,root->right);
	}
}
struct node* newNode(int data)  
{  
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;  
}

int main(void)  
{  
    struct node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->right->left = newNode(4);  
    root->left->right = newNode(5);  
      
    if(isFoldable(root) == 1)  
    {  
        printf("Yes: Tree is foldable:\n");  
    }  
    else
    {  
        printf("No: Tree is not foldable:\n");
    }  
    return 0;  
}  
