#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left,*right;
};

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->right=NULL;
	temp->left=NULL;
}
void postorder(struct node* root)
{
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);	
}

struct node* post_order(int *in,int *pre,int n,int m)
{
	int index;
	index=0;
	root->data=*(pre+index);
	
	
	
}
int main()
{
	int m,n;
	struct node* root=NULL;
	printf("Enter the size of first array:\n");
	scanf("%d",&n);
	printf("Enter thr sizeof second array:\n");
	scanf("%d",&m);
	int arr1[n],arr2[m];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(j=0;j<m;j++)
	{
		scanf("%d",&arr[j]);
	}
	root=post_order(arr1,arr2,n,m);
	printf("Postorder traversal is:\n");
	postorder(root);
	return 0;
}
