#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void print_level_order(struct node* root,int level);

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int height(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		int lheight=height(root->left);
		int rheight=height(root->right);
		if(lheight>rheight)
		{
			return (1+lheight);
		}
		else
		{
			return (1+rheight);
		}
	}
}

void spiral(struct node* root)
{
	int i;
	if(!root)
	{
		return;
	}
	else
	{
		int h=height(root);
		for(i=1;i<=h;i++)
		{
			print_level_order(root,i);
			printf("\n");
		}
	}
}

void print_level_order(struct node* root,int level)
{
	if(level==1)
	{
		printf("%d\t",root->data);
	}
	else
	{
		print_level_order(root->left,level-1);
		print_level_order(root->right,level-1);
	}
	return;
}

void preorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	int n,m,i;
	printf("Enter the number of nodes in tree:\n");
	scanf("%d",&n);
	struct node* root=NULL;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	printf("Preorder Traversal is given by:\n");
	preorder(root);
	printf("Spiral form of the tree is :\n");
	spiral(root);
	return 0;
}
	
