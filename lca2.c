#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->data=new_data;
	return temp;
}

struct node* insert(struct node* root,int key)
{
	if(!root)
	{
		return newNode(key);
	}
	else if(key<root->data)
	{
		root->left=insert(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=insert(root->right,key);
	}
	return root;
}

struct node* LCA(struct node* root,int n1,int n2)
{
	if(!root)
	{
		return NULL;
	}
	 if(root->data <n1 && root->data<n2)
	{
		return LCA(root->left,n1,n2);
	}
	else if(root->data>n1 && root->data>n2)
	{
		return LCA(root->right,n1,n2);
	}
	return root;
}

int main()
{
	struct node* root=NULL;
	int m,n,i;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		root=insert(root,m);
	}
	int n1,n2;
	printf("Enter the value of the n1 and n2:\n");
	scanf("%d %d",&n1,&n2);
	struct node *lca=LCA(root,n1,n2);
	printf("LCA of  %d and %d is :%d",n1,n2,lca->data);
	return 0;
}
