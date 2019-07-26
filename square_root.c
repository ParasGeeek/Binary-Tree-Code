int longestPathSum(struct Node* root,int path[],int len);
int height(Node* root);
int sumOfLongRootToLeafPath(Node* root)
{
	int path[1000];
	int l=height(root);
	return longestPathSum(root,path,0,l);
}
int longestPathSum(Node* root,int path[],int len,int l)
{
    if(!root)
    {
        return 0;
    }
    path[len++]=root->data;
    if(!root->left && !root->right)
    {
        if(len==l)
            return printSum(path,len);
    }
    longestPathSum(root->left,path,len,l);
    longestPathSum(root->right,path,len,l);
}
int height(Node* root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
        int l=height(root->left);
        int r=height(root->right);
    }
    if(l>r)
    {
        return (l+1);
    }
    else
    {
        return (r+1);
    }
}

int printSum(int path[],int len)
{
    int sum=0;
    for(i=0;i,len;i++)
    {
        sum=sum+path[i];
    }
    return sum;
}
