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

 void helper(TreeNode* node, int k , vector<TreeNode*> & psf , int& counter )
 {
     if(node == NULL)
     {
         return ;
     }
     if(node->left==NULL && node->right==NULL)
     {
         psf.push_back(node);
         if(psf.size()-1 >= k && psf[psf.size() -k-1] !=NULL)
         {
             counter++;
             psf[psf.size() -k-1] = NULL;
         }
         psf.pop_back();
         return;
     }
     psf.push_back(node);

     helper(node->left ,k ,psf,counter);
     helper(node->right ,k ,psf,counter);
    psf.pop_back();
 }

 int KDistantfromLeaf(TreeNode* node, int k) {
    vector<TreeNode* > v;
    int c =0 ;
    helper(node,k,v,c);
     return c;
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
     int k;
     cin>>k;
     TreeNode* root = stringToTreeNode(line);
     cout<<KDistantfromLeaf(root, k)<<endl;
 }
