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

int getLevel(struct node *root, int target)
{
	if(!root)
	    return 0;
	return GetLevel(root,target,1);    
}

int GetLevel(struct node* root,int target,int level)
{
    if(!root)
    {
        return 0;
    }
    if(root->data==target)
    {
		return level;
	}
	int level2=GetLevel(root->left,target,level+1);
	if(level2!=0)
	{
		return level2;
	}
	GetLevel(root->right,target,level+1);
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

int main()
{
	struct node *root =NULL; 
    int x,key; 
    root = newNode(3); 
    root->left = newNode(2); 
    root->right = newNode(5); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    printf("Inorder Traversal of the above tree is:\n");
    inorder(root);
    printf("Enter the node of which you want to get level:\n");
    scanf("%d",&key);
    printf("%d",getLevel(root,key));
    return 0;
}

