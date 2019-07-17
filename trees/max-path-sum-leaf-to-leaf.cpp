int helper(struct Node * r ,int &maxsum)
{
    if(r==NULL)
    return 0;
    int ls = helper(r->left,maxsum);
    int rs = helper(r->right,maxsum);
    maxsum = max(maxsum , ls + rs + r->data);
    return max(ls , rs) + r->data;
}
int maxPathSum(struct Node *root)
{
int maxsum = 0;
int x = helper(root,maxsum);
return maxsum;
}

