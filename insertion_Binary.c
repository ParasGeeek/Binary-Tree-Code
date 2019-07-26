#include<stdio.h>
#include<queue>
#include<stdlib.h>
struct node
{
	int data;
	struct Node * left,*right;
};
struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=temp->right=NULL;
	return temp;
}
void insert(struct node* root,int key)
{
	if(!root)
		return;
		
}
void inorder(struct node* root)
{
	if(!root)
		return;
	inorder(root->left)	;
	printf("%d\t",root->data);
	inorder(root->right);
}
int main()
{
	struct node* root=newNode(10);
	root->left=newNode(11);
	root->left->left=newNode(7);
	root->right=newNode(9);
	root->right->left=newNode(15);
	root->right->right=newNode(8);
	printf("Inorder traversal:\n");
	inorder(root);
	int key;
	printf("Enter the key which you want to insert:\n");
	scanf("%d",&key);
	insert(root,key);
	printf("\n");
	printf("Now Inorder traversal is :\n");
	inorder(root);
	return 0;
}


