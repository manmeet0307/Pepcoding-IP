#include<iostream>
 #include<vector>
 using namespace std;

 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array. It should return true if the array can represent preorder traversal of a BST, else should return false.
 bool helper(vector<int> &pre , int minv , int maxv , int s , int e)
 {
     if(s > e)
        return true;

     if(pre[s] < minv || pre[s] > maxv)
     {
         return false;
     }
     int idx = -1;
     int x = pre[s];
     for(int i = s + 1 ; i<= e ; i++)
     {
         if(pre[i] > x)
         {
             idx = i;
             break;
         }
     }
     bool lhs = helper(pre , minv , pre[s] , s+1 , idx == -1 ? e : idx-1);
     bool rhs = true;
     if(idx != -1)
      rhs = helper(pre , pre[s] , maxv , idx , e);
     return lhs && rhs;

 }

 bool preOrder(vector<int> &pre) {
     return helper(pre,INT_MIN , INT_MAX ,0,pre.size()-1);

 }


 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> arr(N);
     for(int i=0; i<N; i++){
         cin>>arr[i];
     }
     if(preOrder(arr)){
         cout<<"Yes"<<endl;
     } else{
         cout<<"No"<<endl;
     }

 }
