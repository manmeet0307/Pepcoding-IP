#include<bits/stdc++.h>
#include<iostream>
 #include<vector>
 using namespace std;

 // TreeNode class for a node of a Binary Search Tree
 class TreeNode {
     public:
 	 int val;
 	 TreeNode* left;
 	 TreeNode* right;

 	 TreeNode(int x) {
 	 	 val = x;
         left = NULL;
         right = NULL;
 	 }
 };

 // utility function to display a binary tree
 void display(TreeNode* node) {
     if (node == NULL) {
         return;
     }
     string str = "";

     str += node->left == NULL ? "." : to_string(node->left->val);
     str += " <= " + to_string(node->val) + " => ";
     str += node->right == NULL ? "." : to_string(node->right->val);

     cout<<str<<endl;

     display(node->left);
     display(node->right);
 }

 // creation of tree from array by level order, -1 says there is no node
 TreeNode* levelOrder(vector<int> &arr) {

     vector<TreeNode*> nodes(arr.size());
     for (int i = 0; i < nodes.size(); i++) {
         if (arr[i] != -1) {
             TreeNode* t = new TreeNode(arr[i]);
             nodes[i] = t;

             if (i > 0) {
                 int pi = (i - 1) / 2;
                 if (i == 2 * pi + 1) {
                     nodes[pi]->left = nodes[i];
                 } else {
                     nodes[pi]->right = nodes[i];
                 }
             }
         }
     }
     TreeNode* root = nodes[0];
     return root;
 }

 // This is a functional problem. You have to complete this function.
 // It takes as input the root of the given tree. It should return the
 // level order traversal as an arraylist of arraylist.
 vector<vector<int> > levelOrderTraversal(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> v;
    while(!q.empty())
    {
        int c = q.size();
        vector<int> c1;
        while(c--)
        {

            TreeNode * curr = q.front();
            c1.push_back(curr->val);
            q.pop();

            if(curr->left !=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right !=NULL)
            {
                q.push(curr->right);
            }
        }
        v.push_back(c1);
    }
    reverse(v.begin(),v.end());
    return v;
 }

 int main(int argc, char** argv){
     // length of array representing the tree
     int len;
     cin>>len;

     vector<int> arr(len);
     for (int i = 0; i < len; i++) {
         cin>>arr[i];
     }
     TreeNode* root = levelOrder(arr);

 	 vector<vector<int> > res = levelOrderTraversal(root);

     for(vector<int> list: res) {
         for(int i: list){
             cout<<i<<" ";
         }
         cout<<endl;
     }

 }
