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

 class Node {
     public:
     int data;
     TreeNode* node;

     Node(TreeNode* node, int index) {
         this->data = index;
         this->node = node;
     }
 };

 // This is a functional problem. You have to complete this function.
 // It takes as input the root node of the given tree. It should print the top view of the tree.
 void printTopView(TreeNode* root) {
     if(!root)
        return ;

    queue<pair<TreeNode* , int>> q;
    q.push({root , 0});
    list<int> l;
    int countleft = 0;
    int mlsofar = 0 , mrsofar = -1 , currlevel = 0;
    while( !q.empty() )
    {
        int count = q.size();
        while(count--)
        {
            pair<TreeNode* , int> c = q.front() ;
            q.pop();
            if(c.second < mlsofar)
            {
                mlsofar = c.second;
                l.push_front((c.first)->val);
                cout<<c.first->val<<" ";
            }
            else if(c.second > mrsofar)
            {
                mrsofar = c.second;
                cout<<c.first->val<<" ";
                l.push_back((c.first)->val);
            }
            if((c.first)->left !=NULL)
            {
                q.push({(c.first)->left , c.second - 1});
            }
            if((c.first)->right !=NULL)
            {
                q.push({(c.first)->right , c.second + 1});
            }

        }

    }
    //l.sort();
//    cout<<"clf" <<countleft <<endl;
//    list<int> :: iterator it,itr ;
//    list<int> :: reverse_iterator itm ;
//    int r = 0;
//    for(it = l.begin() ; r < countleft ; it++ ,r++)
//    {
//
//    }
//    itr = it;
//    //itm = it;
//    //cout<<*it<<endl;
//    for( ; it != l.begin() ; it-- )
//    {
//        cout << *it;
//    }
//    cout<<*it;
//    itr++;
//    for( ; itr != l.end() ; itr++)
//    {
//        cout<< *itr;
//    }

 }



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
     printTopView(root);
 }
