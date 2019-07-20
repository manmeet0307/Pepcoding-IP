
void kdown(node * root, int k ,node * blocker)
{
    if(root == NULL || k<0 || root == blocker)
    {
        return ;
    }
    if(k == 0)
    {
        cout<<root->data<<" ";
        return ;
    }
    kdown(root->left,k-1,blocker);
    kdown(root->right , k-1 , blocker);
}
 bool kfar(node* root, node* target , int k , int &dist)
 {
     if(root == NULL)
     {
         return 0;a
     }
     if(root == target)
     {
         kdown(root , k , NULL);
         dist++;
         return true;
     }
     else if(kfar(root->left,target,k,dist))
     {
         kdown(root , k-dist , root->left );
         dist++;
         return true;
     }
     else if(kfar(root->right,target,k,dist))
     {
         kdown(root , k-dist , root->right );
         dist++;
         return true;
     }
     else {
        return false;
     }
 }
int printkdistanceNode(node* root, node* target , int k)
{
    if(root == NULL)
    {
        return 0;
    }
    int dist = 0;
    bool f = kfar(root , target , k , dist);
     return 0;
}
