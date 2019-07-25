#include<iostream>
 #include<vector>
 using namespace std;

 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array representing the preorder traversal of a BST.
 // It should print the postorder traversal.
 void helper(vector<int> pre , int ps, int pe)
 {
     if(ps > pe || ps <0 || pe<0 )
     {
         return ;
     }
     int nge = -1;
     int x = pre[ps];
     for(int i = ps+1 ; i<= pe ; i++)
     {
         if(pre[i] > x)
         {
             nge = i;
             break;
         }
     }
    // cout<<nge <<endl;
     helper(pre , ps+1 , nge == -1 ? pe : nge-1);
     if(nge != -1)
        helper(pre , nge , pe);
     cout << x<<" ";
 }
 void postfrompre(vector<int> &pre) {

    helper(pre,0,pre.size()-1);
 }


 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> preorder(N);
     for(int i=0; i<N; i++){
         cin>>preorder[i];
     }
     postfrompre(preorder);

 }
