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
  	  TreeNode* lca(TreeNode* root, int n1, int n2) {
          if(root == NULL)
          {
              return root;
          }
          if(root-> val == n1 || root->val == n2)
          {
              return root;
          }
          TreeNode * l = lca(root->left , n1 , n2);
          TreeNode * r = lca(root->right , n1 , n2);
          if(l && r)
          {
              return root;
          }
          else{
            return l != NULL ? l : r;
          }
  	  }

  	  TreeNode *lcaans = NULL;

  	  bool lca2(TreeNode* root, int n1, int n2) {
          if(root == NULL)
          {
              return false;
          }

          bool sf = false;
          if(root-> val == n1 || root->val == n2)
          {
              sf = true;
          }
          TreeNode * l = lcaans != NULL || lca(root->left , n1 , n2);
          TreeNode * r = lcaans != NULL ||lca(root->right , n1 , n2);
          if(l && r || sf && r || sf && l)
          {
              lca = (lca ==NULL ? lca = root : lca);
          }
          return sf || l || r;
  	  }
  };

  TreeNode* child;

  int main(int argc, char** argv){
      unordered_map<int, TreeNode*> map;
      int n ;
      cin>>n;
      TreeNode* root = NULL;
      for (int i = 0; i < n; i++) {
          TreeNode* parent = NULL;
          int n1, n2;
          cin>>n1>>n2;
          char c;
          cin>>c;
          if (map.find(n1) == map.end()) {
              parent = new TreeNode(n1);
              map[n1] = parent;
              if (root == NULL)
                  root = parent;
          } else
              parent = map[n1];

          child = new TreeNode(n2);
          if (c == 'L')
              parent->left = child;
          else
              parent->right = child;
          map[n2] =  child;
      }
      int firstNode, secondNode;
      cin>>firstNode>>secondNode;

      BinaryTree bt;
      TreeNode* lca = bt.lca(root, firstNode, secondNode);
      cout<<lca->val;

  }
