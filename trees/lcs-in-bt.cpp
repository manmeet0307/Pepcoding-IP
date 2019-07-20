#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
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

 class BinaryTree {
 public:
    int ms = -1;
    void fun(TreeNode* root , vector<int> &psf)
    {
        if(root == NULL)
        {
            return;
        }

        if(psf.size() == 0 ||  root->val == psf[psf.size() -1] + 1)
        {
            psf.push_back(root->val);
            fun(root->left , psf);
            fun(root->right , psf);
            int x = psf.size();
            ms = max(ms , x);
            psf.pop_back();
        }
        else
        {
            vector<int> t = psf;
            psf.clear();
            psf.push_back(root->val);
            fun(root->left , psf);
            fun(root->right , psf);
//            int x = psf.size();
//            ms = max(ms , x);
            psf = t;
        }
    }
 	 int longestConsecutive(TreeNode* root) {
 	 	 // Write your code here.
        vector<int> v;
        fun(root , v);
        return ms == 1 ? -1 : ms;
 	 }

 };

 void insert(TreeNode* root, int a1, int a2, char ch) {
     if (root == NULL)
         return;
     if (root->val == a1) {
         switch (ch) {
         case 'L':
             root->left = new TreeNode(a2);

             break;
         case 'R':
             root->right = new TreeNode(a2);
             break;
         }
     } else {
         insert(root->left, a1, a2, ch);
         insert(root->right, a1, a2, ch);
     }
 }


 int main(int argc, char** argv){
     int n ;
     cin>>n;

     TreeNode* root = NULL;
     if (n == 0) {
         cout<<endl;
     }
     for (int i = 0; i < n; i++) {
         int a1, a2;
         cin>>a1>>a2;
         char ch;
         cin>>ch;
         if (root == NULL) {
             root = new TreeNode(a1);
             switch (ch) {
             case 'L':
                 root->left = new TreeNode(a2);
                 break;
             case 'R':
                 root->right = new TreeNode(a2);
                 break;
             }
         } else {
             insert(root, a1, a2, ch);
         }
     }
     BinaryTree bt;
     cout<<bt.longestConsecutive(root)<<endl;

 }
