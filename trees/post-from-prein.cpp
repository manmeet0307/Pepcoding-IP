#include<iostream>
 #include<vector>
 using namespace std;

 // This is a functional problem. You have to complete this function.
 // It takes as input the inorder array, preorder array and the length of the arrays.
 // It should print the postorder traversal.

 void construct(vector<int> preor , int prs , int pre , vector<int> in , int ins , int ine )
 {
     if(prs > pre || ins > ine)
     {
         return;
     }
     int idx = -1;
     for(int i = ins;i<=ine ; i++)
     {
         if(preor[prs] == in[i])
         {
             idx = i;
             break;
         }
     }
     int lhs = idx - ins;
     construct(preor ,prs + 1 , prs + lhs, in ,ins , idx - 1);
     construct(preor , prs + lhs + 1, pre , in , idx + 1 , ine );
     cout<<preor[prs]<<" ";
 }
 void printPostOrder(vector<int> &in, vector<int> &pre, int n) {

    construct(pre,0,pre.size()-1, in , 0 , n-1);
 }

 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> inorder(N);
     for(int i=0; i<N; i++){
         cin>>inorder[i];
     }

     vector<int> preorder(N);
     for(int i=0; i<N; i++){
         cin>>preorder[i];
     }
     printPostOrder(inorder, preorder, N);

 }
