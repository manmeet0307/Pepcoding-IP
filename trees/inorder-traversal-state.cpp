#include<bits/stdc++.h>
#include<iostream>
  #include<vector>
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

  // creation of tree from array by level order, -1 says there is no node
  TreeNode* levelOrder(vector<int> &arr) {

      vector<TreeNode*> nodes(arr.size());
      for (int i = 0; i < nodes.size(); i++) {
          if (arr[i] != -1) {
              TreeNode* t = new TreeNode(arr[i]);
              nodes[i] = t;

              if (i > 0) {
                  int pi = (i - 1) / 2;
                  if (i == 2 * pi + 1) {
                      nodes[pi]->left = nodes[i];
                  } else {
                      nodes[pi]->right = nodes[i];
                  }
              }
          }
      }
      TreeNode* root = nodes[0];
      return root;
  }

  // This is a functional problem. You have to complete this function.
  // It takes as input the root node of the given tree. It should return
  // the inorder traversal arraylist.
  void inorderTraversal(TreeNode* node) {
    stack< pair<TreeNode* , int>> st;
     st.push(make_pair(node , 0));
     while(!st.empty())
     {
         pair<TreeNode* , int > curr = st.top();
         if(curr.second == 0)
         {
            pair<TreeNode* , int > temp = st.top();
            st.pop();
            st.push(make_pair(temp.first , 1));
            if((curr.first)->left !=NULL)
            st.push(make_pair((curr.first)->left , 0));
         }
         else if(curr.second == 1)
         {
            pair<TreeNode* , int > temp = st.top();
            st.pop();
            st.push(make_pair(temp.first , 2));
            cout<< (temp.first)->val <<" ";

         }
         else if(curr.second == 2)
         {
            pair<TreeNode* , int > temp = st.top();
            st.pop();
            st.push(make_pair(temp.first , 3));
            if((curr.first)->right != NULL)
                st.push(make_pair((curr.first)->right , 0));
         }
         else if(curr.second == 3)
         {
             st.pop();
         }
     }

  }

  int main(int argc, char** argv){
      // length of array representing the tree
      int len;
      cin>>len;

      vector<int> arr(len);
      for (int i = 0; i < len; i++) {
          cin>>arr[i];
      }
      TreeNode* root = levelOrder(arr);
       inorderTraversal(root);


  }
