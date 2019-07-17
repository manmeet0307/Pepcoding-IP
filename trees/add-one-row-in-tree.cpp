#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
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

 //Don't change code of utility function.
 TreeNode* stringToTreeNode(string input) {
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

  TreeNode* helper(TreeNode* root , int v , int d , int level)
 {
     if(root == NULL)
     {
         return NULL;
     }
     if(d == 1)
     {
         TreeNode * nn = new TreeNode(v);
         nn->left = root;
         //nn->right = root->right;
         return nn;
     }
     //postorder mei kaam karenge

     root->left = helper(root->left , v , d, level + 1);
     root->right = helper(root->right , v , d, level + 1);
     if(level == d-1)
     {
         TreeNode* left = root->left;
         TreeNode* right = root->right;
         root->left = new TreeNode(v);
         root->left->left = left;
         root->right = new TreeNode(v);
         root->right->right = right;

     }
     return root;
 }
 TreeNode* addOneRow(TreeNode* root, int v, int d) {
    return helper(root,v,d,1);
 }

 int main(int argc, char** argv){
     int v, d;
     cin>>v>>d;
     cin.ignore();
 	 string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
 	 TreeNode* res = addOneRow(root, v, d);
 	 display(res);
 }
