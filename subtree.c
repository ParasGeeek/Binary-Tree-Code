struct TreeNode* newNode(int new_data);
void convert(node *head,TreeNode * &root)
{
  if(!head)
  {
      root=NULL;
      return;
  }
  queue<TreeNode*>q;
  root=newNode(head->data);
  q.push(root);
  head=head->next;
  while(head)
  {
      struct TreeNode* parent=q.front();
      q.pop();
      struct TreeNode* lc=NULL,rc=NULL;
      lc=newNode(head->data);
      q.push(lc);
      head=head->next;
      if(head)
      {
          rc=newNode(head->data);
          q.push(rc);
          head=head->next;
      }
      parent->left=lc;
      parent->right=rc;
  }
}

struct TreeNode* newNode(int new_data)
{
    TreeNode* temp=new TreeNode;
    temp->data=new_data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
