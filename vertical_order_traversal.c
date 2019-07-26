#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void inorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void verticalOrder(struct node* root)
{
	if(!root)
	{
		return;
	}
	int min=0,max=0;
	findMinMax(root,&min,&max,0);
	for(int line_no=min;line_no<=max;line_no++)
	{
		printVerticalLine(root,line_no,0);
		printf("\n");
	}
}

void findMinMax(struct node* root,int *min,int *max,int hd)
{
	if(!root)
	{
		return;
	}
	if(hd<*min)
	{
		*min=hd;
	}
	else if(hd>*max)
	{
		*max=hd;
	}
	findMinMax(root->left,min,max,hd-1);
	findMinMax(root->right,min,max,hd+1);
}

void printVerticalLine(struct node* root,int line_no,int hd)
{
	if(!root)
	{
		return;
	}
	if(line_no==hd)
	{
		printf("%d ",root->data);
	}
	printVerticalLine(root->left,line_no,hd-1);
	printVerticalLine(root->right,line_no,hd+1);
}

int main() 
{ 
   
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    printf("Inorder Traversal of the above tree is given below:\n");
    inorder(root);
    printf("\n");
    verticalOrder(root); 
  
    return 0; 
}
