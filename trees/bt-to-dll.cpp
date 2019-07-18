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
 	 TreeNode* head;

    pair<TreeNode*, TreeNode*> helper(TreeNode * root)
    {
        if(root == NULL)
        {
            pair< TreeNode*, TreeNode* > p({NULL,NULL}) ;

            return p;
        }
        pair<TreeNode*,TreeNode*> l = helper(root->left);
        pair<TreeNode*,TreeNode*> r = helper(root->right);
        TreeNode * n = new TreeNode(root->val);
        if(l.first != NULL && r.first != NULL)
        {
            (l.second)->right = n;
            n->left = l.second;
            n->right = r.first;
            (r.first)->left = n;
            return make_pair(l.first,r.second);
        }
        else if(l.first != NULL && r.first == NULL)
        {
            (l.second)->right = n;
            n->left = l.second;
            return make_pair(l.first,n);
        }
        else if(l.first == NULL && r.first != NULL)
        {

            n->right = r.first;
            (r.first)->left = n;
            return make_pair( n ,r.second);
        }
        else{
            return make_pair(n,n);
        }
    }
     //This is a functional problem. Write your code here.
 	 TreeNode* BT2DLL(TreeNode* root) {
 	 	 return helper(root).first;
 	 }

     // Don't make any changes here
 	 void printList(TreeNode* head) {
 	 	 TreeNode* prev = head;
 	 	 while (head != NULL) {
 	 	 	 cout<<head->val<<" ";
 	 	 	 prev = head;
 	 	 	 head = head->right;
 	 	 }

 	 	 cout<<endl;
 	 	 while (prev != NULL) {
 	 	 	 cout<<prev->val<<" ";
 	 	 	 prev = prev->left;
 	 	 }
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
 	 TreeNode* newRoot = bt.BT2DLL(root);
     bt.printList(newRoot);
 }
