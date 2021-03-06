#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 #include<deque>
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
 class Pair
 {
     public:
     bool isbst;
     int min1;
     int max1;
     TreeNode * lbr;
     int lbs;
 };
 Pair helper(TreeNode* root)
 {
     if(root == NULL)
     {
         Pair p;
         p.isbst = true;
         p.min1 = INT_MAX;
         p.max1 = INT_MIN;
         p.lbr = NULL;
         p.lbs = 0;
         return p;
     }

     Pair lp = helper(root->left);
     Pair rp = helper(root->right);

     Pair ans ;
     ans.isbst = lp.isbst && rp.isbst && (lp.max1 < root->val) && (root->val < rp.min1);
    ans.min1 = min(lp.min1 , min(rp.min1,root->val));
     ans.max1 = max(lp.max1 , max(rp.max1,root->val));
     if( ans.isbst)
     {
         ans.lbr = root;
         ans.lbs = lp.lbs + rp.lbs + 1;

         //return ans;
     }
     else if(lp.lbs > rp.lbs)
     {
        ans.lbr = lp.lbr;
        ans.lbs = lp.lbs ;
     }
     else
     {
        ans.lbr = rp.lbr;
        ans.lbs = rp.lbs;
     }
     return ans;
 }
 int largestBst(TreeNode* node) {
     // write your code here.

    Pair x =  helper(node);

    return x.lbs ;
 }


 int main(int argc, char** argv){

     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
     cout<<largestBst(root)<<endl;
     return 0;
 }
