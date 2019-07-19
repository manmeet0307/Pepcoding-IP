#include<bits/stdc++.h>
using namespace std;
// A utility function to find min of two integers
int min(int x, int y) { return (x < y)? x: y; }

/* A binary tree node has data, pointer to left child and a pointer to
right child */
struct node
{
	int data;
	struct node *left, *right;
};

int helper(struct node * root, unordered_map<struct node* , int> &m)
{
    if(root == NULL)
    {
        return 0;
    }
    if(m.count(root))
    {
        return m[root];
    }

    int f1 = 1 + helper(root->left,m) + helper(root->right,m);
    int f2 = 0;
    if(root->left)
    {
        f2 += 1 + helper(root->left->left,m) + helper(root->left->right,m);
    }
    if(root->right)
    {
        f2 += 1 + helper(root->right->left,m) + helper(root->right->right,m);
    }
    m[root] = min(f1,f2);
    return min(f1,f2);
}
// The function returns size of the minimum vertex cover
int vCover(struct node *root)
{
    unordered_map<struct node* , int> m;
    return helper(root,m);
}

// A utility function to create a node
struct node* newNode( int data )
{
	struct node* temp = (struct node *) malloc( sizeof(struct node) );
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us construct the tree given in the above diagram
	struct node *root		 = newNode(20);
	root->left			 = newNode(8);
	root->left->left		 = newNode(4);
	root->left->right		 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right			 = newNode(22);
	root->right->right	 = newNode(25);

	printf ("Size of the smallest vertex cover is %d ", vCover(root));

	return 0;
}
