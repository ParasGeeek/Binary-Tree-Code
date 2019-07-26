#include<stdio.h> 
#include<stdlib.h> 

 

struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void leftViewUtil(struct node* root,int level,int *max_level)
{
	if(!root)
	{
		return;
	}
	else if(root)
	{
		if(*max_level<level)
		{
			printf("%d ",root->data);
			*max_level=level;
		}
		leftViewUtil(root->left,level+1,max_level);
		leftViewUtil(root->right,level+1,max_level);
	}
} 

void leftView(struct node* root)
{
	if(!root)
	{
		return;
	}
	int max_level=0;
	leftViewUtil(root,1,&max_level);
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
    struct node *root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 
    printf("Inorder Traversal of the above tree is:\n");
    inorder(root);
    printf("\n"); 
    leftView(root); 
    return 0;
}  
    
