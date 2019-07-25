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

 // This is a functional problem. You have to complete this function.
 // It takes as input the root node of the given tree. It should return the required sum.
 int convert(vector<int> v)
 {
     int l = 0,ans = 0;
     for(int i = v.size()-1 ; i >=0 ; i-- , l++)
     {
         ans = ans + (v[i] * pow(2,l));
     }
     return ans;
 }

 void helper(TreeNode * root , vector<int>& psf , int& sum  )
 {
     if(!root)
        return ;
    if(!root->left && !root->right)
    {
        psf.push_back(root->val);
        int x = convert(psf);
        sum += x;
        cout<<x<<endl;
        psf.pop_back();
        return;
    }

    psf.push_back(root->val);
    helper(root->left , psf,sum);
    helper(root->right , psf,sum);
    psf.pop_back();
}

 int sumRootToLeaf(TreeNode* node) {
     // write your code here.
     vector<int> r;
     int s = 0;
     helper(node , r , s);
     return s;
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
     TreeNode* root = stringToTreeNode(line);
     cout<<sumRootToLeaf(root)<<endl;
 }
