#include<stdio.h>
#include<stdlib.h>

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

void inorder(struct node * root)
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

int getMaxWidth(struct node* root)
{
	if(!root)
	{
		return 1;
	}
	int max_width=0,max;
	int h=height(root);
	for(int i=1;i<=h;i++)
	{
		max=getMaxWidthUtil(root,i);
		if(max>max_width)
		{
			max_width=max;
		}
	}
	return max_width;
}

int height(struct node* root)
{
	int l,r;
	if(!root)
	{
		return 0;
	}
	else
	{
		l=height(root->left);
		r=height(root->right);
		if(l>r)
		{
			return(l+1);
		}
		else
		{
			return(r+1);
		}
	}
}

int getMaxWidthUtil(struct node* root,int level)
{
	if(!root)
	{
		return 0;
	}
	if(level==1)
	{
		return 1;
	}
	if(level>1)
	{
		return(getMaxWidthUtil(root->left,level-1)+getMaxWidthUtil(root->right,level-1));
	}
}

int main() 
{ 
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  root->right->right = newNode(8);     
  root->right->right->left  = newNode(6);     
  root->right->right->right  = newNode(7);  
  printf("Inorder traversal of above tree is:\n");
  inorder(root);
  printf("\n");      
  printf("Maximum width is %d \n", getMaxWidth(root));   
  return 0; 
}
