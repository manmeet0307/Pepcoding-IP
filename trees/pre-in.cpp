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
BinaryTreeNode<int>* construct(int *preorder, int pres, int pre, int *inorder, int ins , int ine)
{
    if(pres > pre || ins > ine)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[pres]);
    int idx = -1;
    for(int i = ins ; i <= ine ; i++)
    {
        if(preorder[pres] == inorder[i])
        {
            idx = i;
        }
    }
    int lhs = idx - ins;

    root->left = construct(preorder , pres + 1 , pres + lhs  , inorder , ins , idx -1);
    root->right = construct(preorder , pres + lhs + 1, pre  , inorder , idx+1,ine);
    return root;

}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
return construct(preorder , 0 , preLength-1 , inorder , 0, inLength-1);
}
