#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct Node
{
	int key;
	int data;
	struct node* next;
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

void vertical_order(struct node* root)
{
	int hd=0;
	if(!root)
	{
		return;
	}
	print_vertical_order(root,hd);
	return;
}

void print_vertical_order(struct node* root,int m)
{
	
}

int main()
{
	int n,i,m;
	printf("Enter the number of vertex in tree:\n");
	scanf("%d",&n);
	struct node* root=NULL;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	root->right->right->left=newNode(8);
	root->right->right->right=newNode(9);
	printf("Inorder Traversal of tree is:\n");
	inorder(root);
	printf("\n");
	printf("Vertical order of tree is:\n");
	vertical_order(root);
	return 0;	
}

