#include<iostream>
 #include<vector>
 using namespace std;
 class Treenode
 {
     public:
     int val;
     Treenode *left,*right;
     Treenode(int x)
     {
         val = x;
         left = NULL;
         right = NULL;
     }
 };
 Treenode* helpercreate(vector<int> &arr , int i , int j)
 {
     if(i>j)
     {
         return NULL;
     }

     int mid = (i+j)/2;
     Treenode * n = new Treenode(arr[mid]);
     n->left = helpercreate(arr,i,mid-1);
     n->right = helpercreate(arr,mid+1,j);
     cout<<n->val<<endl;
     return n;
 }
 void display(Treenode * r)
 {
     if(r==NULL)
     {
         return ;
     }
     cout<<r->val<<" ";
     display(r->left);
     display(r->right);
 }
 void BSTFormation(vector<int> &arr, int i, int j) {

   Treenode * r = helpercreate(arr,0,arr.size()-1);
   display(r);
 }

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr(n);
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
     BSTFormation(arr, 0, arr.size() - 1);
 }
