#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 #include<deque>
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


 // This is a functional problem. You have to complete this function.
 // It takes as input the root node of the given tree. It should print the corner nodes at each level.
 void printCorner(TreeNode* root) {
     queue<TreeNode *> q;
     q.push(root);
     while(!q.empty())
     {
         int c = q.size();
         int i = 0;
         while(i<c)
         {
             TreeNode * curr = q.front() ;
             q.pop();
             if(i == 0 || i == c-1)
             {
                 cout<< curr->val<< " ";
             }
             if(curr->left)
                q.push(curr->left);
             if(curr->right)
                q.push(curr->right);

             i++;
         }
     }

 }



 int main(int argc, char** argv){

     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
     printCorner(root);
     return 0;
 }
