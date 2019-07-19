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

 class BinaryTree {
     public:
     void leftboundary( TreeNode * root , vector<int> &lb)
     {
         if(root == NULL)
         {
             return ;
         }
         if(root->left !=NULL && root->right !=NULL)
         {
             lb.push_back(root->val);
             leftboundary(root->left , lb);
         }
         else if(root->left !=NULL && root->right ==NULL)
         {
             lb.push_back(root->val);
             leftboundary(root->left , lb);
         }
         else if(root->left ==NULL && root->right !=NULL)
         {
             lb.push_back(root->val);
             leftboundary(root->right , lb);
         }
         else
         {
             return ;
         }
     }

     void leafnodes(TreeNode* root , vector<int> &lb)
     {
         if(root == NULL)
         {
             return ;
         }
         if(root->left == NULL && root->right == NULL)
         {
             lb.push_back(root->val);
             return;
         }
         leafnodes(root->left , lb);
         leafnodes(root->right , lb);
     }
     void rightboundary( TreeNode * root , vector<int> &lb)
     {
         if(root == NULL)
         {
             return ;
         }
         if(root->left !=NULL && root->right !=NULL)
         {

             rightboundary(root->right,lb);
             lb.push_back(root->val);
         }
         else if(root->left !=NULL && root->right ==NULL)
         {
             rightboundary(root->left , lb);
             lb.push_back(root->val);
         }
         else if(root->left ==NULL && root->right !=NULL)
         {

             rightboundary(root->right , lb);
             lb.push_back(root->val);
         }
         else
         {
             return ;
         }
     }

 	 vector<int> boundaryOfBinaryTree(TreeNode* root) {

        vector<int> lb ;
        lb.push_back(root->val);
        leftboundary(root->left , lb);
        leafnodes(root->left , lb);
        leafnodes(root->right , lb);
        rightboundary(root->right , lb);
        /*for(int i=0;i<lb.size() ;i++)
        {
            cout<<lb[i]<<" ";
        }*/
        return lb;
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
 };

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

 int main(int argc, char** argv){
     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
 	 BinaryTree bt;
 	 vector<int> res = bt.boundaryOfBinaryTree(root);
     cout<<"[";
 	 for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }
