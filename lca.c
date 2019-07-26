#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right,*parent;
};

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->left=temp->right=temp->parent=NULL;
	temp->data=new_data;
	return temp;
}

int depth(struct node* node)
{
	int d=-1;
	while(node)
	{
		++d;
		node=node->parent;
	}
	return d;
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
		root->left->parent=root;
	}
	else if(key>root->data)
	{
		root->right=insert(root->right,key);
		root->right->parent=root;
	}
	return root;
}

struct node *LCA(struct node* n1,struct node* n2)
{
	int diff;
	int d1=depth(n1);
	int d2=depth(n2);
	diff=d1-d2;
	if(diff<0)
	{
		struct node* temp=n1;
		n1=n2;
		n2=temp;
		diff=-diff;
	}
	while(diff--)
	{
		n1=n1->parent;
	}
	while(n1 && n2)
	{
		if(n1==n2)
		{
			return n1;
		}
		else
		{
			n1=n1->parent;
			n2=n2->parent;
		}
	}
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
	struct node* n1=root->left->right->left;
	struct node* n2=root->right;
	struct node *lca=LCA(n1,n2);
	printf("LCA of  %d and %d is :%d",n1->data,n2->data,lca->data);
	return 0;
}
