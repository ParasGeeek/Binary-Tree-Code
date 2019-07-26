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

void printKDistantfromLeaf(struct node*root,int k)
{
	if(!root)
	{
		return;
	}
	int path[1000],visited[1000];
	printKDistantfromLeafUtil(root,path,visited,k,0);
	return;
}

void printKDistantfromLeafUtil(struct node* root,int path[],int visited[],int k,int Path_len)
{
	if(!root)
	{
		return;
	}
	path[path_len++]=root->data;
	visited[path_len++]=0;
	if(!root->left && !root->right)
	{
		if(visited[path_len]==0 && path_len-k-1>0)
		{
			printf("%d ",path[path_len-k]);
		}
	}
	printKDistantfromLeafUtil(root->left,path,visited,k,path_len);
	printKDistantfromLeafUtil(root->right,path,visited,k,path_len);
}

int main() 
{ 
    
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    int k;
    scanf("%d",&k);
    printKDistantfromLeaf(root, k); 
    return 0; 
}
