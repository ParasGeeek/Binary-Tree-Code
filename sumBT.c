#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

//int print_sum(struct node*,int);
//int height(struct node* root);

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void print_inorder(struct node* root)
{
	if(!root)
		return;
	else
	{
		print_inorder(root->left);
		printf("%d\t",root->data);
		print_inorder(root->right);
	}	
}
/*int SumBT(struct node* root)
{
   if(!root)
   {
	   return 1;
   }
   else if(!root->left && !root->right)
   {
	   return 1;
   }
   else
   {
	   if(root->data==SumBT(root->left)+sumBT(root->right))
	   {
		   return 1;
	   }
	   else
	   {
		   return 0;
	   }
   }
}
* */

/*int sumBT(struct node* root)
{
	int h=height(root);
	if(!root)
		return 0;
	int i;
	static int sum=0;
	for(i=1;i<=h;i++)
	{
		sum=sum+print_sum(root,i);
	}
	return sum;	
}

int print_sum(struct node* root,int k)
{
	if(!root)
		return 0;
	if(k==1)
	{
		return(root->data);
	}
	else
	{
		print_sum(root->left,k-1);
		print_sum(root->right,k-1);
	}	
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
*/

/*
int sumBT(struct node* root)
{
    static int sum=0;
	if(!root)
	{
		return 0;
	}
	else
	{
		sum=sum+root->data;
		sumBT(root->left);
		//sum=sum+root->data;
		sumBT(root->right);
	}
	return sum;
}*/
/*int sumBT(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		return(root->data+sumBT(root->left)+sumBT(root->right));
	}
}*/

int sumLeaf(struct node* root)
{
	static int sum=0;
	if(!root)
	{
		return 0;
	}
	else if(!root->left && !root->right)
	{
		sum=sum+root->data;
	}
	else
	{
		sumLeaf(root->left);
		sumLeaf(root->right);
	}
	return sum;
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
	printf("Inorder Traversal of tree is:\n");
	print_inorder(root);
	printf("\n");
	int sum=sumLeaf(root);
	printf("%d\n",sum);
	return 0;	
}

