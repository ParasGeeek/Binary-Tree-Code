#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left,*right;
};
int findPath(struct node* root,int path[],int n,int len);
struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
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
}
int lca(struct node *root,int n1,int n2)
{
	int len1,len2;
	int path1[1000],path2[1000];
	int i;
	if(!root)
	{
		return 0;
	}
	else
	{
		if(!findPath(root,path1,n1,0) || !findPath(root,path2,n2,0))
		{
			return 0;
		}
		else
		{
			len1=sizeof(path1)/sizeof(path1[0]);
			len2=sizeof(path2)/sizeof(path2[0]);
			
			if(len1>len2)
			{
				for(int i=0;i<len1;i++)
				{
					if(path1[i]!=path2[i])
					{
						return path1[i-1];
						break;
					}
				}
			}
			else
			{
				for(int i=0;i<len2;i++)
				{
					if(path1[i]!=path2[i])
					{
						return path1[i-1];
						break;
					}
				}
			}
		}
	}
}

int findPath(struct node* root,int path[],int n,int len)
{
	if(!root)
	{
		return 0;
	}
	path[len++]=root->data;
	if(root->data==n)
		return 1;
	if((root->left && findPath(root->left,path,n,len)) || (root->right && findPath(root->right,path,n,len)))
		return 1;
}

int main()
{
	int k1,k2;
	struct node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14);
    printf("Node of the tree before applyong the function:\n");
    inorder(root);
    printf("\n");
    printf("Enter the two value of which you want to get LCA:\n");
    scanf("%d %d",&k1,&k2);
    printf("LCA of two number is %d",lca(root,k1,k2));
    return 0;
} 
    
