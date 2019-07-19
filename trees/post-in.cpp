// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
BinaryTreeNode<int>* helper(int *postorder, int poststart,int postend, int *inorder,
                            int instart,int inend)
{
  // base case
  if(poststart> postend || instart > inend)
  {
    return NULL;
  }
  BinaryTreeNode <int> * root= new BinaryTreeNode <int> (postorder[postend]);
  int idx;
  for(int i=instart;i<=inend;i++)
  {
    if(inorder[i]==postorder[postend])
    {
      idx=i;
        break;
    }
  }
 int lhs = idx - instart ;
 root->left=helper(postorder,poststart,poststart + lhs - 1,inorder, instart, idx - 1 );
 root->right=helper(postorder,poststart + lhs ,postend - 1,inorder,idx+1 ,inend );
  return root;

}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return helper(postorder,0,postLength-1,inorder,0,inLength-1);
}
