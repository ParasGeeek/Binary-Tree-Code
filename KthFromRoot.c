#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void inorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf(" %d",root->data);
		inorder(root->right);
	}
}

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void printKDistantUtil(struct node* root,int key,int level)
{
	if(!root)
	{
		return;
	}
	if(key==level)
	{
		printf("%d ",root->data);
	}
		printKDistantUtil(root->left,key,level+1);
		printKDistantUtil(root->right,key,level+1);
}

void printKDistant(struct node* root,int key)
{
	if(!root)
	{
		return;
	}
	else
	{
		printKDistantUtil(root,key,0);
	}
}

int main() 
{ 
  int key;
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  root->right->left = newNode(8);
  printf("Inorder Traversal of above tree is :\n");
  inorder(root);   
  printf("Enter the level of tree:\n");
  scanf("%d",&key);
  printKDistant(root,key);  
  return 0; 
} 
