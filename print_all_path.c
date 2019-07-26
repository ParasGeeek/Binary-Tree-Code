#include<stdio.h>
#include<stdlib.h>

void printArray(int path[],int len);
void printPathRecur(struct node* root,int path[],int path_len);

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void printArray(int path[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
	printf("%d\t",path[i]);	
	}
	printf("#");
	return;
}

void printPathRecur(struct node* root,int path[],int path_len)
{
	if(!root)
	{
		return;
	}
	else
	{
		path[path_len++]=root->data;
		if(!root->left && !root->right)
		{
			printArry(path,path_len);
		}
		printPathRecur(root->left,path,path_len);
		printPathRecur(root->right,path,path_len);
	}
}

void printPaths(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		int path[1000];
		printPathRecur(root,path,0);
	}
}

int main() 
{  
  struct node *root = newnode(10); 
  root->left        = newnode(8); 
  root->right       = newnode(2); 
  root->left->left  = newnode(3); 
  root->left->right = newnode(5); 
  root->right->left = newnode(2);    
  printPaths(root); 
  return 0; 
} 

