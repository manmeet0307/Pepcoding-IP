#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
class tNode {
    public:
	int data;
	 tNode* left;
	 tNode* right;
	tNode()
	{
	    data = 0;
	    left = NULL;
	    right = NULL;
	}
};
tNode * fun(tNode * node)
{
    tNode * lkarm = node->left;
    while(lkarm->right!=NULL && lkarm->right!=node )
    {
        lkarm = lkarm->right;
    }
    return lkarm;
}
void MorrisTraversal(tNode* root)
{
    if(root == NULL)
    {
        return ;
    }
    tNode * node = root;
    while(node != NULL)
    {

        if(node->left == NULL)
        {
        cout << node->data<<" ";
            node = node->right;
        }
        else
        {
            tNode * lkarm = fun(node);
            if(lkarm->right == NULL)
            {
                cout << node->data<<" ";
                lkarm->right = node;
                node = node->left;
            }
            else if(lkarm->right == node)
            {
                lkarm->right = NULL;
                node = node->right;
            }
        }
    }

}

 tNode* newtNode(int data)
{
	 tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{


    tNode* root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	MorrisTraversal(root);

	return 0;
}
