#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left,*right;
};

int height(struct node* root);
void print_level_order(struct node* root,int level);

struct node* newNode(int new_data)
{
	struct node* root=(struct node*)malloc(sizeof(struct node*));
	root->data=new_data;
	root->left=NULL;
	root->right=NULL;
	return root;
}
void level_order_traversal(struct node* root)
{
	if(!root)
		return;
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
	{
		print_level_order(root,i);
	}
	return;	
}

void print_level_order(struct node* root,int level)
{
	if(!root)
		return;
	if(level==1)
	{
		printf("%d\t",root->data);
	}
	else
	{
		print_level_order(root->left,level-1);
		print_level_order(root->right,level-1);
	}
}

int height(struct node* root)
{
	int lheight,rheight;
	if(!root)
	{
		return 0;
	}
	else
	{
		lheight=height(root->left);
		rheight=height(root->right);
		if(lheight>rheight)
		{
			return (lheight+1);
		}
		else
		{
			return (rheight+1);
		}
	}
}

void inorder(struct node* root)
{
	if(!root)
		return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);	
}
int main()
{
	struct node* root=newNode(10);
	root->left=newNode(14);
	root->right=newNode(12);
	root->left->left=newNode(13);
	root->left->right=newNode(14);
	root->right->left=newNode(20);
	root->right->right=newNode(16);
	printf("\n");
	printf("Given inorder traversal is :\n");
	inorder(root);
	printf("\n");
	printf("Level order traversal is given below:\n");
	level_order_traversal(root);
	return 0;
}

