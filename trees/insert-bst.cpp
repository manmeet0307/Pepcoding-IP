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
 	 TreeNode* insertIntoBST(TreeNode* root, int val) {
 	 	 if(root == NULL)
         {
             TreeNode * x = new TreeNode(val);
             return x;
         }
         if(val < root->val)
         {
             root->left = insertIntoBST(root->left , val);
         }
         else
         {
            root->right = insertIntoBST(root->right , val);
         }
         return root;
 	 }

     string levelOrder(TreeNode* node) {
 	 	 if(node == NULL){
             return "[]";
         }
         string output = "";
 	 	 queue<TreeNode*> nodeQueue;
 	 	 nodeQueue.push(node);
 	 	 while (nodeQueue.size() > 0) {
 	 	 	 TreeNode* node = nodeQueue.front();
             nodeQueue.pop();

 	 	 	 if (node == NULL) {
 	 	 	 	 output += "null ";
 	 	 	 	 continue;
 	 	 	 }

 	 	 	 output += to_string(node->val) + " ";
 	 	 	 nodeQueue.push(node->left);
 	 	 	 nodeQueue.push(node->right);
 	 	 }
 	 	 return output;
 	 }

 	 // Don't make any changes here
 	 void inOrder(TreeNode* node) {
 	 	 if (node == NULL) {
 	 	 	 return;
 	 	 }

 	 	 inOrder(node->left);
 	 	 cout<<node->val<<" ";
 	 	 inOrder(node->right);
 	 }

     void printPostorder(TreeNode* node) {
 	 	 if (node == NULL)
 	 	 	 return;

 	 	 printPostorder(node->left);
 	 	 printPostorder(node->right);
 	 	 cout<<node->val<<" ";
 	 }

 	 void printPreorder(TreeNode* node) {
 	 	 if (node == NULL)
 	 	 	 return;

 	 	 cout<<node->val<<" ";
 	 	 printPostorder(node->left);
 	 	 printPostorder(node->right);
 	 }

     class BSTPair {
         public:
 	 	 int max = INT_MIN;
 	 	 int min = INT_MAX;
 	 	 bool isBst = false;
 	 };

     BSTPair isBST(TreeNode* node) {

 	 	 if (node == NULL) {
 	 	 	 BSTPair basePair;
 	 	 	 basePair.isBst = true;
 	 	 	 return basePair;
 	 	 }

 	 	 BSTPair leftPair = isBST(node->left);
 	 	 BSTPair rightPair = isBST(node->right);
 	 	 if (leftPair.isBst && rightPair.isBst) {
 	 	 	 if (node->val > leftPair.max && node->val < rightPair.min) {
 	 	 	 	 BSTPair returnPair;
 	 	 	 	 returnPair.isBst = true;
 	 	 	 	 returnPair.max = max(node->val, rightPair.max);
 	 	 	 	 returnPair.min = min(node->val, leftPair.min);
 	 	 	 	 return returnPair;
 	 	 	 } else {
 	 	 	 	 BSTPair returnPair;
 	 	 	 	 returnPair.isBst = false;
 	 	 	 	 return returnPair;
 	 	 	 }
 	 	 } else {
 	 	 	 BSTPair returnPair;
 	 	 	 returnPair.isBst = false;
 	 	 	 return returnPair;
 	 	 }

 	 }

     bool isBinarySearhTree(TreeNode* root) {

 	 	 BSTPair res = isBST(root);
 	 	 return res.isBst;

 	 }

 };

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
     string str;
     getline(cin, str);
     int x;
     cin>>x;
     TreeNode* root = stringToTreeNode(str);
     BinaryTree bt;
     bt.insertIntoBST(root, x);
     if(bt.isBinarySearhTree(root)){
         cout<<"true";
     }else{
         cout<<"false";
     }
 }
