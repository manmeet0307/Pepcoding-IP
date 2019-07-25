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

 class Result {
     public:
 	 TreeNode* pre = NULL;
     TreeNode* succ = NULL;
 };

 // This is a functional problem. You have to complete this function.
 // It takes as input the root node of the given tree, an object of class Result and a key.
 // It should set the pre and succ values of the object r for the given key, if present, else should leave them null.
 TreeNode* successor(TreeNode* node, int key)
 {
     if(node == NULL)
     {
         return node ;
     }

     TreeNode *s = NULL;
     TreeNode * n = node;
     while(1)
     {
         if( n == NULL )
            break;
         if(key < n->val)
         {
            s = n;
            n = n->left ;
         }
         else if(key > n->val)
         {
             n = n->right;
         }
         else
         {
             if(n->right != NULL)
             {
                 s = n->right;
                 while(s ->left!=NULL)
                 {
                     s = s->left;
                 }
             }
           break;
         }
     }
     return s;

 }

 TreeNode* predecessor(TreeNode* node, int key)
 {
     if(node == NULL)
     {
         return node;
     }

     TreeNode *p = NULL;
     TreeNode * n = node;
     while(1)
     {
         if( n == NULL)
            break;
         if(key < n->val)
         {
            n = n->left ;
         }
         else if(key > n->val)
         {
             p = n;
             n = n->right;
         }
         else
         {
             if(n->left != NULL)
             {
                 p = n->left;
                 while(p ->right!=NULL)
                 {
                     p = p->right;
                 }
             }
             break;
         }
     }
     return p;

 }
 void findPreSuc(TreeNode* node, Result* r, int key) {
     // write your code here.
     r->pre = predecessor(node,key);
     r->succ = successor(node,key);
 }

 //Don't change code of utility function.
 TreeNode* stringToTreeNode(string &input) {
     int first = input.find_first_not_of(' ');
     int last = input.find_last_not_of(' ');
     input = input.substr(first, (last - first + 1));
     if (!input.size()) {
         return nullptr;
     }

     string item;
     stringstream ss;
     ss.str(input);

     getline(ss, item, ' ');
     TreeNode* root = new TreeNode(stoi(item));
     queue<TreeNode*> nodeQueue;
     nodeQueue.push(root);

     while (true) {
         TreeNode* node = nodeQueue.front();
         nodeQueue.pop();
         if (!getline(ss, item, ' ')) {
             break;
         }

         if (item != "null") {
             int leftNumber = stoi(item);
             node->left = new TreeNode(leftNumber);
             nodeQueue.push(node->left);
         }

         if (!getline(ss, item, ' ')) {
             break;
         }

         if (item != "null") {
             int rightNumber = stoi(item);
             node->right = new TreeNode(rightNumber);
             nodeQueue.push(node->right);

         }
     }
     return root;
 }

 int main(int argc, char** argv){
     string line;
     getline(cin, line);
     int key;
     cin>>key;
     TreeNode* root = stringToTreeNode(line);
     Result* r = new Result();
 	 findPreSuc(root, r, key);

     if(r->pre != NULL){
         cout<<r->pre->val<<" ";
     } else{
         cout<<"-1 ";
     }

     if(r->succ != NULL){
         cout<<r->succ->val<<" ";
     } else{
         cout<<"-1 ";
     }
 }
